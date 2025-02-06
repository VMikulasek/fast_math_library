#ifndef SIMD_VEC3_HPP
#define SIMD_VEC3_HPP

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
    template<typename T>
    class Vec<3, T>
    {
    public:
        union alignas(AVX_ALIGNMENT) 
        {
            struct{ T x, y, z; };
            T data[3];
        };
        
        inline Vec(T x, T y, T z);
        inline Vec();

        inline Vec operator+(const Vec &other) const;
        inline Vec operator-(const Vec &other) const;
        inline Vec operator*(const Vec &other) const;
        inline Vec operator/(const Vec &other) const;

        inline Vec abs() const;
        inline static Vec min(const Vec &vec1, const Vec &vec2);
        inline static Vec max(const Vec &vec1, const Vec &vec2);

        inline static T dot(const Vec &vec1, const Vec &vec2);

        inline Vec<2, T> xy();
    };

    using Vec3f = Vec<3, float>;
    using Vec3 = Vec<3, int>;
} // namespace simd

#include <simd/detail/vec/simd_vec3.inl>

#endif // SIMD_VEC3_HPP