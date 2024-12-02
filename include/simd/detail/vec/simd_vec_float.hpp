#ifndef SIMDVECFLOAT_HPP
#define SIMDVECFLOAT_HPP

#include <simd/detail/vec/simd_vec_t.hpp>

#include <cstddef>
#include <type_traits>
#include <array>

namespace simd
{
    template<size_t L>
    class Vec<L, float>
    {
        using NumType = float;

    public:
        std::array<NumType, L> data;

        template<typename... Ts>
        inline Vec(Ts... args);

        inline Vec operator+(const Vec &other) const;
        inline Vec operator-(const Vec &other) const;
        inline Vec operator*(const Vec &other) const;
        inline Vec operator/(const Vec &other) const;
        inline NumType dot(const Vec &vec1, const Vec &vec2);

    private:
        Vec() = default;
    };
} // namespace simd

#include <simd/detail/vec/simd_vec_float.inl>

#endif // SIMDVECFLOAT_HPP