#ifndef SIMD_VEC4_HPP
#define SIMD_VEC4_HPP

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
    template<typename T>
    class Vec<4, T>
    {
    public:
        union alignas(AVX_ALIGNMENT)
        {
            struct{ T x, y, z, w; };
            T data[4];
        };
        
        inline Vec(T x, T y, T z, T w);
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

        inline Vec<2, T> xy();
        inline Vec<3, T> xyz();
    };

    using Vec4f = Vec<4, float>;
    using Vec4 = Vec<4, int>;
} // namespace simd

#include <simd/detail/vec/simd_vec4.inl>

#endif // SIMD_VEC4_HPP