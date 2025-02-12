#ifndef SIMDVECT_HPP
#define SIMDVECT_HPP

#include <simd/simd_common.hpp>

#include <type_traits>
#include <cstddef>

namespace simd
{
    /**
     * @tparam L Length of the vector
     * @tparam T Type of the vector
     */
    template<size_t L, typename T>
    class Vec
    {
        static_assert(std::is_arithmetic_v<T>);

    public:
        alignas(AVX_ALIGNMENT) T data[L];

        /**
         * @brief Constructs vector with args.
         * 
         * @param args Numbers to which the vector should be initialized.
         * Amount of args has to correspond with length of the vector and
         * type of args has to correspond with type of the vector.
         */
        template<typename... Ts>
        inline Vec(Ts... args);
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
} // namespace simd

#include <simd/detail/vec/simd_vec_t.inl>

#endif // SIMDVECT_HPP