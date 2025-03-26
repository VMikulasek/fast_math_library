#ifndef SEQ_TRANSCENDENTALS_HPP
#define SEQ_TRANSCENDENTALS_HPP

#include <cstddef>

namespace mathops
{
namespace seq
{
    template<typename T>
    void fast_sqrt_arr(const T *arr, size_t size, T *dst);
    template<typename T>
    void fast_invsqrt_arr(const T *arr, size_t size, T *dst);

    template<typename T>
    void fast_sin_arr(const T *arr, size_t size, T *dst);
    template<typename T>
    void fast_cos_arr(const T *arr, size_t size, T *dst);

    template<typename T>
    void sqrt_arr(const T *arr, size_t size, T *dst);
    template<typename T>
    void invsqrt_arr(const T *arr, size_t size, T *dst);
    template<typename T>
    void sin_arr(const T *arr, size_t size, T *dst);
    template<typename T>
    void cos_arr(const T *arr, size_t size, T *dst);
    template<typename T>
    void tan_arr(const T *arr, size_t size, T *dst);
    template<typename T>
    void cot_arr(const T *arr, size_t size, T *dst);
} // namespace seq
} // namespace mathops

#include <mathops/detail/SEQ/seq_transcendentals.inl>

#endif // SEQ_TRANSCENDENTALS_HPP