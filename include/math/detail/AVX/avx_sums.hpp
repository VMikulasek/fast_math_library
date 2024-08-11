#ifndef AVX_SUMS_HPP

#include <cstddef>

namespace math
{
namespace avx
{
    float sum(const float *arr, size_t size);
} // namespace avx
} // namespace math

#include <math/detail/AVX/avx_sums.inl>

#endif // AVX_SUMS_HPP