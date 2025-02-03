#ifndef SIMD_VEC3_AVX_FLOAT_HPP
#define SIMD_VEC3_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec3.hpp>

#undef addv3f
#undef subv3f
#undef mulv3f
#undef divv3f
#undef dotv3f

namespace simd
{
namespace avx
{
    Vec3f addv3f(const Vec3f &vec1, const Vec3f &vec2);
    Vec3f subv3f(const Vec3f &vec1, const Vec3f &vec2);
    Vec3f mulv3f(const Vec3f &vec1, const Vec3f &vec2);
    Vec3f divv3f(const Vec3f &vec1, const Vec3f &vec2);
    
    float dotv3f(const Vec3f &vec1, const Vec3f &vec2);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/AVX/simd_vec3_avx_float.inl>

#endif // SIMD_VEC3_AVX_FLOAT_HPP