#ifndef TRANSCEDENTALS_HPP
#define TRANSCEDENTALS_HPP

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
    float sqrt(float num);

    /**
     * @brief Accelerated computation of square root
     * of num with lower accuracy
     * 
     * Can be actually slower than accurate standard variant
     * if hardware acceleration is present
     */
    float fast_sqrt(float num);

    /**
     * @brief Computes square root of num using
     * 1 / std::sqrt
     */
    float invsqrt(float num);

    /**
     * @brief Accelerated computation of inverse square root
     * of num with lower accuracy
     * using the fast inverse square root algorithm
     * 
     * Can be actually slower than accurate standard variant
     * if hardware acceleration is present
     */
    float fast_invsqrt(float num);

    /**
     * @brief Computes sin of num using std::sin
     */
    float sin(float num);

    /**
     * @brief Accelerated computation of sin of num
     * with lower accuracy (<-pi, pi> maximal error 2^-11)
     *
     * Can be actually slower than accurate standard variant
     * if hardware acceleration is present
     */
    float fast_sin(float num);

    /**
     * @brief Computes cos of num using std::cos
     */
    float cos(float num);

    /**
     * @brief Accelerated computation of cos of num
     * with lower accuracy (<-pi, pi> maximal error 2^-11)
     * 
     * Can be actually slower than accurate standard variant
     * if hardware acceleration is present
     */
    float fast_cos(float num);

    /**
     * @brief Computes tan using std::cos and std::sin
     */
    float tan(float num);

    /**
     * @brief Computes cot using std::cos and std::sin
     */
    float cot(float num);

    /**
     * @brief Calculates fast square root for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
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
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Vector of floats to calculate square root on,
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
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
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
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Vector of floats to calculate square root on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_invsqrt_arr(const std::vector<float> &arr);

    /**
     * @brief Calculates fast sin for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Array of floats to calculate inverse square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_sin_arr(const float *arr, size_t size);

    /**
     * @brief Calculates fast sin for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Vector of floats to calculate square root on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_sin_arr(const std::vector<float> &arr);

    /**
     * @brief Calculates fast cos for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Array of floats to calculate inverse square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_cos_arr(const float *arr, size_t size);

    /**
     * @brief Calculates fast cos for array,
     * if any supported SIMD unit available,
     * then will accelerate the algorithm also
     * with vectorization through biggest SIMD unit available
     * 
     * @param arr Vector of floats to calculate square root on,
     * vector.data() has to be aligned to 32 bytes
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *fast_cos_arr(const std::vector<float> &arr);

    /**
     * @brief Calculates sqrt for array
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *sqrt_arr(const float *arr, size_t size);

    /**
     * @brief Calculates sqrt for vector
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *sqrt_arr(const std::vector<float> &arr);

    /**
     * @brief Calculates invsqrt for array
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *invsqrt_arr(const float *arr, size_t size);

    /**
     * @brief Calculates invsqrt for vector
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *invsqrt_arr(const std::vector<float> &arr);
    
    /**
     * @brief Calculates sin for array
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *sin_arr(const float *arr, size_t size);

    /**
     * @brief Calculates sin for vector
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *sin_arr(const std::vector<float> &arr);
    
    /**
     * @brief Calculates cos for array
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *cos_arr(const float *arr, size_t size);

    /**
     * @brief Calculates cos for vector
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *cos_arr(const std::vector<float> &arr);

    /**
     * @brief Calculates tan for array
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *tan_arr(const float *arr, size_t size);

    /**
     * @brief Calculates tan for vector
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *tan_arr(const std::vector<float> &arr);

    /**
     * @brief Calculates cot for array
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *cot_arr(const float *arr, size_t size);

    /**
     * @brief Calculates cot for vector
     * 
     * @returns Array with results and size of vector.size() floats,
     * that has to be freed after use.
     * If used on windows, then has to be freed with _aligned_free().
     * In case of allocation fail returns nullptr.
     */
    float *cot_arr(const std::vector<float> &arr);
}

#include <mathops/detail/transcedentals.inl>

#endif // TRANSCEDENTALS_HPP