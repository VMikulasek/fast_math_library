#ifndef SIMD_VEC2_VEC_HPP
#define SIMD_VEC2_VEC_HPP

#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
namespace avx
{

    template<typename T, InstructionSet S>
    inline Vec<2, T> addv2v(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<2, T> subv2v(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<2, T> mulv2v(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<2, T> divv2v(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    
    template<typename T, InstructionSet S>
    inline Vec<2, T> absv2v(const Vec<2, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<2, T> minv2v(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline Vec<2, T> maxv2v(const Vec<2, T> &vec1, const Vec<2, T> &vec2);

    template<typename T, InstructionSet S>
    inline Vec<2, T> fast_sqrtv2v(const Vec<2, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<2, T> fast_invsqrtv2v(const Vec<2, T> &vec);

    template<typename T, InstructionSet S>
    inline Vec<2, T> fast_sinv2v(const Vec<2, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<2, T> fast_cosv2v(const Vec<2, T> &vec);

    template<typename T, InstructionSet S>
    inline T dotv2v(const Vec<2, T> &vec1, const Vec<2, T> &vec2);
    template<typename T, InstructionSet S>
    inline T lengthv2v(const Vec<2, T> &vec);
    template<typename T, InstructionSet S>
    inline Vec<2, T> normalizev2v(const Vec<2, T> &vec);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec2_vec.inl>

#endif // SIMD_VEC2_VEC_HPP