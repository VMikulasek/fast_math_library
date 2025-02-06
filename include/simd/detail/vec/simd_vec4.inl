#ifndef SIMD_VEC4_INL
#define SIMD_VEC4_INL

#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/detail/vec/AVX/simd_vec4_avx_float.hpp>

#ifdef HAS_AVX

#define addv4f(vec1, vec2) avx::addv4f(vec1, vec2)
#define subv4f(vec1, vec2) avx::subv4f(vec1, vec2)
#define mulv4f(vec1, vec2) avx::mulv4f(vec1, vec2)
#define divv4f(vec1, vec2) avx::divv4f(vec1, vec2)

#define absv4f(vec) avx::absv4f(vec)
#define minv4f(vec1, vec2) avx::minv4f(vec1, vec2)
#define maxv4f(vec1, vec2) avx::maxv4f(vec1, vec2)

#define dotv4f(vec1, vec2) avx::dotv4f(vec1, vec2)

#else // HAS_AVX

#define addv4f(vec1, vec2) seq::addv(vec1, vec2)
#define subv4f(vec1, vec2) seq::subv(vec1, vec2)
#define mulv4f(vec1, vec2) seq::mulv(vec1, vec2)
#define divv4f(vec1, vec2) seq::divv(vec1, vec2)

#define absv4f(vec) seq::absv(vec)
#define minv4f(vec1, vec2) seq::minv(vec1, vec2)
#define maxv4f(vec1, vec2) seq::maxv(vec1, vec2)

#define dotv4f(vec1, vec2) seq::dotv(vec1, vec2)

#endif // HAS_AVX

namespace simd
{
    template<typename T>
    inline Vec<4, T>::Vec(T x, T y, T z, T w) : data{x, y, z, w}
    {}
    template<typename T>
    inline Vec<4, T>::Vec() : data{}
    {}

    template<typename T>
    inline Vec<4, T> Vec<4, T>::operator+(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return addv4f(*this, other);
        }
        else
        {
            return seq::addv(*this, other);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::operator-(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return subv4f(*this, other);
        }
        else
        {
            return seq::subv(*this, other);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::operator*(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return mulv4f(*this, other);
        }
        else
        {
            return seq::mulv(*this, other);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::operator/(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return divv4f(*this, other);
        }
        else
        {
            return seq::divv(*this, other);
        }
    }

    template<typename T>
    inline Vec<4, T> Vec<4, T>::abs() const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return absv4f(*this);
        }
        else
        {
            return seq::absv(*this);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::min(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return minv4f(vec1, vec2);
        }
        else
        {
            return seq::minv(vec1, vec2);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::max(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return maxv4f(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<typename T>
    inline T Vec<4, T>::dot(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return dotv4f(vec1, vec2);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }

    template<typename T>
    inline Vec<2, T> Vec<4, T>::xy()
    {
        return Vec<2, T>(this->x, this->y);
    }
    template<typename T>
    inline Vec<3, T> Vec<4, T>::xyz()
    {
        return Vec<3, T>(this->x, this->y, this->z);
    }
} // namespace simd

#endif // SIMD_VEC4_INL