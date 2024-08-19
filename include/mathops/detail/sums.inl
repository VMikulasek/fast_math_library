#ifndef SUMS_INL
#define SUMS_INL

#include <mathops/sums.hpp>
#include <mathops/detail/AVX/avx_sums.hpp>

namespace mathops
{
#ifdef HAS_AVX

#define SUM avx::sum
#define PREFIX_SUM avx::prefix_sum

#else

#define SUM seq::sum
#define PREFIX_SUM seq::prefix_sum

#endif

    inline float sum(const float *arr, size_t size)
    {
        return SUM(arr, size);
    }

    inline void prefix_sum(const float *arr, size_t size, float *dstArr)
    {
        PREFIX_SUM(arr, size, dstArr);
    }
} // namespace math

#endif // SUMS_INL