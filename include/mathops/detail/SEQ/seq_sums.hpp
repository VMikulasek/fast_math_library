#ifndef SEQ_SUMS_HPP
#define SEQ_SUMS_HPP

#include <cstddef>

namespace mathops
{
namespace seq
{
    template<typename T>
    T sum(const T *arr, size_t size);

    template<typename T>
    void prefix_sum(const T *arr, size_t size, T *dstArr);
} // namespace seq
} // namespace math

#include <mathops/detail/SEQ/seq_sums.inl>

#endif // SEQ_SUMS_HPP