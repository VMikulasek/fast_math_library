#ifndef SEQ_TRANSCEDENTALS_HPP
#define SEQ_TRANSCEDENTALS_HPP

#include <cstddef>

namespace mathops
{
namespace seq
{
    void fast_sqrt_arr(const float *arr, size_t size, float *dst);
    void fast_invsqrt_arr(const float *arr, size_t size, float *dst);

    void fast_sin_arr(const float *arr, size_t size, float *dst);
    void fast_cos_arr(const float *arr, size_t size, float *dst);

    void sqrt_arr(const float *arr, size_t size, float *dst);
    void invsqrt_arr(const float *arr, size_t size, float *dst);
    void sin_arr(const float *arr, size_t size, float *dst);
    void cos_arr(const float *arr, size_t size, float *dst);
    void tan_arr(const float *arr, size_t size, float *dst);
    void cot_arr(const float *arr, size_t size, float *dst);
} // namespace seq
} // namespace mathops

#include <mathops/detail/SEQ/seq_transcedentals.inl>

#endif // SEQ_TRANSCEDENTALS_HPP