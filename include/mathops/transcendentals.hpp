#ifndef TRANSCENDENTALS_HPP
#define TRANSCENDENTALS_HPP

#include <cstddef>
#include <vector>

namespace mathops
{
    constexpr float pi2 = 1 / (2 * 3.1415926535f);
    constexpr float A = 6.28230858f;
    constexpr float B = -41.1693687f;
    constexpr float C = 74.4388885f;

    /**
     * @brief Computes square root of num using
     * std::sqrt
     */
    template<typename T>
    T sqrt(T num);

    /**
     * @brief Accelerated computation of square root
     * of num with lower accuracy
     * 
     * Can be actually slower than accurate standard variant
     * if hardware acceleration is present
     */
    template<typename T>
    T fast_sqrt(T num);

    /**
     * @brief Computes square root of num using
     * 1 / std::sqrt
     */
    template<typename T>
    T invsqrt(T num);

    /**
     * @brief Accelerated computation of inverse square root
     * of num with lower accuracy
     * using the fast inverse square root algorithm
     * 
     * Can be actually slower than accurate standard variant
     * if hardware acceleration is present
     */
    template<typename T>
    T fast_invsqrt(T num);

    /**
     * @brief Computes sin of num using std::sin
     */
    template<typename T>
    T sin(T num);

    /**
     * @brief Accelerated computation of sin of num
     * with lower accuracy (<-pi, pi> maximal error 2^-11)
     *
     * Can be actually slower than accurate standard variant
     * if hardware acceleration is present
     */
    template<typename T>
    T fast_sin(T num);

    /**
     * @brief Computes cos of num using std::cos
     */
    template<typename T>
    T cos(T num);

    /**
     * @brief Accelerated computation of cos of num
     * with lower accuracy (<-pi, pi> maximal error 2^-11)
     * 
     * Can be actually slower than accurate standard variant
     * if hardware acceleration is present
     */
    template<typename T>
    T fast_cos(T num);

    /**
     * @brief Computes tan using std::cos and std::sin
     */
    template<typename T>
    T tan(T num);

    /**
     * @brief Computes cot using std::cos and std::sin
     */
    template<typename T>
    T cot(T num);

    /**
     * @brief Calculates fast square root for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Array to calculate square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *fast_sqrt_arr(const T *arr, size_t size);

    /**
     * @brief Calculates fast square root for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Vector to calculate square root on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @return Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *fast_sqrt_arr(const std::vector<T> &arr);

    /**
     * @brief Calculates fast inverse square root for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Array to calculate inverse square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *fast_invsqrt_arr(const T *arr, size_t size);

    /**
     * @brief Calculates fast inverse square root for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Vector to calculate square root on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *fast_invsqrt_arr(const std::vector<T> &arr);

    /**
     * @brief Calculates fast sin for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Array to calculate inverse square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *fast_sin_arr(const T *arr, size_t size);

    /**
     * @brief Calculates fast sin for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Vector to calculate square root on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *fast_sin_arr(const std::vector<T> &arr);

    /**
     * @brief Calculates fast cos for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Array to calculate inverse square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *fast_cos_arr(const T *arr, size_t size);

    /**
     * @brief Calculates fast cos for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Vector to calculate square root on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *fast_cos_arr(const std::vector<T> &arr);

    /**
     * @brief Calculates sqrt for array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *sqrt_arr(const T *arr, size_t size);

    /**
     * @brief Calculates sqrt for vector
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *sqrt_arr(const std::vector<T> &arr);

    /**
     * @brief Calculates invsqrt for array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *invsqrt_arr(const T *arr, size_t size);

    /**
     * @brief Calculates invsqrt for vector
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *invsqrt_arr(const std::vector<T> &arr);
    
    /**
     * @brief Calculates sin for array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *sin_arr(const T *arr, size_t size);

    /**
     * @brief Calculates sin for vector
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *sin_arr(const std::vector<T> &arr);
    
    /**
     * @brief Calculates cos for array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *cos_arr(const T *arr, size_t size);

    /**
     * @brief Calculates cos for vector
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *cos_arr(const std::vector<T> &arr);

    /**
     * @brief Calculates tan for array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *tan_arr(const T *arr, size_t size);

    /**
     * @brief Calculates tan for vector
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *tan_arr(const std::vector<T> &arr);

    /**
     * @brief Calculates cot for array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *cot_arr(const T *arr, size_t size);

    /**
     * @brief Calculates cot for vector
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *cot_arr(const std::vector<T> &arr);
} // namespace mathops

#include <mathops/detail/transcendentals.inl>

#endif // TRANSCENDENTALS_HPP