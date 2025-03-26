#ifndef SIMD_VEC3_INL
#define SIMD_VEC3_INL

#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/VEC/simd_vec3_vec.hpp>
#include <simd/simd_common.hpp>

#include <type_traits>

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
            return vec::addv3<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return vec::addv3<T, InstructionSet::AVX2>(*this, other);
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
            return vec::subv3<T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return vec::subv3<T, InstructionSet::AVX2>(*this, other);
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
            return vec::mulv3<T, InstructionSet::AVX>(*this, other);
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
            return vec::divv3<T, InstructionSet::AVX>(*this, other);
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
            return vec::absv3<T, InstructionSet::AVX>(*this);
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
            return vec::minv3<T, InstructionSet::AVX>(vec1, vec2);
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
            return vec::maxv3<T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<typename T>
    inline Vec<3, T> Vec<3, T>::sqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::sqrtv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::fast_sqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_sqrtv3<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sqrtv(*this);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::invsqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::invsqrtv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::fast_invsqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_invsqrtv3<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_invsqrtv(*this);
        }
    }

    template<typename T>
    inline Vec<3, T> Vec<3, T>::sin() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::sinv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::cos() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::cosv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::tan() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::tanv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::cot() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::cotv(*this);
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::fast_sin() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_sinv3<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sinv(*this);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::fast_cos() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_cosv3<T, InstructionSet::AVX>(*this);
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
            return vec::crossv3v<T, InstructionSet::AVX>(vec2, vec1);
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
            return vec::dotv3<T, InstructionSet::AVX>(vec2, vec1);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }
    template<typename T>
    inline T Vec<3, T>::length() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::lengthv3<T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::lengthv(*this);
        }
    }
    template<typename T>
    inline Vec<3, T> Vec<3, T>::normalize() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::normalizev3<T, InstructionSet::AVX>(*this);
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