#ifndef SIMDVECFLOAT_HPP
#define SIMDVECFLOAT_HPP

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/simd_common.hpp>

#include <cstddef>
#include <type_traits>

namespace simd
{
    template<size_t L>
    class Vec<L, float>
    {
        using NumType = float;

    public:
        alignas(AVX_ALIGNMENT) NumType data[L];

        template<typename... Ts>
        inline Vec(Ts... args);
        Vec();

        inline Vec operator+(const Vec &other) const;
        inline Vec operator-(const Vec &other) const;
        inline Vec operator*(const Vec &other) const;
        inline Vec operator/(const Vec &other) const;
        inline static NumType dot(const Vec &vec1, const Vec &vec2);
    };
} // namespace simd

#include <simd/detail/vec/simd_vec_float.inl>

#endif // SIMDVECFLOAT_HPP