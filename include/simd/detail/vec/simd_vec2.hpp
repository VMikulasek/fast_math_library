#ifndef SIMD_VEC2_HPP
#define SIMD_VEC2_HPP

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
    template<typename T>
    class Vec<2, T>
    {
    public:
        union alignas(AVX_ALIGNMENT) 
        {
            struct{ T x, y; };
            T data[2];
        };
        
        inline Vec(T x, T y);
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

        inline Vec sin() const;
        inline Vec cos() const;
        inline Vec tan() const;
        inline Vec cot() const;
        inline Vec fast_sin() const;
        inline Vec fast_cos() const;

        inline static T dot(const Vec &vec1, const Vec &vec2);
    };

    using Vec2f = Vec<2, float>;
    using Vec2 = Vec<2, int>;
} // namespace simd

#include <simd/detail/vec/simd_vec2.inl>

#endif // SIMD_VEC2_HPP