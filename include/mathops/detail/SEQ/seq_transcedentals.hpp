#ifndef SEQ_TRANSCEDENTALS_HPP
#define SEQ_TRANSCEDENTALS_HPP

#include <cstddef>

namespace mathops
{
namespace seq
{
    void fast_sqrt_arr(const float *arr, size_t size, float *dst);
    void fast_invsqrt_arr(const float *arr, size_t size, float *dst);
} // namespace seq
} // namespace mathops

#include <mathops/detail/SEQ/seq_transcedentals.inl>

#endif // SEQ_TRANSCEDENTALS_HPP