#ifndef SUMS_HPP
#define SUMS_HPP

#include <cstddef>
#include <vector>

namespace mathops
{
    /**
     * @brief Computes sum of arr accelerated with
     * biggest SIMD unit supported and available on
     * PC, in case of no SIMD unit available, computes
     * sequentially
     * 
     * @param arr Array to sum, aligned to 32 bytes,
     * otherwise segmentation fault may be generated
     * @param size Size of array
     * 
     * @returns Sum of arr
     */
    template<typename T>
    T sum(const T *arr, size_t size);
    /**
     * @brief Computes sum of arr accelerated with
     * biggest SIMD unit supported and available on
     * PC, in case of no SIMD unit available, computes
     * sequentially
     * 
     * @param arr Vector to perform prefix sum on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Sum of arr
     */
    template<typename T>
    T sum(const std::vector<T> &arr);
    
    /**
     * @brief Computes prefix sum of arr accelerated
     * with biggest SIMD unit supported and available on
     * PC, in case of no SIMD unit available, computes
     * sequentially 
     * 
     * @param arr Array to perform prefix sum on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *prefix_sum(const T *arr, size_t size);

    /**
     * @brief Computes prefix sum of arr accelerated
     * with biggest SIMD unit supported and available on
     * PC, in case of no SIMD unit available, computes
     * sequentially 
     * 
     * @param arr Vector to perform prefix sum on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Array with results,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    template<typename T>
    T *prefix_sum(const std::vector<T> &arr);
} // namespace mathops

#include <mathops/detail/sums.inl>

#endif // SUMS_HPP