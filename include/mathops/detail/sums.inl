#ifndef SUMS_INL
#define SUMS_INL

#include <mathops/sums.hpp>
#include <mathops/detail/AVX/avx_sums.hpp>

namespace mathops
{
#ifdef HAS_AVX

#define SUM avx::sum

#else

#define SUM seq::sum

#endif

    inline float sum(const float *arr, size_t size)
    {
        return SUM(arr, size);
    }    
} // namespace math

#endif // SUMS_INL