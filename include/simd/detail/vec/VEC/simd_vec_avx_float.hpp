#ifndef SIMD_VEC_AVX_FLOAT_HPP
#define SIMD_VEC_AVX_FLOAT_HPP

#include <simd/detail/vec/simd_vec_t.hpp>

namespace simd
{
namespace avx
{
    template<size_t L>
    inline Vec<L, float> addvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> subvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> mulvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> divvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    
    template<size_t L>
    inline Vec<L, float> absvf(const Vec<L, float> &vec);
    template<size_t L>
    inline Vec<L, float> minvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline Vec<L, float> maxvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);

    template<size_t L>
    inline Vec<L, float> fast_sqrtvf(const Vec<L, float> &vec);
    template<size_t L>
    inline Vec<L, float> fast_invsqrtvf(const Vec<L, float> &vec);

    template<size_t L>
    inline Vec<L, float> fast_sinvf(const Vec<L, float> &vec);
    template<size_t L>
    inline Vec<L, float> fast_cosvf(const Vec<L, float> &vec);

    template<size_t L>
    inline float dotvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2);
    template<size_t L>
    inline float lengthvf(const Vec<L, float> &vec);
    template<size_t L>
    inline Vec<L, float> normalizevf(const Vec<L, float> &vec);
    template<size_t L>
    inline float fast_lengthvf(const Vec<L, float> &vec);
    template<size_t L>
    inline Vec<L, float> fast_normalizevf(const Vec<L, float> &vec);
} // namespace avx
} // namespace simd

#include <simd/detail/vec/VEC/simd_vec_avx_float.inl>

#endif // SIMD_VEC_AVX_FLOAT_HPP