#ifndef SIMD_VEC2_HPP
#define SIMD_VEC2_HPP

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/simd_common.hpp>
#include <simd/simd_operations.hpp>

#ifdef HAS_AVX

#define VEC_ALIGNMENT SIMDOperations<float, AVX>::ALIGNMENT

#else // HAS_AVX

#define VEC_ALIGNMENT 8

#endif // HAS_AVX

namespace simd
{
    /**
     * @tparam T type of 2 dimensional vector
     */
    template<typename T>
    class Vec<2, T>
    {
    public:
        union alignas(VEC_ALIGNMENT)
        {
            struct{ T x, y; };
            T data[32 / sizeof(T)];
        };
        
        /**
         * @brief Constructs vector with x and y.
         */
        inline Vec(T x, T y);
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
    };

    using Vec2f = Vec<2, float>;
    using Vec2 = Vec<2, int>;
} // namespace simd

#include <simd/detail/vec/simd_vec2.inl>

#endif // SIMD_VEC2_HPP