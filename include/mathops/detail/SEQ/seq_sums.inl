#ifndef SEQ_SUMS_INL
#define SEQ_SUMS_INL

#include <mathops/detail/SEQ/seq_sums.hpp>

#include <cstddef>
#include <numeric>

namespace mathops
{
namespace seq
{
    inline float sum(const float *arr, size_t size)
    {
        return std::accumulate(arr, arr + size, 0.0f);
    }
} // namespace seq
} // namespace math

#endif // SEQ_SUMS_INL