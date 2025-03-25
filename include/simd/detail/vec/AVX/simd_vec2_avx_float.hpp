#ifndef SIMD_VEC2_AVX_FLOAT_HPP
#define SIMD_VEC2_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec2.hpp>

namespace simd
{
namespace avx
{

    template<typename T>
    inline Vec<2, T> addv2f(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    inline Vec2f subv2f(const Vec2f &vec1, const Vec2f &vec2);
    inline Vec2f mulv2f(const Vec2f &vec1, const Vec2f &vec2);
    inline Vec2f divv2f(const Vec2f &vec1, const Vec2f &vec2);
    
    inline Vec2f absv2f(const Vec2f &vec);
    inline Vec2f minv2f(const Vec2f &vec1, const Vec2f &vec2);
    inline Vec2f maxv2f(const Vec2f &vec1, const Vec2f &vec2);

    inline Vec2f fast_sqrtv2f(const Vec2f &vec);
    inline Vec2f fast_invsqrtv2f(const Vec2f &vec);

    inline Vec2f fast_sinv2f(const Vec2f &vec);
    inline Vec2f fast_cosv2f(const Vec2f &vec);

    inline float dotv2f(const Vec2f &vec1, const Vec2f &vec2);
    inline float lengthv2f(const Vec2f &vec);
    inline Vec2f normalizev2f(const Vec2f &vec);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/AVX/simd_vec2_avx_float.inl>

#endif // SIMD_VEC2_AVX_FLOAT_HPP