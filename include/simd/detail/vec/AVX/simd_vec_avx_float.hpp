#ifndef SIMD_VEC_AVX_FLOAT_HPP
#define SIMD_VEC_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec_t.hpp>

#undef addvf
#undef subvf
#undef mulvf
#undef divvf
#undef dotvf

namespace simd
{
namespace avx
{
    template<size_t L>
    inline Vec<L, float> addvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> subvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> mulvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> divvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    
    template<size_t L>
    inline float dotvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/AVX/simd_vec_avx_float.inl>

#endif // SIMD_VEC_AVX_FLOAT_HPP