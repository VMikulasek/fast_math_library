#ifndef AVX_STATISTICALS_INL
#define AVX_STATISTICALS_INL

#include <mathops/detail/AVX/avx_statisticals.hpp>
#include <mathops/detail/AVX/avx_sums.hpp>
#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>

#include <cstddef>
#include <limits>
#include <algorithm>
#include <cmath>

namespace mathops
{
namespace avx
{

#ifdef HAS_AVX

    using FloatOps = simd::SIMDOperations<float, simd::InstructionSet::AVX>;

    inline float min(const float *arr, size_t size)
    {
        FloatOps::AvxReg minReg = FloatOps::set_register(std::numeric_limits<float>::max());

        for ( ; size >= AVX_FLOAT_VECTOR_SIZE; size -= 8, arr += 8)
        {
            minReg = FloatOps::min(minReg, FloatOps::load_vector(arr));
        }

        alignas(AVX_ALIGNMENT) float minVec[AVX_FLOAT_VECTOR_SIZE];
        FloatOps::materialize_register(minReg, minVec);
        
        float min = minVec[0];
        for (unsigned i = 1; i < AVX_FLOAT_VECTOR_SIZE; i++)
        {
            min = std::min(min, minVec[i]);
        }

        for ( ; size > 0; size--, arr++)
        {
            min = std::min(min, *arr);
        }

        return min;
    }

    inline float max(const float *arr, size_t size)
    {
        FloatOps::AvxReg maxReg = FloatOps::set_register(std::numeric_limits<float>::min());

        for ( ; size >= AVX_FLOAT_VECTOR_SIZE; size -= AVX_FLOAT_VECTOR_SIZE, arr += AVX_FLOAT_VECTOR_SIZE)
        {
            maxReg = FloatOps::max(maxReg, FloatOps::load_vector(arr));
        }

        alignas(AVX_ALIGNMENT) float maxVec[AVX_FLOAT_VECTOR_SIZE];
        FloatOps::materialize_register(maxReg, maxVec);
        
        float max = maxVec[0];
        for (unsigned i = 1; i < AVX_FLOAT_VECTOR_SIZE; i++)
        {
            max = std::max(max, maxVec[i]);
        }

        for ( ; size > 0; size--, arr++)
        {
            max = std::max(max, *arr);
        }

        return max;
    }

    inline float arithmetic_mean(const float *arr, size_t size)
    {
        if (size == 0) return 0.f;

        return mathops::avx::sum(arr, size) / size;
    }

    inline float geometric_mean(const float *arr, size_t size)
    {
        if (size == 0) return 0.f;

        float elementsToProcess = size;
        FloatOps::AvxReg productReg = FloatOps::set_register(1.f);

        for ( ; elementsToProcess >= AVX_FLOAT_VECTOR_SIZE;
                elementsToProcess -= AVX_FLOAT_VECTOR_SIZE,
                arr += AVX_FLOAT_VECTOR_SIZE)
        {
            productReg = FloatOps::mul(productReg, FloatOps::load_vector(arr));
        }

        alignas(AVX_ALIGNMENT) float productVec[AVX_FLOAT_VECTOR_SIZE];
        FloatOps::materialize_register(productReg, productVec);

        float product = productVec[0];
        for (unsigned i = 1; i < AVX_FLOAT_VECTOR_SIZE; i++)
        {
            product *= productVec[i];
        }
        
        for ( ; elementsToProcess > 0; elementsToProcess--, arr++)
        {
            product *= *arr;
        }

        return std::pow(product, 1.f / size);
    }

    inline float weighted_mean(const float *values, const float *weights, size_t size)
    {
        FloatOps::AvxReg sumReg = FloatOps::set_register_zero();
        FloatOps::AvxReg weightSumReg = FloatOps::set_register_zero();

        for ( ; size >= AVX_FLOAT_VECTOR_SIZE;
            size -= AVX_FLOAT_VECTOR_SIZE,
            values += AVX_FLOAT_VECTOR_SIZE,
            weights += AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg weightReg = FloatOps::load_vector(weights);
            FloatOps::AvxReg valueReg = FloatOps::load_vector(values);
            weightSumReg = FloatOps::add(weightSumReg, weightReg);
            sumReg = FloatOps::add(sumReg, FloatOps::mul(weightReg, valueReg));
        }

        sumReg = FloatOps::horizontal_add(sumReg, sumReg);
        sumReg = FloatOps::horizontal_add(sumReg, sumReg);
        weightSumReg = FloatOps::horizontal_add(weightSumReg, weightSumReg);
        weightSumReg = FloatOps::horizontal_add(weightSumReg, weightSumReg);

        float sum = FloatOps::materialize_register_at_index(sumReg, 0)
            + FloatOps::materialize_register_at_index(sumReg, 4);
        float weightSum = FloatOps::materialize_register_at_index(weightSumReg, 0)
            + FloatOps::materialize_register_at_index(weightSumReg, 4);

        for ( ; size > 0; size--, values++, weights++)
        {
            sum += (*values) * (*weights);
            weightSum += *weights;
        }

        if (weightSum == 0) return 0.f;

        return sum / weightSum;
    }

    inline float variance(const float *arr, size_t size)
    {
        if (size == 0) return 0.f;

        float elementsToProcess = size;

        FloatOps::AvxReg varianceReg = FloatOps::set_register_zero();
        FloatOps::AvxReg meanReg = FloatOps::set_register_zero();
        for ( ; elementsToProcess >= AVX_FLOAT_VECTOR_SIZE;
                elementsToProcess -= AVX_FLOAT_VECTOR_SIZE,
                arr += AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg x = FloatOps::load_vector(arr);
            meanReg = FloatOps::add(meanReg, x);

            FloatOps::AvxReg x2 = FloatOps::mul(x, x);
            varianceReg = FloatOps::add(varianceReg, x2);
        }

        varianceReg = FloatOps::horizontal_add(varianceReg, varianceReg);
        varianceReg = FloatOps::horizontal_add(varianceReg, varianceReg);
        meanReg = FloatOps::horizontal_add(meanReg, meanReg);
        meanReg = FloatOps::horizontal_add(meanReg, meanReg);

        float variance = FloatOps::materialize_register_at_index(varianceReg, 0)
            + FloatOps::materialize_register_at_index(varianceReg, 4);
        float mean = FloatOps::materialize_register_at_index(meanReg, 0)
            + FloatOps::materialize_register_at_index(meanReg, 4);

        for ( ; elementsToProcess > 0; elementsToProcess--, arr++)
        {
            mean += *arr;
            variance += std::pow((*arr), 2);
        }

        return (variance / size) - std::pow(mean / size, 2);
    }

    inline float variance(const float *arr, const float *probabilities, size_t size)
    {
        if (size == 0) return 0.f;

        float elementsToProcess = size;

        FloatOps::AvxReg meanReg = FloatOps::set_register_zero();
        FloatOps::AvxReg varianceReg = FloatOps::set_register_zero();
        for ( ; elementsToProcess >= AVX_FLOAT_VECTOR_SIZE;
            elementsToProcess -= AVX_FLOAT_VECTOR_SIZE,
            arr += AVX_FLOAT_VECTOR_SIZE,
            probabilities += AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg x = FloatOps::load_vector(arr);
            FloatOps::AvxReg x2 = FloatOps::mul(x, x);

            FloatOps::AvxReg p = FloatOps::load_vector(probabilities);
            FloatOps::AvxReg xp = FloatOps::mul(x, p);
            meanReg = FloatOps::add(meanReg, xp);

            FloatOps::AvxReg x2p = FloatOps::mul(x2, p);
            varianceReg = FloatOps::add(varianceReg, x2p);
        }

        varianceReg = FloatOps::horizontal_add(varianceReg, varianceReg);
        varianceReg = FloatOps::horizontal_add(varianceReg, varianceReg);
        meanReg = FloatOps::horizontal_add(meanReg, meanReg);
        meanReg = FloatOps::horizontal_add(meanReg, meanReg);

        float variance = FloatOps::materialize_register_at_index(varianceReg, 0)
            + FloatOps::materialize_register_at_index(varianceReg, 4);
        float mean = FloatOps::materialize_register_at_index(meanReg, 0)
            + FloatOps::materialize_register_at_index(meanReg, 4);

        for ( ; elementsToProcess > 0;
                elementsToProcess--, arr++, probabilities++)
        {
            mean += (*arr) * (*probabilities);
            variance += std::pow((*arr), 2) * (*probabilities);
        }

        return variance - std::pow(mean, 2);
    }

    inline float sample_variance(const float *arr, size_t size)
    {
        if (size <= 1) return 0.f;

        float elementsToProcess = size;

        FloatOps::AvxReg meanReg = FloatOps::set_register_zero();
        FloatOps::AvxReg varianceReg = FloatOps::set_register_zero();
        for ( ; elementsToProcess >= AVX_FLOAT_VECTOR_SIZE;
                elementsToProcess -= AVX_FLOAT_VECTOR_SIZE,
                arr += AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg x = FloatOps::load_vector(arr);
            meanReg = FloatOps::add(meanReg, x);

            FloatOps::AvxReg x2 = FloatOps::mul(x, x);
            varianceReg = FloatOps::add(varianceReg, x2);
        }

        varianceReg = FloatOps::horizontal_add(varianceReg, varianceReg);
        varianceReg = FloatOps::horizontal_add(varianceReg, varianceReg);
        meanReg = FloatOps::horizontal_add(meanReg, meanReg);
        meanReg = FloatOps::horizontal_add(meanReg, meanReg);

        float variance = FloatOps::materialize_register_at_index(varianceReg, 0)
            + FloatOps::materialize_register_at_index(varianceReg, 4);
        float mean = FloatOps::materialize_register_at_index(meanReg, 0)
            + FloatOps::materialize_register_at_index(meanReg, 4);

        for ( ; elementsToProcess > 0; elementsToProcess--, arr++)
        {
            mean += *arr;
            variance += std::pow((*arr), 2);
        }

        return (variance - (std::pow(mean / size, 2) * size)) / (size - 1);
    }

    inline float std_deviation(const float *arr, size_t size)
    {
        return std::sqrt(variance(arr, size));
    }

    float std_deviation(const float *arr, const float *probabilities, size_t size)
    {
        return std::sqrt(variance(arr, probabilities, size));
    }

    inline float sample_std_deviation(const float *arr, size_t size)
    {
        return std::sqrt(sample_variance(arr, size));
    }

#endif // HAS_AVX

} // namespace avx
} // namespace mathops

#endif // AVX_STATISTICALS_INL