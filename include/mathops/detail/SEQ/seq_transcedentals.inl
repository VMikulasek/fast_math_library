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

    inline void fast_sin_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = fast_sin(arr[i]);
        }
    }

    inline void fast_cos_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = fast_cos(arr[i]);
        }
    }

    inline void sqrt_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = sqrt(arr[i]);
        }
    }

    inline void invsqrt_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = invsqrt(arr[i]);
        }
    }

    inline void sin_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = sin(arr[i]);
        }
    }

    inline void cos_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = cos(arr[i]);
        }
    }

    inline void tan_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = tan(arr[i]);
        }
    }

    inline void cot_arr(const float *arr, size_t size, float *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = cot(arr[i]);
        }
    }
} // namespace seq
} // namespace mathops

#endif // SEQ_TRANSCEDENTALS_INL