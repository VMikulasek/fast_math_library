#ifndef SIMD_VEC4_VEC_HPP
#define SIMD_VEC4_VEC_HPP

#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
namespace vec
{
    template<typename T, InstructionSet S>
    inline Vec<4, T> addv4(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<4, T> subv4(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<4, T> mulv4(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<4, T> divv4(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    
    template<typename T, InstructionSet S>
    inline Vec<4, T> absv4(const Vec<4, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<4, T> minv4(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<4, T> maxv4(const Vec<4, T> &vec1, const Vec<4, T> &vec2);

    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<4, T> fast_sqrtv4(const Vec<4, T> &vec);
    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<4, T> fast_invsqrtv4(const Vec<4, T> &vec);

    template<typename T, InstructionSet S>
    inline Vec<4, T> fast_sinv4(const Vec2f &vec);
    template<typename T, InstructionSet S>
    inline Vec<4, T> fast_cosv4(const Vec2f &vec);

    template<typename T, InstructionSet S>
    inline T dotv4(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline T lengthv4(const Vec<4, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<4, T> normalizev4(const Vec<4, T> &vec);
} // namespace vec
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec4_vec.inl>

#endif // SIMD_VEC4_VEC_HPP