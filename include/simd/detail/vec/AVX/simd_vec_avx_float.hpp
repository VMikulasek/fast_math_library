#ifndef SIMD_VEC_AVX_FLOAT_HPP
#define SIMD_VEC_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec_t.hpp>

namespace simd
{
namespace avx
{
    template<size_t L>
    inline Vec<L, float> addv(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> subv(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> mulv(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> divv(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    
    template<size_t L>
    inline float dotv(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/AVX/simd_vec_avx_float.inl>

#endif // SIMD_VEC_AVX_FLOAT_HPP