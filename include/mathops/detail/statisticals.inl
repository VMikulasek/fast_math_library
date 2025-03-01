#ifndef STATISTICALS_INL
#define STATISTICALS_INL

#include <mathops/statisticals.hpp>
#include <mathops/detail/AVX/avx_statisticals.hpp>
#include <mathops/detail/SEQ/seq_statisticals.hpp>

namespace mathops
{
#if defined(HAS_AVX)

#define MIN avx::min
#define MAX avx::max

#define ARITHMETIC_MEAN avx::arithmetic_mean
#define GEOMETRIC_MEAN avx::geometric_mean
#define WEIGHTED_MEAN avx::weighted_mean

#define VARIANCE avx::variance
#define SAMPLE_VARIANCE avx::sample_variance
#define STD_DEVIATION avx::std_deviation
#define SAMPLE_STD_DEVIATION avx::sample_std_deviation

#else // HAS_AVX

#define MIN seq::min
#define MAX seq::max

#define ARITHMETIC_MEAN seq::arithmetic_mean
#define GEOMETRIC_MEAN seq::geometric_mean
#define WEIGHTED_MEAN seq::weighted_mean

#define VARIANCE seq::variance
#define SAMPLE_VARIANCE seq::sample_variance
#define STD_DEVIATION seq::std_deviation
#define SAMPLE_STD_DEVIATION seq::sample_std_deviation

#endif // HAS_AVX

    inline float min(const float *arr, size_t size)
    {
        return MIN(arr, size);
    }
    inline float min(const std::vector<float> &arr)
    {
        return MIN(arr.data(), arr.size());
    }
    inline float max(const float *arr, size_t size)
    {
        return MAX(arr, size);
    }
    inline float max(const std::vector<float> &arr)
    {
        return MAX(arr.data(), arr.size());
    }

    inline float arithmetic_mean(const float *arr, size_t size)
    {
        return ARITHMETIC_MEAN(arr, size);
    }
    inline float arithmetic_mean(const std::vector<float> &arr)
    {
        return ARITHMETIC_MEAN(arr.data(), arr.size());
    }
    inline float geometric_mean(const float *arr, size_t size)
    {
        return GEOMETRIC_MEAN(arr, size);
    }
    inline float geometric_mean(const std::vector<float> &arr)
    {
        return GEOMETRIC_MEAN(arr.data(), arr.size());
    }
    inline float weighted_mean(const float *values, const float *weights, size_t size)
    {
        return WEIGHTED_MEAN(values, weights, size);
    }
    inline float weighted_mean(const std::vector<float> &values, const std::vector<float> &weights)
    {
        return WEIGHTED_MEAN(values.data(), weights.data(), values.size());
    }

    inline int mode(const int *arr, size_t size)
    {
        return seq::mode(arr, size);
    }
    inline int mode(const std::vector<int> &arr)
    {
        return seq::mode(arr.data(), arr.size());
    }
    inline float median(const float *arr, size_t size)
    {
        return seq::median(arr, size);
    }
    inline float median(const std::vector<float> &arr)
    {
        return seq::median(arr.data(), arr.size());
    }
    inline float median(const int *arr, size_t size)
    {
        return seq::median(arr, size);
    }
    inline float median(const std::vector<int> &arr)
    {
        return seq::median(arr.data(), arr.size());
    }

    inline float variance(const float *arr, size_t size)
    {
        return VARIANCE(arr, size);
    }
    inline float variance(const std::vector<float> &arr)
    {
        return VARIANCE(arr.data(), arr.size());
    }
    inline float variance(const float *values, const float *probabilities, size_t size)
    {
        return VARIANCE(values, probabilities, size);
    }
    inline float variance(const std::vector<float> &values, const std::vector<float> &probabilities)
    {
        return VARIANCE(values.data(), probabilities.data(), values.size());
    }
    inline float sample_variance(const float *arr, size_t size)
    {
        return SAMPLE_VARIANCE(arr, size);
    }
    inline float sample_variance(const std::vector<float> &arr)
    {
        return SAMPLE_VARIANCE(arr.data(), arr.size());
    }
    inline float std_deviation(const float *arr, size_t size)
    {
        return STD_DEVIATION(arr, size);
    }
    inline float std_deviation(const std::vector<float> &arr)
    {
        return STD_DEVIATION(arr.data(), arr.size());
    }
    inline float std_deviation(const float *values, const float *probabilities, size_t size)
    {
        return STD_DEVIATION(values, probabilities, size);
    }
    inline float std_deviation(const std::vector<float> &values, const std::vector<float> &probabilities)
    {
        return STD_DEVIATION(values.data(), probabilities.data(), values.size());
    }
    inline float sample_std_deviation(const float *arr, size_t size)
    {
        return SAMPLE_STD_DEVIATION(arr, size);
    }
    inline float sample_std_deviation(const std::vector<float> &arr)
    {
        return SAMPLE_STD_DEVIATION(arr.data(), arr.size());
    }
} // namespace mathops

#endif // STATISTICALS_INL