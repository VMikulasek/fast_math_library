#ifndef SUMS_INL
#define SUMS_INL

#include <mathops/sums.hpp>
#include <mathops/detail/AVX/avx_sums.hpp>
#include <mathops/detail/SEQ/seq_sums.hpp>
#include <common/detail/memory_common.inl>

namespace mathops
{

#ifdef HAS_AVX

#define SUM avx::sum
#define PREFIX_SUM avx::prefix_sum

#else // HAS_AVX

#define SUM seq::sum
#define PREFIX_SUM seq::prefix_sum

#endif // HAS_AVX

    inline float sum(const float *arr, size_t size)
    {
        return SUM(arr, size);
    }

    inline float *prefix_sum(const float *arr, size_t size)
    {
        ALLOC_DST;

        PREFIX_SUM(arr, size, dst);

        return dst;
    }

    inline float *prefix_sum(const std::vector<float> &arr)
    {
        return prefix_sum(arr.data(), arr.size());
    }
} // namespace math

#endif // SUMS_INL