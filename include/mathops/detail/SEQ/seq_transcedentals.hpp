#ifndef SEQ_TRANSCEDENTALS_HPP
#define SEQ_TRANSCEDENTALS_HPP

#include <cstddef>

namespace mathops
{
namespace seq
{
    void fast_sqrt_arr(float *arr, size_t size);
} // namespace seq
} // namespace mathops

#include <mathops/detail/SEQ/seq_transcedentals.inl>

#endif // SEQ_TRANSCEDENTALS_HPP