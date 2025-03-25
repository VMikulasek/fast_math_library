#ifndef SIMD_VEC4_VEC_HPP
#define SIMD_VEC4_VEC_HPP

#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
namespace avx
{
    template<typename T, InstructionSet S>
    inline Vec<4, T> addv4v(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<4, T> subv4v(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<4, T> mulv4v(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<4, T> divv4v(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    
    template<typename T, InstructionSet S>
    inline Vec<4, T> absv4v(const Vec<4, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<4, T> minv4v(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<4, T> maxv4v(const Vec<4, T> &vec1, const Vec<4, T> &vec2);

    template<typename T, InstructionSet S>
    inline Vec<4, T> fast_sqrtv4v(const Vec<4, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<4, T> fast_invsqrtv4v(const Vec<4, T> &vec);

    template<typename T, InstructionSet S>
    inline Vec<4, T> fast_sinv4v(const Vec2f &vec);
    template<typename T, InstructionSet S>
    inline Vec<4, T> fast_cosv4v(const Vec2f &vec);

    template<typename T, InstructionSet S>
    inline T dotv4v(const Vec<4, T> &vec1, const Vec<4, T> &vec2);
    template<typename T, InstructionSet S>
    inline T lengthv4v(const Vec<4, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<4, T> normalizev4v(const Vec<4, T> &vec);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec4_vec.inl>

#endif // SIMD_VEC4_VEC_HPP