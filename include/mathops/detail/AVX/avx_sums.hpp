#ifndef AVX_SUMS_HPP
#define AVX_SUMS_HPP

#include <cstddef>

namespace mathops
{
namespace avx
{
    float sum(const float *arr, size_t size);

    void prefix_sum(const float *arr, size_t size, float *dstArr);
} // namespace avx
} // namespace math

#include <mathops/detail/AVX/avx_sums.inl>

#endif // AVX_SUMS_HPP