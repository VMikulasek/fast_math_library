#ifndef STATISTICALS_HPP
#define STATISTICALS_HPP

#include <cstddef>
#include <vector>

namespace mathops
{
    /**
     * @brief Finds minimal value from arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float min(const float *arr, size_t size);
    /**
     * @brief Finds minimal value from arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float min(const std::vector<float> &arr);
    /**
     * @brief Finds maximal value from arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float max(const float *arr, size_t size);
    /**
     * @brief Finds maximal value from arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float max(const std::vector<float> &arr);    
    
    /**
     * @brief Computes arithmetic mean of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float arithmetic_mean(const float *arr, size_t size);
    /**
     * @brief Computes arithmetic mean of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float arithmetic_mean(const std::vector<float> &arr);
    /**
     * @brief Computes geometric mean of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float geometric_mean(const float *arr, size_t size);
    /**
     * @brief Computes geometric mean of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float geometric_mean(const std::vector<float> &arr);
    /**
     * @brief Computes weighted mean of values in arr
     * 
     * @param values Has to be aligned to 32 bytes
     * @param weights Has to be aligned to 32 bytes
     */
    float weighted_mean(const float *values, const float *weights, size_t size);
    /**
     * @brief Computes weighted mean of values in arr
     * 
     * @param values values.data has to be aligned to 32 bytes
     * @param weights has to be at least as long as values
     * and weights.data has to be aligned to 32 bytes
     */
    float weighted_mean(const std::vector<float> &values, const std::vector<float> &weights);

    /**
     * @brief Finds mode of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    int mode(const int *arr, size_t size);
    /**
     * @brief Finds mode of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    int mode(const std::vector<int> &arr);
    /**
     * @brief Finds median of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float median(const float *arr, size_t size);
    /**
     * @brief Finds median of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float median(const std::vector<float> &arr);
    /**
     * @brief Finds median of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float median(const int *arr, size_t size);
    /**
     * @brief Finds median of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float median(const std::vector<int> &arr);

    /**
     * @brief Computes variance of values in arr, each value same probability 
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float variance(const float *arr, size_t size);
    /**
     * @brief Computes variance of values in arr, each value same probability 
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float variance(const std::vector<float> &arr);
    /**
     * @brief Computes variance of values in arr, according to given probabilities
     * 
     * @param values Has to be aligned to 32 bytes
     * @param probabilities Has to be aligned to 32 bytes
     */
    float variance(const float *values, const float *probabilities, size_t size);
    /**
     * @brief Computes variance of values in arr, according to given probabilities
     * 
     * @param values values.data has to be aligned to 32 bytes
     * @param probabilities has to be at least as long as values
     * and probabilities.data has to be aligned to 32 bytes
     */
    float variance(const std::vector<float> &values, const std::vector<float> &probabilities);
    /**
     * @brief Computes sample variance of values in arr, each value same probability 
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float sample_variance(const float *arr, size_t size);
    /**
     * @brief Computes sample variance of values in arr, each value same probability 
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float sample_variance(const std::vector<float> &arr);
    /**
     * @brief Computes standard deviation of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float std_deviation(const float *arr, size_t size);
    /**
     * @brief Computes standard deviation of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float std_deviation(const std::vector<float> &arr);
    /**
     * @brief Computes std deviation of values in arr, according to given probabilities
     * 
     * @param values Has to be aligned to 32 bytes
     * @param probabilities Has to be aligned to 32 bytes
     */
    float std_deviation(const float *values, const float *probabilities, size_t size);
    /**
     * @brief Computes std deviation of values in arr, according to given probabilities
     * 
     * @param values values.data has to be aligned to 32 bytes
     * @param probabilities has to be at least as long as values
     * and probabilities.data has to be aligned to 32 bytes
     */
    float std_deviation(const std::vector<float> &values, const std::vector<float> &probabilities);

    /**
     * @brief Computes sample standard deviation of values in arr (with Bessels correction)
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    float sample_std_deviation(const float *arr, size_t size);
    /**
     * @brief Computes sample standard deviation of values in arr (with Bessels correction)
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    float sample_std_deviation(const std::vector<float> &arr);
} // namespace mathops

#include <mathops/detail/statisticals.inl>

#endif // STATISTICALS_HPP