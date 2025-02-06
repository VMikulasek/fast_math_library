#ifndef SIMDVECT_HPP
#define SIMDVECT_HPP

#include <simd/simd_common.hpp>

#include <type_traits>
#include <cstddef>

namespace simd
{
    template<size_t L, typename T>
    class Vec
    {
        static_assert(std::is_arithmetic_v<T>);

    public:
        alignas(AVX_ALIGNMENT) T data[L];

        template<typename... Ts>
        inline Vec(Ts... args);
        inline Vec();

        inline Vec operator+(const Vec &other) const;
        inline Vec operator-(const Vec &other) const;
        inline Vec operator*(const Vec &other) const;
        inline Vec operator/(const Vec &other) const;
        
        inline Vec abs() const;
        inline static Vec min(const Vec &vec1, const Vec &vec2);
        inline static Vec max(const Vec &vec1, const Vec &vec2);

        inline Vec sqrt() const;
        inline Vec fast_sqrt() const;
        inline Vec invsqrt() const;
        inline Vec fast_invsqrt() const;

        inline static T dot(const Vec &vec1, const Vec &vec2);
    };
} // namespace simd

#include <simd/detail/vec/simd_vec_t.inl>

#endif // SIMDVECT_HPP