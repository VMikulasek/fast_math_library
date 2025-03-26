#ifndef SEQ_STATISTICALS_HPP
#define SEQ_STATISTICALS_HPP

#include <cstddef>

namespace mathops
{
namespace seq
{
    template<typename T>
    T min(const T *arr, size_t size);
    template<typename T>
    T max(const T *arr, size_t size);

    template<typename T>
    T arithmetic_mean(const T *arr, size_t size);
    template<typename T>
    T geometric_mean(const T *arr, size_t size);
    template<typename T>
    T weighted_mean(const T *values, const T *weights, size_t size);

    template<typename T>
    T mode(const T *arr, size_t size);
    template<typename T>
    T median(const T *arr, size_t size);

    template<typename T>
    T variance(const T *arr, size_t size);
    template<typename T>
    T variance(const T *arr, const T *probabilities, size_t size);
    template<typename T>
    T sample_variance(const T *arr, size_t size);
    template<typename T>
    T std_deviation(const T *arr, size_t size);
    template<typename T>
    T std_deviation(const T *arr, const T *probabilities, size_t size);
    template<typename T>
    T sample_std_deviation(const T *arr, size_t size);
} // namespace seq
} // namespace mathops

#include <mathops/detail/SEQ/seq_statisticals.inl>

#endif // SEQ_STATISTICALS_HPP