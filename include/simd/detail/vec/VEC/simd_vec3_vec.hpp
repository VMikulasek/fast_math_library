#ifndef SIMD_VEC3_VEC_HPP
#define SIMD_VEC3_VEC_HPP

#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
namespace avx
{
    template<typename T, InstructionSet S>
    inline Vec<3, T> addv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<3, T> subv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<3, T> mulv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<3, T> divv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    
    template<typename T, InstructionSet S>
    inline Vec<3, T> absv3v(const Vec<3, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<3, T> minv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<3, T> maxv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);

    template<typename T, InstructionSet S>
    inline Vec<3, T> fast_sqrtv3v(const Vec<3, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<3, T> fast_invsqrtv3v(const Vec<3, T> &vec);

    template<typename T, InstructionSet S>
    inline Vec<3, T> fast_sinv3v(const Vec2f &vec);
    template<typename T, InstructionSet S>
    inline Vec<3, T> fast_cosv3v(const Vec2f &vec);

    template<typename T, InstructionSet S>
    inline Vec<3, T> crossv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline T dotv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline T lengthv3v(const Vec<3, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<3, T> normalizev3v(const Vec<3, T> &vec);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec3_vec.inl>

#endif // SIMD_VEC3_VEC_HPP