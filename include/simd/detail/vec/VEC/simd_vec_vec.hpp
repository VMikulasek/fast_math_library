#ifndef SIMD_VEC_VEC_HPP
#define SIMD_VEC_VEC_HPP

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
namespace vec
{
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> addv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> subv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> mulv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> divv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> absv(const Vec<L, T> &vec);
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> minv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> maxv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);

    template<size_t L, typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<L, T> fast_sqrtv(const Vec<L, T> &vec);
    template<size_t L, typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<L, T> fast_invsqrtv(const Vec<L, T> &vec);

    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> fast_sinv(const Vec<L, T> &vec);
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> fast_cosv(const Vec<L, T> &vec);

    template<size_t L, typename T, InstructionSet S>
    inline T dotv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T, InstructionSet S>
    inline T lengthv(const Vec<L, T> &vec);
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> normalizev(const Vec<L, T> &vec);
} // namespace vec
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec_vec.inl>

#endif // SIMD_VEC_VEC_HPP