#ifndef SIMD_VEC3_INL
#define SIMD_VEC3_INL

#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/AVX/simd_vec3_avx_float.hpp>

#ifdef HAS_AVX

#define addv3f(vec1, vec2) avx::addv3f(vec1, vec2);
#define subv3f(vec1, vec2) avx::subv3f(vec1, vec2);
#define mulv3f(vec1, vec2) avx::mulv3f(vec1, vec2);
#define divv3f(vec1, vec2) avx::divv3f(vec1, vec2);
#define dotv3f(vec1, vec2) avx::dotv3f(vec1, vec2);

#else // HAS_AVX

#define addv3f(vec1, vec2) seq::addv(vec1, vec2);
#define subv3f(vec1, vec2) seq::subv(vec1, vec2);
#define mulv3f(vec1, vec2) seq::mulv(vec1, vec2);
#define divv3f(vec1, vec2) seq::divv(vec1, vec2);
#define dotv3f(vec1, vec2) seq::dotv(vec1, vec2);

#endif // HAS_AVX

namespace simd
{
    template<typename T>
    Vec<3, T>::Vec(T x, T y, T z) : data{x, y, z}
    {}
    template<typename T>
    Vec<3, T>::Vec() : data{}
    {}

    template<typename T>
    Vec<3, T> Vec<3, T>::operator+(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return addv3f(*this, other);
        }
        else
        {
            return seq::addv(*this, other);
        }
    }
    template<typename T>
    Vec<3, T> Vec<3, T>::operator-(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return subv3f(*this, other);
        }
        else
        {
            return seq::subv(*this, other);
        }
    }
    template<typename T>
    Vec<3, T> Vec<3, T>::operator*(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return mulv3f(*this, other);
        }
        else
        {
            return seq::mulv(*this, other);
        }
    }
    template<typename T>
    Vec<3, T> Vec<3, T>::operator/(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return divv3f(*this, other);
        }
        else
        {
            return seq::divv(*this, other);
        }
    }
    template<typename T>
    T Vec<3, T>::dot(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float>)
        {
            return dotv3f(*this, other);
        }
        else
        {
            return seq::dotv(*this, other);
        }
    }
} // namespace simd

#endif // SIMD_VEC3_INL