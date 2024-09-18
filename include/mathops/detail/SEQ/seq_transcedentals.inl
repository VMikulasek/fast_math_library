#ifndef SEQ_TRANSCEDENTALS_INL
#define SEQ_TRANSCEDENTALS_INL

#include <mathops/detail/SEQ/seq_transcedentals.hpp>
#include <mathops/transcedentals.hpp>

namespace mathops
{
namespace seq
{
    inline void fast_sqrt_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = fast_sqrt(arr[i]);
        }
    }

    inline void fast_invsqrt_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = fast_invsqrt(arr[i]);
        }
    }
} // namespace seq
} // namespace mathops

#endif // SEQ_TRANSCEDENTALS_INL