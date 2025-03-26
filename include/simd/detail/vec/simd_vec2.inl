#ifndef SIMD_VEC2_INL
#define SIMD_VEC2_INL

#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/VEC/simd_vec2_vec.hpp>
#include <simd/simd_common.hpp>

#include <type_traits>

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
            return vec::addv2<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return vec::addv2<T, InstructionSet::AVX2>(*this, other);
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
            return vec::subv2<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return vec::subv2<T, InstructionSet::AVX2>(*this, other);
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
            return vec::mulv2<T, InstructionSet::AVX>(*this, other);
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
            return vec::divv2<T, InstructionSet::AVX>(*this, other);
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
            return vec::absv2<T, InstructionSet::AVX>(*this);
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
            return vec::minv2<T, InstructionSet::AVX>(vec1, vec2);
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
            return vec::maxv2<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<typename T>
    inline Vec<2, T> Vec<2, T>::sqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::sqrtv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::fast_sqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX && HAS_AVX2)
        {
            return vec::fast_sqrtv2<T, InstructionSet::AVX, InstructionSet::AVX2>(*this);
        }
        else
        {
            return seq::fast_sqrtv(*this);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::invsqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::invsqrtv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::fast_invsqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX && HAS_AVX2)
        {
            return vec::fast_invsqrtv2<T, InstructionSet::AVX, InstructionSet::AVX2>(*this);
        }
        else
        {
            return seq::fast_invsqrtv(*this);
        }
    }

    template<typename T>
    inline Vec<2, T> Vec<2, T>::sin() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::sinv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::cos() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::cosv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::tan() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::tanv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::cot() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::cotv(*this);
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::fast_sin() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_sinv2<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sinv(*this);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::fast_cos() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_cosv2<T, InstructionSet::AVX>(*this);
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
            return vec::dotv2<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }
    template<typename T>
    inline T Vec<2, T>::length() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::lengthv2<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::lengthv(*this);
        }
    }
    template<typename T>
    inline Vec<2, T> Vec<2, T>::normalize() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::normalizev2<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::normalizev(*this);
        }
    }
} // namespace simd

#endif // SIMD_VEC2_INL