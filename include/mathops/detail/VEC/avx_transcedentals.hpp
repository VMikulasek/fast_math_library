#ifndef AVX_TRANSCEDENTALS_HPP
#define AVX_TRANSCEDENTALS_HPP

#include <cstddef>

namespace mathops
{
namespace avx
{
    void fast_sqrt_arr(const float *arr, size_t size, float *dst);
    void fast_invsqrt_arr(const float *arr, size_t size, float *dst);

    void fast_sin_arr(const float *arr, size_t size, float *dst);
    void fast_cos_arr(const float *arr, size_t size, float *dst);
} // namespace avx
} // namespace mathops

#include <mathops/detail/VEC/avx_transcedentals.inl>

#endif // AVX_TRANSCEDENTALS_HPP