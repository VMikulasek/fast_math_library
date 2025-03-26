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
    template<typename T>
    T min(const T *arr, size_t size);
    /**
     * @brief Finds minimal value from arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T min(const std::vector<T> &arr);
    /**
     * @brief Finds maximal value from arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T max(const T *arr, size_t size);
    /**
     * @brief Finds maximal value from arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T max(const std::vector<T> &arr);    
    
    /**
     * @brief Computes arithmetic mean of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T arithmetic_mean(const T *arr, size_t size);
    /**
     * @brief Computes arithmetic mean of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T arithmetic_mean(const std::vector<T> &arr);
    /**
     * @brief Computes geometric mean of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T geometric_mean(const T *arr, size_t size);
    /**
     * @brief Computes geometric mean of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T geometric_mean(const std::vector<T> &arr);
    /**
     * @brief Computes weighted mean of values in arr
     * 
     * @param values Has to be aligned to 32 bytes
     * @param weights Has to be aligned to 32 bytes
     */
    template<typename T>
    T weighted_mean(const T *values, const T *weights, size_t size);
    /**
     * @brief Computes weighted mean of values in arr
     * 
     * @param values values.data has to be aligned to 32 bytes
     * @param weights has to be at least as long as values
     * and weights.data has to be aligned to 32 bytes
     */
    template<typename T>
    T weighted_mean(const std::vector<T> &values, const std::vector<T> &weights);

    /**
     * @brief Finds mode of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T mode(const T *arr, size_t size);
    /**
     * @brief Finds mode of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T mode(const std::vector<T> &arr);
    /**
     * @brief Finds median of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T median(const T *arr, size_t size);
    /**
     * @brief Finds median of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T median(const std::vector<T> &arr);

    /**
     * @brief Computes variance of values in arr, each value same probability 
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T variance(const T *arr, size_t size);
    /**
     * @brief Computes variance of values in arr, each value same probability 
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T variance(const std::vector<T> &arr);
    /**
     * @brief Computes variance of values in arr, according to given probabilities
     * 
     * @param values Has to be aligned to 32 bytes
     * @param probabilities Has to be aligned to 32 bytes
     */
    template<typename T>
    T variance(const T *values, const T *probabilities, size_t size);
    /**
     * @brief Computes variance of values in arr, according to given probabilities
     * 
     * @param values values.data has to be aligned to 32 bytes
     * @param probabilities has to be at least as long as values
     * and probabilities.data has to be aligned to 32 bytes
     */
    template<typename T>
    T variance(const std::vector<T> &values, const std::vector<T> &probabilities);
    /**
     * @brief Computes sample variance of values in arr, each value same probability 
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T sample_variance(const T *arr, size_t size);
    /**
     * @brief Computes sample variance of values in arr, each value same probability 
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T sample_variance(const std::vector<T> &arr);
    /**
     * @brief Computes standard deviation of values in arr
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T std_deviation(const T *arr, size_t size);
    /**
     * @brief Computes standard deviation of values in arr
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T std_deviation(const std::vector<T> &arr);
    /**
     * @brief Computes std deviation of values in arr, according to given probabilities
     * 
     * @param values Has to be aligned to 32 bytes
     * @param probabilities Has to be aligned to 32 bytes
     */
    template<typename T>
    T std_deviation(const T *values, const T *probabilities, size_t size);
    /**
     * @brief Computes std deviation of values in arr, according to given probabilities
     * 
     * @param values values.data has to be aligned to 32 bytes
     * @param probabilities has to be at least as long as values
     * and probabilities.data has to be aligned to 32 bytes
     */
    template<typename T>
    T std_deviation(const std::vector<T> &values, const std::vector<T> &probabilities);

    /**
     * @brief Computes sample standard deviation of values in arr (with Bessels correction)
     * 
     * @param arr Has to be aligned to 32 bytes
     */
    template<typename T>
    T sample_std_deviation(const T *arr, size_t size);
    /**
     * @brief Computes sample standard deviation of values in arr (with Bessels correction)
     * 
     * @param arr arr.data has to be aligned to 32 bytes
     */
    template<typename T>
    T sample_std_deviation(const std::vector<T> &arr);
} // namespace mathops

#include <mathops/detail/statisticals.inl>

#endif // STATISTICALS_HPP