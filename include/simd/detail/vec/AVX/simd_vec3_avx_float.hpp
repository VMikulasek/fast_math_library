#ifndef SIMD_VEC3_AVX_FLOAT_HPP
#define SIMD_VEC3_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec3.hpp>

namespace simd
{
namespace avx
{
    inline Vec3f addv3f(const Vec3f &vec1, const Vec3f &vec2);
    inline Vec3f subv3f(const Vec3f &vec1, const Vec3f &vec2);
    inline Vec3f mulv3f(const Vec3f &vec1, const Vec3f &vec2);
    inline Vec3f divv3f(const Vec3f &vec1, const Vec3f &vec2);
    
    inline Vec3f absv3f(const Vec3f &vec);
    inline Vec3f minv3f(const Vec3f &vec1, const Vec3f &vec2);
    inline Vec3f maxv3f(const Vec3f &vec1, const Vec3f &vec2);

    inline Vec3f fast_sqrtv3f(const Vec3f &vec);
    inline Vec3f fast_invsqrtv3f(const Vec3f &vec);

    inline float dotv3f(const Vec3f &vec1, const Vec3f &vec2);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/AVX/simd_vec3_avx_float.inl>

#endif // SIMD_VEC3_AVX_FLOAT_HPP