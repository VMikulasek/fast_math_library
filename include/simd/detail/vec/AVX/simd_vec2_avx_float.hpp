#ifndef SIMD_VEC2_AVX_FLOAT_HPP
#define SIMD_VEC2_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec2.hpp>

#undef addv2f
#undef subv2f
#undef mulv2f
#undef divv2f
#undef dotv2f

namespace simd
{
namespace avx
{
    Vec2f addv2f(const Vec2f &vec1, const Vec2f &vec2);
    Vec2f subv2f(const Vec2f &vec1, const Vec2f &vec2);
    Vec2f mulv2f(const Vec2f &vec1, const Vec2f &vec2);
    Vec2f divv2f(const Vec2f &vec1, const Vec2f &vec2);
    
    float dotv2f(const Vec2f &vec1, const Vec2f &vec2);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/AVX/simd_vec2_avx_float.inl>

#endif // SIMD_VEC2_AVX_FLOAT_HPP