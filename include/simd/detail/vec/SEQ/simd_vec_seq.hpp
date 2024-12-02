#ifndef SIMDVECSEQ_HPP
#define SIMDVECSEQ_HPP

#include <simd/detail/vec/simd_vec_t.hpp>

namespace simd
{
namespace seq
{
    template<size_t L, typename T>
    inline Vec<L, T> addv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T>
    inline Vec<L, T> subv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T>
    inline Vec<L, T> mulv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T>
    inline Vec<L, T> divv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    
    template<size_t L, typename T>
    inline Vec<L, T> dotv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
} // namespace seq
} // namespace simd

#include <simd/detail/vec/SEQ/simd_vec_seq.inl>

#endif // SIMDVECSEQ_HPP