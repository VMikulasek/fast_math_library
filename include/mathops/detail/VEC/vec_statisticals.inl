#ifndef VEC_STATISTICALS_INL
#define VEC_STATISTICALS_INL

#include <mathops/detail/VEC/vec_statisticals.hpp>
#include <mathops/detail/VEC/avx_sums.hpp>
#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>

#include <cstddef>
#include <limits>
#include <algorithm>
#include <cmath>

namespace mathops
{
namespace vec
{
    template<typename T, simd::InstructionSet S>
    inline T min(const T *arr, size_t size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        typename Ops::Reg minReg = Ops::set_register(std::numeric_limits<T>::max());

        for ( ; size >= Ops::REG_SIZE; size -= 8, arr += 8)
        {
            minReg = Ops::min(minReg, Ops::load_vector(arr));
        }

        alignas(Ops::ALIGNMENT) T minVec[Ops::REG_SIZE];
        Ops::materialize_register(minReg, minVec);
        
        T min = minVec[0];
        for (unsigned i = 1; i < Ops::REG_SIZE; i++)
        {
            min = std::min(min, minVec[i]);
        }

        for ( ; size > 0; size--, arr++)
        {
            min = std::min(min, *arr);
        }

        return min;
    }

    template<typename T, simd::InstructionSet S>
    inline T max(const T *arr, size_t size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        typename Ops::Reg maxReg = Ops::set_register(std::numeric_limits<T>::min());

        for ( ; size >= Ops::REG_SIZE; size -= Ops::REG_SIZE, arr += Ops::REG_SIZE)
        {
            maxReg = Ops::max(maxReg, Ops::load_vector(arr));
        }

        alignas(Ops::ALIGNMENT) T maxVec[Ops::REG_SIZE];
        Ops::materialize_register(maxReg, maxVec);
        
        T max = maxVec[0];
        for (unsigned i = 1; i < Ops::REG_SIZE; i++)
        {
            max = std::max(max, maxVec[i]);
        }

        for ( ; size > 0; size--, arr++)
        {
            max = std::max(max, *arr);
        }

        return max;
    }

    template<typename T, simd::InstructionSet S>
    inline T arithmetic_mean(const T *arr, size_t size)
    {
        if (size == 0) return 0.f;

        return mathops::avx::sum(arr, size) / size;
    }

    template<typename T, simd::InstructionSet S>
    inline T geometric_mean(const T *arr, size_t size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        if (size == 0) return 0.f;

        T elementsToProcess = size;
        typename Ops::Reg productReg = Ops::set_register(1.f);

        for ( ; elementsToProcess >= Ops::REG_SIZE;
                elementsToProcess -= Ops::REG_SIZE,
                arr += Ops::REG_SIZE)
        {
            productReg = Ops::mul(productReg, Ops::load_vector(arr));
        }

        alignas(Ops::ALIGNMENT) T productVec[Ops::REG_SIZE];
        Ops::materialize_register(productReg, productVec);

        T product = productVec[0];
        for (unsigned i = 1; i < Ops::REG_SIZE; i++)
        {
            product *= productVec[i];
        }
        
        for ( ; elementsToProcess > 0; elementsToProcess--, arr++)
        {
            product *= *arr;
        }

        return std::pow(product, 1.f / size);
    }

    template<typename T, simd::InstructionSet S>
    inline T weighted_mean(const T *values, const T *weights, size_t size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        typename Ops::Reg sumReg = Ops::set_register_zero();
        typename Ops::Reg weightSumReg = Ops::set_register_zero();

        for ( ; size >= Ops::REG_SIZE;
            size -= Ops::REG_SIZE,
            values += Ops::REG_SIZE,
            weights += Ops::REG_SIZE)
        {
            typename Ops::Reg weightReg = Ops::load_vector(weights);
            typename Ops::Reg valueReg = Ops::load_vector(values);
            weightSumReg = Ops::add(weightSumReg, weightReg);
            sumReg = Ops::add(sumReg, Ops::mul(weightReg, valueReg));
        }

        sumReg = Ops::horizontal_add(sumReg, sumReg);
        sumReg = Ops::horizontal_add(sumReg, sumReg);
        weightSumReg = Ops::horizontal_add(weightSumReg, weightSumReg);
        weightSumReg = Ops::horizontal_add(weightSumReg, weightSumReg);

        T sum = Ops::materialize_register_at_index(sumReg, 0)
            + Ops::materialize_register_at_index(sumReg, 4);
        T weightSum = Ops::materialize_register_at_index(weightSumReg, 0)
            + Ops::materialize_register_at_index(weightSumReg, 4);

        for ( ; size > 0; size--, values++, weights++)
        {
            sum += (*values) * (*weights);
            weightSum += *weights;
        }

        if (weightSum == 0) return 0.f;

        return sum / weightSum;
    }

    template<typename T, simd::InstructionSet S>
    inline T variance(const T *arr, size_t size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        if (size == 0) return 0.f;

        T elementsToProcess = size;

        typename Ops::Reg varianceReg = Ops::set_register_zero();
        typename Ops::Reg meanReg = Ops::set_register_zero();
        for ( ; elementsToProcess >= Ops::REG_SIZE;
                elementsToProcess -= Ops::REG_SIZE,
                arr += Ops::REG_SIZE)
        {
            typename Ops::Reg x = Ops::load_vector(arr);
            meanReg = Ops::add(meanReg, x);

            typename Ops::Reg x2 = Ops::mul(x, x);
            varianceReg = Ops::add(varianceReg, x2);
        }

        varianceReg = Ops::horizontal_add(varianceReg, varianceReg);
        varianceReg = Ops::horizontal_add(varianceReg, varianceReg);
        meanReg = Ops::horizontal_add(meanReg, meanReg);
        meanReg = Ops::horizontal_add(meanReg, meanReg);

        T variance = Ops::materialize_register_at_index(varianceReg, 0)
            + Ops::materialize_register_at_index(varianceReg, 4);
        T mean = Ops::materialize_register_at_index(meanReg, 0)
            + Ops::materialize_register_at_index(meanReg, 4);

        for ( ; elementsToProcess > 0; elementsToProcess--, arr++)
        {
            mean += *arr;
            variance += std::pow((*arr), 2);
        }

        return (variance / size) - std::pow(mean / size, 2);
    }

    template<typename T, simd::InstructionSet S>
    inline T variance(const T *arr, const T *probabilities, size_t size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        if (size == 0) return 0.f;

        T elementsToProcess = size;

        typename Ops::Reg meanReg = Ops::set_register_zero();
        typename Ops::Reg varianceReg = Ops::set_register_zero();
        for ( ; elementsToProcess >= Ops::REG_SIZE;
            elementsToProcess -= Ops::REG_SIZE,
            arr += Ops::REG_SIZE,
            probabilities += Ops::REG_SIZE)
        {
            typename Ops::Reg x = Ops::load_vector(arr);
            typename Ops::Reg x2 = Ops::mul(x, x);

            typename Ops::Reg p = Ops::load_vector(probabilities);
            typename Ops::Reg xp = Ops::mul(x, p);
            meanReg = Ops::add(meanReg, xp);

            typename Ops::Reg x2p = Ops::mul(x2, p);
            varianceReg = Ops::add(varianceReg, x2p);
        }

        varianceReg = Ops::horizontal_add(varianceReg, varianceReg);
        varianceReg = Ops::horizontal_add(varianceReg, varianceReg);
        meanReg = Ops::horizontal_add(meanReg, meanReg);
        meanReg = Ops::horizontal_add(meanReg, meanReg);

        T variance = Ops::materialize_register_at_index(varianceReg, 0)
            + Ops::materialize_register_at_index(varianceReg, 4);
        T mean = Ops::materialize_register_at_index(meanReg, 0)
            + Ops::materialize_register_at_index(meanReg, 4);

        for ( ; elementsToProcess > 0;
                elementsToProcess--, arr++, probabilities++)
        {
            mean += (*arr) * (*probabilities);
            variance += std::pow((*arr), 2) * (*probabilities);
        }

        return variance - std::pow(mean, 2);
    }

    template<typename T, simd::InstructionSet S>
    inline T sample_variance(const T *arr, size_t size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        if (size <= 1) return 0.f;

        T elementsToProcess = size;

        typename Ops::Reg meanReg = Ops::set_register_zero();
        typename Ops::Reg varianceReg = Ops::set_register_zero();
        for ( ; elementsToProcess >= Ops::REG_SIZE;
                elementsToProcess -= Ops::REG_SIZE,
                arr += Ops::REG_SIZE)
        {
            typename Ops::Reg x = Ops::load_vector(arr);
            meanReg = Ops::add(meanReg, x);

            typename Ops::Reg x2 = Ops::mul(x, x);
            varianceReg = Ops::add(varianceReg, x2);
        }

        varianceReg = Ops::horizontal_add(varianceReg, varianceReg);
        varianceReg = Ops::horizontal_add(varianceReg, varianceReg);
        meanReg = Ops::horizontal_add(meanReg, meanReg);
        meanReg = Ops::horizontal_add(meanReg, meanReg);

        T variance = Ops::materialize_register_at_index(varianceReg, 0)
            + Ops::materialize_register_at_index(varianceReg, 4);
        T mean = Ops::materialize_register_at_index(meanReg, 0)
            + Ops::materialize_register_at_index(meanReg, 4);

        for ( ; elementsToProcess > 0; elementsToProcess--, arr++)
        {
            mean += *arr;
            variance += std::pow((*arr), 2);
        }

        return (variance - (std::pow(mean / size, 2) * size)) / (size - 1);
    }

    template<typename T, simd::InstructionSet S>
    inline T std_deviation(const T *arr, size_t size)
    {
        return std::sqrt(variance<T, S>(arr, size));
    }

    template<typename T, simd::InstructionSet S>
    T std_deviation(const T *arr, const T *probabilities, size_t size)
    {
        return std::sqrt(variance<T, S>(arr, probabilities, size));
    }

    template<typename T, simd::InstructionSet S>
    inline T sample_std_deviation(const T *arr, size_t size)
    {
        return std::sqrt(sample_variance<T, S>(arr, size));
    }
} // namespace vec
} // namespace mathops

#endif // VEC_STATISTICALS_INL