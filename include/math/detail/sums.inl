#ifndef SUMS_INL

#include <math/sums.hpp>
#include <math/detail/AVX/avx_sums.hpp>

namespace math
{
#ifdef HAS_AVX

#define SUM avx::sum

#else

#define SUM seq::sum

#endif

    inline float sum(const float *arr, size_t size)
    {
        SUM(arr, size);
    }    
} // namespace math

#endif // SUMS_INL