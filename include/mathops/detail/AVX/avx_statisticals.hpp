#ifndef AVX_STATISTICALS_HPP
#define AVX_STATISTICALS_HPP

#include <cstddef>

namespace mathops
{
namespace avx
{
    float min(const float *arr, size_t size);
    float max(const float *arr, size_t size);

    float arithmetic_mean(const float *arr, size_t size);
    float geometric_mean(const float *arr, size_t size);
    float weighted_mean(const float *values, const float *weights, size_t size);

    float variance(const float *arr, size_t size);
    float variance(const float *arr, const float *probabilities, size_t size);
    float sample_variance(const float *arr, size_t size);
    float std_deviation(const float *arr, size_t size);
    float std_deviation(const float *arr, const float *probabilities, size_t size);
    float sample_std_deviation(const float *arr, size_t size);
} // namespace avx
} // namespace mathops

#include <mathops/detail/AVX/avx_statisticals.inl>

#endif // AVX_STATISTICALS_HPP