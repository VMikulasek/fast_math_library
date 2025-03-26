#ifndef SEQ_TRANSCENDENTALS_INL
#define SEQ_TRANSCENDENTALS_INL

#include <mathops/detail/SEQ/seq_transcendentals.hpp>
#include <mathops/transcendentals.hpp>

namespace mathops
{
namespace seq
{
    template<typename T>
    inline void fast_sqrt_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = fast_sqrt(arr[i]);
        }
    }

    template<typename T>
    inline void fast_invsqrt_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = fast_invsqrt(arr[i]);
        }
    }

    template<typename T>
    inline void fast_sin_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = fast_sin(arr[i]);
        }
    }

    template<typename T>
    inline void fast_cos_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = fast_cos(arr[i]);
        }
    }

    template<typename T>
    inline void sqrt_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = sqrt(arr[i]);
        }
    }

    template<typename T>
    inline void invsqrt_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = invsqrt(arr[i]);
        }
    }

    template<typename T>
    inline void sin_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = sin(arr[i]);
        }
    }

    template<typename T>
    inline void cos_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = cos(arr[i]);
        }
    }

    template<typename T>
    inline void tan_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = tan(arr[i]);
        }
    }

    template<typename T>
    inline void cot_arr(const T *arr, size_t size, T *dst)
    {
        for (size_t i = 0; i < size; i++)
        {
            dst[i] = cot(arr[i]);
        }
    }
} // namespace seq
} // namespace mathops

#endif // SEQ_TRANSCENDENTALS_INL