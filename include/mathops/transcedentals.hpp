#ifndef TRANSCEDENTALS_HPP
#define TRANSCEDENTALS_HPP

#include <cstddef>
#include <vector>

namespace mathops
{
    /**
     * @brief Computes square root of num using
     * C++ standard library
     */
    float sqrt(float num);

    /**
     * @brief Accelerated computation of square root
     * of num with lower accuracy
     */
    float fast_sqrt(float num);

    /**
     * @brief Accelerated computation of inverse square root
     * of num with lower accuracy
     * using the fast inverse square root algorithm
     */
    float fast_invsqrt(float num);

    /**
     * @brief Calculates fast square root for array,
     * if any supported SIMD unit available,
     * then accelerates the algorithm also
     * with vectorisation through biggest SIMD unit available
     * 
     * @param arr Array of floats to calculate square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results and size of size floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_sqrt_arr(const float *arr, size_t size);

    /**
     * @brief Calculates fast square root for array,
     * if any supported SIMD unit available,
     * then accelerates the algorithm also
     * with vectorisation through biggest SIMD unit available
     * 
     * @param arr Vector of floats to calculate square root om,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @return Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_sqrt_arr(const std::vector<float> &arr);

    /**
     * @brief Calculates fast inverse square root for array,
     * if any supported SIMD unit available,
     * then accelerates the algorithm also
     * with vectorisation through biggest SIMD unit available
     * 
     * @param arr Array of floats to calculate inverse square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results and size of size floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_invsqrt_arr(const float *arr, size_t size);

    /**
     * @brief Calculates fast inverse square root for array,
     * if any supported SIMD unit available,
     * then accelerates the algorithm also
     * with vectorisation through biggest SIMD unit available
     * 
     * @param arr Vector of floats to calculate square root om,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_invsqrt_arr(const std::vector<float> &arr);
}

#include <mathops/detail/transcedentals.inl>

#endif // TRANSCEDENTALS_HPP