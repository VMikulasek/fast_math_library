#ifndef SEQ_SUMS_HPP
#define SEQ_SUMS_HPP

#include <cstddef>

namespace mathops
{
namespace seq
{
    float sum(const float *arr, size_t size);

    void prefix_sum(const float *arr, size_t size, float *dstArr);
} // namespace seq
} // namespace math

#include <mathops/detail/SEQ/seq_sums.inl>

#endif // SEQ_SUMS_HPP