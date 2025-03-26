#ifndef SEQ_SUMS_INL
#define SEQ_SUMS_INL

#include <mathops/detail/SEQ/seq_sums.hpp>

#include <cstddef>
#include <numeric>

namespace mathops
{
namespace seq
{
    template<typename T>
    inline T sum(const T *arr, size_t size)
    {
        return std::accumulate(arr, arr + size, 0.0f);
    }

    template<typename T>
    inline void prefix_sum(const T *arr, size_t size, T *dstArr)
    {
        std::inclusive_scan(arr, arr + size, dstArr);
    }
} // namespace seq
} // namespace math

#endif // SEQ_SUMS_INL