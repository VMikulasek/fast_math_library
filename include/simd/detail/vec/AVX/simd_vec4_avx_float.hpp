#ifndef SIMD_VEC4_AVX_FLOAT_HPP
#define SIMD_VEC4_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec4.hpp>

#undef addv4f
#undef subv4f
#undef mulv4f
#undef divv4f
#undef dotv4f

namespace simd
{
namespace avx
{
    inline Vec4f addv4f(const Vec4f &vec1, const Vec4f &vec2);
    inline Vec4f subv4f(const Vec4f &vec1, const Vec4f &vec2);
    inline Vec4f mulv4f(const Vec4f &vec1, const Vec4f &vec2);
    inline Vec4f divv4f(const Vec4f &vec1, const Vec4f &vec2);
    
    inline Vec4f absv4f(const Vec4f &vec);
    inline Vec4f minv4f(const Vec4f &vec1, const Vec4f &vec2);
    inline Vec4f maxv4f(const Vec4f &vec1, const Vec4f &vec2);

    inline float dotv4f(const Vec4f &vec1, const Vec4f &vec2);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/AVX/simd_vec4_avx_float.inl>

#endif // SIMD_VEC4_AVX_FLOAT_HPP