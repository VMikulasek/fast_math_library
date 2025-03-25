#ifndef SIMD_VEC2_INL
#define SIMD_VEC2_INL

#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/VEC/simd_vec2_vec.hpp>

#include <simd/simd_common.hpp>

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
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::addv2v<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return avx::addv2v<T, InstructionSet::AVX2>(*this, other);
        }
        else
        {
            return seq::addv(*this, other);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::operator-(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::subv2v<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return avx::subv2v<T, InstructionSet::AVX2>(*this, other);
        }
        else
        {
            return seq::subv(*this, other);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::operator*(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::mulv2v<T, InstructionSet::AVX>(*this, other);
        }
        else
        {
            return seq::mulv(*this, other);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::operator/(const Vec &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::divv2v<T, InstructionSet::AVX>(*this, other);
        }
        else
        {
            return seq::divv(*this, other);
        }
    }

    template<typename T>
    inline Vec<2, T> Vec<2, T>::abs() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::absv2v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::absv(*this);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::min(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::minv2v<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::minv(vec1, vec2);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::max(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::maxv2v<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<typename T>
    inline Vec<2, T> Vec<2, T>::sqrt() const
    {
        return seq::sqrtv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::fast_sqrt() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::fast_sqrtv2v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sqrtv(*this);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::invsqrt() const
    {
        return seq::invsqrtv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::fast_invsqrt() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::fast_invsqrtv2v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_invsqrtv(*this);
        }
    }

    template<typename T>
    inline Vec<2, T> Vec<2, T>::sin() const
    {
        return seq::sinv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::cos() const
    {
        return seq::cosv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::tan() const
    {
        return seq::tanv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::cot() const
    {
        return seq::cotv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::fast_sin() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::fast_sinv2v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sinv(*this);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::fast_cos() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::fast_cosv2v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_cosv(*this);
        }
    }

    template<typename T>
    inline T Vec<2, T>::dot(const Vec &vec1, const Vec &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::dotv2v<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }
    template<typename T>
    inline T Vec<2, T>::length() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::lengthv2v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::lengthv(*this);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::normalize() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return avx::normalizev2v<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::normalizev(*this);
        }
    }
} // namespace simd

#endif // SIMD_VEC2_INL