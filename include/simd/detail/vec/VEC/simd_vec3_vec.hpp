#ifndef SIMD_VEC3_VEC_HPP
#define SIMD_VEC3_VEC_HPP

#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
namespace vec
{
    template<typename T, InstructionSet S>
    inline Vec<3, T> addv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<3, T> subv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<3, T> mulv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<3, T> divv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    
    template<typename T, InstructionSet S>
    inline Vec<3, T> absv3(const Vec<3, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<3, T> minv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<3, T> maxv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2);

    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<3, T> fast_sqrtv3(const Vec<3, T> &vec);
    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<3, T> fast_invsqrtv3(const Vec<3, T> &vec);

    template<typename T, InstructionSet S>
    inline Vec<3, T> fast_sinv3(const Vec2f &vec);
    template<typename T, InstructionSet S>
    inline Vec<3, T> fast_cosv3(const Vec2f &vec);

    template<typename T, InstructionSet S>
    inline Vec<3, T> crossv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline T dotv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<typename T, InstructionSet S>
    inline T lengthv3(const Vec<3, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<3, T> normalizev3(const Vec<3, T> &vec);
} // namespace vec
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec3_vec.inl>

#endif // SIMD_VEC3_VEC_HPP