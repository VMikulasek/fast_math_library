#ifndef SIMD_VEC2_AVX_FLOAT_HPP
#define SIMD_VEC2_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec2.hpp>

namespace simd
{
namespace avx
{
    Vec2f addv2f(const Vec2f &vec1, const Vec2f &vec2);
    Vec2f subv2f(const Vec2f &vec1, const Vec2f &vec2);
    Vec2f mulv2f(const Vec2f &vec1, const Vec2f &vec2);
    Vec2f divv2f(const Vec2f &vec1, const Vec2f &vec2);
    
    float dotv2f(const Vec2f &vec1, const Vec2f &vec2);
}
} // namespace simd

#include <simd/detail/vec/AVX/simd_vec2_avx_float.inl>

#endif // SIMD_VEC2_AVX_FLOAT_HPP