#ifndef SIMD_VEC3_INL
#define SIMD_VEC3_INL

#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/VEC/simd_vec3_vec.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
    template<typename T>
    inline Vec<3, T>::Vec(T x, T y, T z) : data{x, y, z}
    {}
    template<typename T>
    inline Vec<3, T>::Vec() : data{}
    {}

    template<typename T>
    inline Vec<3, T> Vec<3, T>::operator+(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::addv3v<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return avx::addv3v<T, InstructionSet::AVX2>(*this, other);
        }
        else
        {
            return seq::addv(*this, other);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::operator-(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::subv3v<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return avx::subv3v<T, InstructionSet::AVX2>(*this, other);
        }
        else
        {
            return seq::subv(*this, other);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::operator*(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::mulv3v<T, InstructionSet::AVX>(*this, other);
        }
        else
        {
            return seq::mulv(*this, other);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::operator/(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::divv3v<T, InstructionSet::AVX>(*this, other);
        }
        else
        {
            return seq::divv(*this, other);
        }
    }

    template<typename T>
    inline Vec<3, T> Vec<3, T>::abs() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::absv3v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::absv(*this);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::min(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::minv3v<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::minv(vec1, vec2);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::max(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::maxv3v<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<typename T>
    inline Vec<3, T> Vec<3, T>::sqrt() const
    {
        return seq::sqrtv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::fast_sqrt() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::fast_sqrtv3v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sqrtv(*this);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::invsqrt() const
    {
        return seq::invsqrtv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::fast_invsqrt() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::fast_invsqrtv3v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_invsqrtv(*this);
        }
    }

    template<typename T>
    inline Vec<3, T> Vec<3, T>::sin() const
    {
        return seq::sinv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::cos() const
    {
        return seq::cosv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::tan() const
    {
        return seq::tanv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::cot() const
    {
        return seq::cotv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::fast_sin() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::fast_sinv3v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sinv(*this);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::fast_cos() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::fast_cosv3v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_cosv(*this);
        }
    }

    template<typename T>
    inline Vec<3, T> Vec<3, T>::cross(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::crossv3v<T, InstructionSet::AVX>(vec2, vec1);
        }
        else
        {
            return seq::crossv3(vec1, vec2);
        }
    }
    template<typename T>
    inline T Vec<3, T>::dot(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::dotv3v<T, InstructionSet::AVX>(vec2, vec1);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }
    template<typename T>
    inline T Vec<3, T>::length() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::lengthv3v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::lengthv(*this);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::normalize() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::normalizev3v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::normalizev(*this);
        }
    }

    template<typename T>
    inline Vec<2, T> Vec<3, T>::xy()
    {
        return Vec<2, T>(this->x, this->y);
    }
} // namespace simd

#endif // SIMD_VEC3_INL