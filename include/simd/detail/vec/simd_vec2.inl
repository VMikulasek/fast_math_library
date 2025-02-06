#ifndef SIMD_VEC2_INL
#define SIMD_VEC2_INL

#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/AVX/simd_vec2_avx_float.hpp>

#ifdef HAS_AVX

#define addv2f(vec1, vec2) avx::addv2f(vec1, vec2)
#define subv2f(vec1, vec2) avx::subv2f(vec1, vec2)
#define mulv2f(vec1, vec2) avx::mulv2f(vec1, vec2)
#define divv2f(vec1, vec2) avx::divv2f(vec1, vec2)

#define absv2f(vec) avx::absv2f(vec)
#define minv2f(vec1, vec2) avx::minv2f(vec1, vec2)
#define maxv2f(vec1, vec2) avx::maxv2f(vec1, vec2)

#define dotv2f(vec1, vec2) avx::dotv2f(vec1, vec2)

#else // HAS_AVX

#define addv2f(vec1, vec2) seq::addv(vec1, vec2)
#define subv2f(vec1, vec2) seq::subv(vec1, vec2)
#define mulv2f(vec1, vec2) seq::mulv(vec1, vec2)
#define divv2f(vec1, vec2) seq::divv(vec1, vec2)

#define absv2f(vec) seq::absv(vec)
#define minv2f(vec1, vec2) seq::minv(vec1, vec2)
#define maxv2f(vec1, vec2) seq::maxv(vec1, vec2)

#define dotv2f(vec1, vec2) seq::dotv(vec1, vec2)

#endif // HAS_AVX

namespace simd
{
    template<typename T>
    inline Vec<2, T>::Vec(T x, T y) : data{x, y}
    {}
    template<typename T>
    inline Vec<2, T>::Vec() : data{}
    {}

    template<typename T>
    inline Vec<2, T> Vec<2, T>::operator+(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return addv2f(*this, other);
        }
        else
        {
            return seq::addv(*this, other);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::operator-(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return subv2f(*this, other);
        }
        else
        {
            return seq::subv(*this, other);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::operator*(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return mulv2f(*this, other);
        }
        else
        {
            return seq::mulv(*this, other);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::operator/(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return divv2f(*this, other);
        }
        else
        {
            return seq::divv(*this, other);
        }
    }

    template<typename T>
    inline Vec<2, T> Vec<2, T>::abs() const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return absv2f(*this);
        }
        else
        {
            return seq::absv(*this);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::min(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return minv2f(vec1, vec2);
        }
        else
        {
            return seq::minv(vec1, vec2);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::max(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return maxv2f(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<typename T>
    inline T Vec<2, T>::dot(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return dotv2f(vec1, vec2);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }
} // namespace simd

#endif // SIMD_VEC2_INL