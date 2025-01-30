#ifndef SIMDVECFLOAT_INL
#define SIMDVECFLOAT_INL

#include <simd/detail/vec/simd_vec_float.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/AVX/simd_vec_avx_float.hpp>

#ifdef HAS_AVX

#define addv(vec1, vec2) avx::addv(vec1, vec2);
#define subv(vec1, vec2) avx::subv(vec1, vec2);
#define mulv(vec1, vec2) avx::mulv(vec1, vec2);
#define divv(vec1, vec2) avx::divv(vec1, vec2);
#define dotv(vec1, vec2) avx::dotv(vec1, vec2);

#else // HAS_AVX

#define addv(vec1, vec2) seq::addv(vec1, vec2);
#define subv(vec1, vec2) seq::subv(vec1, vec2);
#define mulv(vec1, vec2) seq::mulv(vec1, vec2);
#define divv(vec1, vec2) seq::divv(vec1, vec2);
#define dotv(vec1, vec2) seq::dotv(vec1, vec2);

#endif // HAS_AVX

namespace simd
{
    template<size_t L>
    template<typename... Ts>
    inline Vec<L, float>::Vec(Ts... args) : data{args...}
    {
        static_assert((std::is_same_v<NumType, Ts> && ...), "All arguments must be of type float");
        static_assert(sizeof...(args) == L, "Number of arguments must match the templatesize L");
    }
    template<size_t L>
    inline Vec<L, float>::Vec() : data{}
    {}

    template<size_t L>
    inline Vec<L, float> Vec<L, float>::operator+(const Vec &other) const
    {
        return addv(*this, other);
    }
    template<size_t L>
    inline Vec<L, float> Vec<L, float>::operator-(const Vec &other) const
    {
        return subv(*this, other);
    }
    template<size_t L>
    inline Vec<L, float> Vec<L, float>::operator*(const Vec &other) const
    {
        return mulv(*this, other);
    }
    template<size_t L>
    inline Vec<L, float> Vec<L, float>::operator/(const Vec &other) const
    {
        return divv(*this, other);
    }

    template<size_t L>
    inline float Vec<L, float>::dot(const Vec &vec1, const Vec &vec2)
    {
        return dotv(vec1, vec2);
    }
} // namespace simd

#endif // SIMDVECFLOAT_INL