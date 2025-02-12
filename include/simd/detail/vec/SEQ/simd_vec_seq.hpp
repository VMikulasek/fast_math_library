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
    inline Vec<L, T> absv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> minv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T>
    inline Vec<L, T> maxv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);

    template<size_t L, typename T>
    inline Vec<L, T> sqrtv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> fast_sqrtv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> invsqrtv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> fast_invsqrtv(const Vec<L, T> &vec);

    template<size_t L, typename T>
    inline Vec<L, T> sinv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> cosv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> tanv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> cotv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> fast_sinv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> fast_cosv(const Vec<L, T> &vec);

    template<typename T>
    inline Vec<3, T> crossv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2);
    template<size_t L, typename T>
    inline T dotv(const Vec<L, T> &vec1, const Vec<L, T> &vec2);
    template<size_t L, typename T>
    inline T lengthv(const Vec<L, T> &vec);
    template<size_t L, typename T>
    inline Vec<L, T> normalizev(const Vec<L, T> &vec);
} // namespace seq
} // namespace simd

#include <simd/detail/vec/SEQ/simd_vec_seq.inl>

#endif // SIMDVECSEQ_HPP