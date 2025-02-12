#ifndef SIMD_VEC3_HPP
#define SIMD_VEC3_HPP

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
    /**
     * @tparam T type of 3 dimensional vector
     */
    template<typename T>
    class Vec<3, T>
    {
    public:
        union alignas(AVX_ALIGNMENT) 
        {
            struct{ T x, y, z; };
            T data[3];
        };
        
        /**
         * @brief Constructs vector with x, y and z.
         */
        inline Vec(T x, T y, T z);
        /**
         * @brief Constructs vector with all zeros.
         */
        inline Vec();

        inline Vec operator+(const Vec &other) const;
        inline Vec operator-(const Vec &other) const;
        inline Vec operator*(const Vec &other) const;
        inline Vec operator/(const Vec &other) const;

        /**
         * @brief Absolute value
         */
        inline Vec abs() const;
        /**
         * @brief Minimum from two vectors on each position
         */
        inline static Vec min(const Vec &vec1, const Vec &vec2);
        /**
         * @brief Maximum from two vectors on each position
         */
        inline static Vec max(const Vec &vec1, const Vec &vec2);

        /**
         * @brief Square root of a vector
         */
        inline Vec sqrt() const;
        /**
         * @brief Approximated square root of a vector
         */
        inline Vec fast_sqrt() const;
        /**
         * @brief Inverse square root of a vector
         */
        inline Vec invsqrt() const;
        /**
         * @brief Approximated inverse square root of a vector
         */
        inline Vec fast_invsqrt() const;

        /**
         * @brief Sine of a vector
         */
        inline Vec sin() const;
        /**
         * @brief Cosine of a vector
         */
        inline Vec cos() const;
        /**
         * @brief Tangent of a vector
         */
        inline Vec tan() const;
        /**
         * @brief Cotangent of a vector
         */
        inline Vec cot() const;
        /**
         * @brief Approximated sine of a vector
         */
        inline Vec fast_sin() const;
        /**
         * @brief Approximated cosine of a vector
         */
        inline Vec fast_cos() const;

        /**
         * @brief Cross product
         */
        inline static Vec cross(const Vec &vec1, const Vec &vec2);
        /**
         * @brief Dot product
         */
        inline static T dot(const Vec &vec1, const Vec &vec2);
        /**
         * @brief Length of a vector
         */
        inline T length() const;
        /**
         * @brief Normalizes vector
         */
        inline Vec normalize() const;

        /**
         * @brief Creates 2 dimensional vector with current x and y
         */
        inline Vec<2, T> xy();
    };

    using Vec3f = Vec<3, float>;
    using Vec3 = Vec<3, int>;
} // namespace simd

#include <simd/detail/vec/simd_vec3.inl>

#endif // SIMD_VEC3_HPP