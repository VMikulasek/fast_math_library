#ifndef STATISTICALS_HPP
#define STATISTICALS_HPP

#include <cstddef>

namespace mathops
{
    /**
     * @brief Finds minimal value from arr`
     */
    float min(const float *arr, size_t size);
    /**
     * @brief Finds maximal value from arr`
     */
    float max(const float *arr, size_t size);
    /**
     * @brief Computes arithmetic mean of values in arr`
     */
    float arithmetic_mean(const float *arr, size_t size);
    /**
     * @brief Computes geometric mean of values in arr`
     */
    float geometric_mean(const float *arr, size_t size);
    /**
     * @brief Computes weighted mean of values in arr`
     */
    float weighted_mean(const float *values, const float *weights, size_t size);
    /**
     * @brief Finds modus of values in arr`
     */
    float modus(const float *arr, size_t size);
    /**
     * @brief Finds median of values in arr`
     */
    float median(const float *arr, size_t size);
    /**
     * @brief Computes variance of values in arr`
     */
    float variance(const float *arr, size_t size);
    /**
     * @brief Computes standard deviation of values in arr`
     */
    float std_deviation(const float *arr, size_t size);
}

#endif // STATISTICALS_HPP