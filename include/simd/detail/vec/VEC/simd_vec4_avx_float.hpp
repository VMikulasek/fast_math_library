#ifndef SIMD_VEC4_AVX_FLOAT_HPP
#define SIMD_VEC4_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec4.hpp>

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

    inline Vec4f fast_sqrtv4f(const Vec4f &vec);
    inline Vec4f fast_invsqrtv4f(const Vec4f &vec);

    inline Vec4f fast_sinv4f(const Vec2f &vec);
    inline Vec4f fast_cosv4f(const Vec2f &vec);

    inline float dotv4f(const Vec4f &vec1, const Vec4f &vec2);
    inline float lengthv4f(const Vec4f &vec);
    inline Vec4f normalizev4f(const Vec4f &vec);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec4_avx_float.inl>

#endif // SIMD_VEC4_AVX_FLOAT_HPP