#ifndef SIMDVECT_HPP
#define SIMDVECT_HPP

#include <type_traits>
#include <cstddef>
#include <array>

namespace simd
{
    template <size_t L, typename T>
    class Vec
    {
        static_assert(std::is_arithmetic_v<T>);

    public:
        std::array<T, L> data;

        template<typename... Ts>
        inline Vec(Ts... args);
        inline Vec();

        inline Vec operator+(const Vec &other) const;
        inline Vec operator-(const Vec &other) const;
        inline Vec operator*(const Vec &other) const;
        inline Vec operator/(const Vec &other) const;
        inline T dot(const Vec &vec1, const Vec &vec2);
    };
} // namespace simd

#include <simd/detail/vec/simd_vec_t.inl>

#endif // SIMDVECT_HPP