#ifndef SIMD_VEC4_INL
#define SIMD_VEC4_INL

#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/detail/vec/VEC/simd_vec4_vec.hpp>
#include <simd/simd_common.hpp>

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
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::addv4<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return vec::addv4<T, InstructionSet::AVX2>(*this, other);
        }
        else
        {
            return seq::addv(*this, other);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::operator-(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::subv4<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int>)
        {
            return vec::subv4<T, InstructionSet::AVX2>(*this, other);
        }
        else
        {
            return seq::subv(*this, other);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::operator*(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::mulv4<T, InstructionSet::AVX>(*this, other);
        }
        else
        {
            return seq::mulv(*this, other);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::operator/(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::divv4<T, InstructionSet::AVX>(*this, other);
        }
        else
        {
            return seq::divv(*this, other);
        }
    }

    template<typename T>
    inline Vec<4, T> Vec<4, T>::abs() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::absv4<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::absv(*this);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::min(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::minv4<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::minv(vec1, vec2);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::max(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::maxv4<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<typename T>
    inline Vec<4, T> Vec<4, T>::sqrt() const
    {
        return seq::sqrtv(*this);
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::fast_sqrt() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_sqrtv4<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sqrtv(*this);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::invsqrt() const
    {
        return seq::invsqrtv(*this);
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::fast_invsqrt() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_invsqrtv4<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_invsqrtv(*this);
        }
    }

    template<typename T>
    inline Vec<4, T> Vec<4, T>::sin() const
    {
        return seq::sinv(*this);
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::cos() const
    {
        return seq::cosv(*this);
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::tan() const
    {
        return seq::tanv(*this);
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::cot() const
    {
        return seq::cotv(*this);
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::fast_sin() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_sinv4<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sinv(*this);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::fast_cos() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_cosv4<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_cosv(*this);
        }
    }

    template<typename T>
    inline T Vec<4, T>::dot(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::dotv4<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }
    template<typename T>
    inline T Vec<4, T>::length() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::lengthv4<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::lengthv(*this);
        }
    }
    template<typename T>
    inline Vec<4, T> Vec<4, T>::normalize() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::normalizev4<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::normalizev(*this);
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