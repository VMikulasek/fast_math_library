#ifndef AVX_TRANSCENDENTALS_HPP
#define AVX_TRANSCENDENTALS_HPP

#include <simd/simd_common.hpp>

#include <cstddef>

namespace mathops
{
namespace vec
{
    template<typename T, simd::InstructionSet FS, simd::InstructionSet IS>
    void fast_sqrt_arr(const T *arr, size_t size, T *dst);
    template<typename T, simd::InstructionSet FS, simd::InstructionSet IS>
    void fast_invsqrt_arr(const T *arr, size_t size, T *dst);

    template<typename T, simd::InstructionSet S>
    void fast_sin_arr(const T *arr, size_t size, T *dst);
    template<typename T, simd::InstructionSet S>
    void fast_cos_arr(const T *arr, size_t size, T *dst);
} // namespace vec
} // namespace mathops

#include <mathops/detail/VEC/vec_transcendentals.inl>

#endif // VEC_TRANSCENDENTALS_HPP