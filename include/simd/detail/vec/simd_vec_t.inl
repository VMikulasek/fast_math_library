#ifndef SIMDVECT_INL
#define SIMDVECT_INL

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/AVX/simd_vec_avx_float.hpp>

#include <type_traits>

#ifdef HAS_AVX

#define addvf(vec1, vec2) avx::addvf(vec1, vec2)
#define subvf(vec1, vec2) avx::subvf(vec1, vec2)
#define mulvf(vec1, vec2) avx::mulvf(vec1, vec2)
#define divvf(vec1, vec2) avx::divvf(vec1, vec2)

#define absvf(vec) avx::absvf(vec)
#define minvf(vec1, vec2) avx::minvf(vec1, vec2)
#define maxvf(vec1, vec2) avx::maxvf(vec1, vec2)

#define fast_sqrtvf(vec) avx::fast_sqrtvf(vec)
#define fast_invsqrtvf(vec) avx::fast_invsqrtvf(vec)

#define dotvf(vec1, vec2) avx::dotvf(vec1, vec2)

#else // HAS_AVX

#define addvf(vec1, vec2) seq::addv(vec1, vec2)
#define subvf(vec1, vec2) seq::subv(vec1, vec2)
#define mulvf(vec1, vec2) seq::mulv(vec1, vec2)
#define divvf(vec1, vec2) seq::divv(vec1, vec2)

#define absvf(vec) seq::absv(vec)
#define minvf(vec1, vec2) seq::minv(vec1, vec2)
#define maxvf(vec1, vec2) seq::maxv(vec1, vec2)

#define fast_sqrtvf(vec) seq::fast_sqrtv(vec)
#define fast_invsqrtvf(vec) seq::fast_invsqrtv(vec)

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
    inline Vec<L, T> Vec<L, T>::min(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return minvf(vec1, vec2);
        }
        else
        {
            return seq::minv(vec1, vec2);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::max(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return maxvf(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::sqrt() const
    {
        return seq::sqrtv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::fast_sqrt() const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return fast_sqrtvf(*this);
        }
        else
        {
            return seq::fast_sqrtv(*this);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::invsqrt() const
    {
        return seq::invsqrtv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::fast_invsqrt() const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return fast_invsqrtvf(*this);
        }
        else
        {
            return seq::fast_invsqrtv(*this);
        }
    }

    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::sin() const
    {
        return seq::sinv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::cos() const
    {
        return seq::cosv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::tan() const
    {
        return seq::tanv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::cot() const
    {
        return seq::cotv(*this);
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