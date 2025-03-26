#ifndef STATISTICALS_INL
#define STATISTICALS_INL

#include <mathops/statisticals.hpp>
#include <mathops/detail/VEC/vec_statisticals.hpp>
#include <mathops/detail/SEQ/seq_statisticals.hpp>

#include <type_traits>

namespace mathops
{
    template<typename T>
    inline T min(const T *arr, size_t size)
    {
        static_assert(std::is_arithmetic_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::min<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::min(arr, size);
        }
    }
    template<typename T>
    inline T min(const std::vector<T> &arr)
    {
        return min(arr.data(), arr.size());
    }
    template<typename T>
    inline T max(const T *arr, size_t size)
    {
        static_assert(std::is_arithmetic_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::max<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::max(arr, size);
        }   
    }
    template<typename T>
    inline T max(const std::vector<T> &arr)
    {
        return max(arr.data(), arr.size());
    }

    template<typename T>
    inline T arithmetic_mean(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::arithmetic_mean<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::arithmetic_mean(arr, size);
        }
    }
    template<typename T>
    inline T arithmetic_mean(const std::vector<T> &arr)
    {
        return arithmetic_mean(arr.data(), arr.size());
    }
    template<typename T>
    inline T geometric_mean(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::geometric_mean<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::geometric_mean(arr, size);
        }
    }
    template<typename T>
    inline T geometric_mean(const std::vector<T> &arr)
    {
        return geometric_mean(arr.data(), arr.size());
    }
    template<typename T>
    inline T weighted_mean(const T *values, const T *weights, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::weighted_mean<T, simd::InstructionSet::AVX>(values, weights, size);
        }
        else
        {
            return seq::weighted_mean(values, weights, size);
        }
    }
    template<typename T>
    inline T weighted_mean(const std::vector<T> &values, const std::vector<T> &weights)
    {
        return weighted_mean(values.data(), weights.data(), values.size());
    }

    template<typename T>
    inline T mode(const T *arr, size_t size)
    {
        static_assert(std::is_integral_v<T>);

        return seq::mode(arr, size);
    }
    template<typename T>
    inline T mode(const std::vector<T> &arr)
    {
        return seq::mode(arr.data(), arr.size());
    }
    template<typename T>
    inline T median(const T *arr, size_t size)
    {
        static_assert(std::is_arithmetic_v<T>);

        return seq::median(arr, size);
    }
    template<typename T>
    inline T median(const std::vector<T> &arr)
    {
        return seq::median(arr.data(), arr.size());
    }

    template<typename T>
    inline T variance(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::variance<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::variance(arr, size);
        }
    }
    template<typename T>
    inline T variance(const std::vector<T> &arr)
    {
        return variance(arr.data(), arr.size());
    }
    template<typename T>
    inline T variance(const T *values, const T *probabilities, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::variance<T, simd::InstructionSet::AVX>(values, probabilities, size);
        }
        else
        {
            return seq::variance(values, probabilities, size);
        }
    }
    template<typename T>
    inline T variance(const std::vector<T> &values, const std::vector<T> &probabilities)
    {
        return variance(values.data(), probabilities.data(), values.size());
    }
    template<typename T>
    inline T sample_variance(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::sample_variance<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::sample_variance(arr, size);
        }
    }
    template<typename T>
    inline T sample_variance(const std::vector<T> &arr)
    {
        return sample_variance(arr.data(), arr.size());
    }
    template<typename T>
    inline T std_deviation(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::std_deviation<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::std_deviation(arr, size);
        }
    }
    template<typename T>
    inline T std_deviation(const std::vector<T> &arr)
    {
        return std_deviation(arr.data(), arr.size());
    }
    template<typename T>
    inline T std_deviation(const T *values, const T *probabilities, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::std_deviation<T, simd::InstructionSet::AVX>(values, probabilities, size);
        }
        else
        {
            return seq::std_deviation(values, probabilities, size);
        }
    }
    template<typename T>
    inline T std_deviation(const std::vector<T> &values, const std::vector<T> &probabilities)
    {
        return std_deviation(values.data(), probabilities.data(), values.size());
    }
    template<typename T>
    inline T sample_std_deviation(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::sample_std_deviation<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::sample_std_deviation(arr, size);
        }
    }
    template<typename T>
    inline T sample_std_deviation(const std::vector<T> &arr)
    {
        return sample_std_deviation(arr.data(), arr.size());
    }
} // namespace mathops

#endif // STATISTICALS_INL