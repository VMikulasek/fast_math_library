#ifndef SIMD_VEC2_VEC_HPP
#define SIMD_VEC2_VEC_HPP

#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
namespace vec
{
    template<typename T, InstructionSet S>
    inline Vec<2, T> addv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<2, T> subv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<2, T> mulv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<2, T> divv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    
    template<typename T, InstructionSet S>
    inline Vec<2, T> absv2(const Vec<2, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<2, T> minv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<2, T> maxv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2);

    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<2, T> fast_sqrtv2(const Vec<2, T> &vec);
    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<2, T> fast_invsqrtv2(const Vec<2, T> &vec);

    template<typename T, InstructionSet S>
    inline Vec<2, T> fast_sinv2(const Vec<2, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<2, T> fast_cosv2(const Vec<2, T> &vec);

    template<typename T, InstructionSet S>
    inline T dotv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline T lengthv2(const Vec<2, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<2, T> normalizev2(const Vec<2, T> &vec);
} // namespace vec
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec2_vec.inl>

#endif // SIMD_VEC2_VEC_HPP