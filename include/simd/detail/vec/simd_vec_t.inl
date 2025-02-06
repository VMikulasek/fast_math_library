#ifndef SIMDVECT_INL
#define SIMDVECT_INL

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/AVX/simd_vec_avx_float.hpp>

#ifdef HAS_AVX

#define addvf(vec1, vec2) avx::addvf(vec1, vec2)
#define subvf(vec1, vec2) avx::subvf(vec1, vec2)
#define mulvf(vec1, vec2) avx::mulvf(vec1, vec2)
#define divvf(vec1, vec2) avx::divvf(vec1, vec2)

#define absvf(vec) avx::absvf(vec)

#define dotvf(vec1, vec2) avx::dotvf(vec1, vec2)

#else // HAS_AVX

#define addvf(vec1, vec2) seq::addv(vec1, vec2)
#define subvf(vec1, vec2) seq::subv(vec1, vec2)
#define mulvf(vec1, vec2) seq::mulv(vec1, vec2)
#define divvf(vec1, vec2) seq::divv(vec1, vec2)

#define absvf(vec) seq::absv(vec)

#define dotvf(vec1, vec2) seq::dotv(vec1, vec2)

#endif // HAS_AVX

namespace simd
{
    template<size_t L, typename T>
    template<typename... Ts>
    inline Vec<L, T>::Vec(Ts... args) : data{args...}
    {
        static_assert((std::is_same_v<T, Ts> && ...), "All arguments must be of type T");
        static_assert(sizeof...(args) == L, "Number of arguments must match the templatesize L");
    }
    template<size_t L, typename T>
    inline Vec<L, T>::Vec() : data{}
    {}

    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator+(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return addvf(*this, other);
        }
        else
        {
            return seq::addv(*this, other);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator-(const Vec<L, T> &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return subvf(*this, other);
        }
        else
        {
            return seq::subv(*this, other);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator*(const Vec<L, T> &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return mulvf(*this, other);
        }
        else
        {
            return seq::mulv(*this, other);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator/(const Vec<L, T> &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return divvf(*this, other);
        }
        else
        {
            return seq::divv(*this, other);
        }
    }

    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::abs() const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return absvf(*this);
        }
        else
        {
            return seq::absv(*this);
        }
    }

    template<size_t L, typename T>
    inline T Vec<L, T>::dot(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return dotvf(vec1, vec2);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }
} // namespace simd

#endif // SIMDVECT_INL