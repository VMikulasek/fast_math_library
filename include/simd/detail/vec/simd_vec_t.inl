#ifndef SIMDVECT_INL
#define SIMDVECT_INL

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <simd/detail/vec/VEC/simd_vec_vec.hpp>

#include <type_traits>

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
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::addv<L, T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return vec::addv<L, T, InstructionSet::AVX2>(*this, other);
        }
        else
        {
            return seq::addv(*this, other);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator-(const Vec<L, T> &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::subv<L, T, InstructionSet::AVX>(*this, other);
        }
        else if constexpr (std::is_same_v<T, int> && HAS_AVX2)
        {
            return vec::addv<L, T, InstructionSet::AVX2>(*this, other);
        }
        else
        {
            return seq::subv(*this, other);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator*(const Vec<L, T> &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::mulv<L, T, InstructionSet::AVX>(*this, other);
        }
        else
        {
            return seq::mulv(*this, other);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator/(const Vec<L, T> &other) const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::divv<L, T, InstructionSet::AVX>(*this, other);
        }
        else
        {
            return seq::divv<float, InstructionSet::AVX>(*this, other);
        }
    }

    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::abs() const
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::absv<L, T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::absv(*this);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::min(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::minv<L, T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::minv(vec1, vec2);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::max(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::maxv<L, T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::maxv(vec1, vec2);
        }
    }

    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::sqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::sqrtv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::fast_sqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_sqrtv<L, T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sqrtv(*this);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::invsqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::invsqrtv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::fast_invsqrt() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_invsqrtv<L, T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_invsqrtv(*this);
        }
    }

    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::sin() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::sinv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::cos() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::cosv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::tan() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::tanv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::cot() const
    {
        static_assert(std::is_floating_point_v<T>);

        return seq::cotv(*this);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::fast_sin() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_sinv<L, T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_sinv(*this);
        }
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::fast_cos() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::fast_cosv<L, T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::fast_cosv(*this);
        }
    }

    template<size_t L, typename T>
    inline T Vec<L, T>::dot(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::dotv<L, T, InstructionSet::AVX>(vec1, vec2);
        }
        else
        {
            return seq::dotv(vec1, vec2);
        }
    }
    template<size_t L, typename T>
    inline T Vec<L, T>::length() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::lengthv<L, T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::lengthv(*this);
        }
    }template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::normalize() const
    {
        static_assert(std::is_floating_point_v<T>);

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            return vec::normalizev<L, T, InstructionSet::AVX>(*this);
        }
        else
        {
            return seq::normalizev(*this);
        }
    }
} // namespace simd

#endif // SIMDVECT_INL