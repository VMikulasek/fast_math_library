#ifndef SEQ_STATISTICALS_INL
#define SEQ_STATISTICALS_INL

#include <mathops/detail/SEQ/seq_statisticals.hpp>

#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <cstddef>

namespace mathops
{
namespace seq
{
    template<typename T>
    inline T min(const T *arr, size_t size)
    {
        T min = arr[0];

        for (size_t i = 1; i < size; i++)
        {
            min = std::min(min, arr[i]);
        }

        return min;
    }

    template<typename T>
    inline T max(const T *arr, size_t size)
    {
        T max = arr[0];

        for (size_t i = 1; i < size; i++)
        {
            max = std::max(max, arr[i]);
        }

        return max;
    }

    template<typename T>
    inline T arithmetic_mean(const T *arr, size_t size)
    {
        if (size == 0) return 0;

        T sum = std::accumulate(arr, arr + size, 0.f);
        return sum / size;
    }

    template<typename T>
    inline T geometric_mean(const T *arr, size_t size)
    {
        if (size == 0) return 0;

        T product = arr[0];

        for (size_t i = 1; i < size; i++)
        {
            product *= arr[i];
        }

        return std::pow(product, 1.f / size);
    }

    template<typename T>
    inline T weighted_mean(const T *values, const T *weights, size_t size)
    {
        if (size == 0) return 0;

        T sum = values[0] * weights[0];
        T weightSum = weights[0];

        for (size_t i = 1; i < size; i++)
        {
            sum += values[i] * weights[i];
            weightSum += weights[i];
        }

        if (weightSum == 0) return 0.f;

        return sum / weightSum;
    }

    template<typename T>
    inline T mode(const T *arr, size_t size)
    {
        std::unordered_map<T, T> frequencyMap;

        for (size_t i = 0; i < size; i++)
        {
            frequencyMap[arr[i]]++;
        }

        T mode = 0;
        T maxCount = 0;

        for (const auto &pair : frequencyMap)
        {
            if (pair.second > maxCount)
            {
                maxCount = pair.second;
                mode = pair.first;
            }
        }

        return mode;
    }

    template<typename T>
    inline T median(const T *arr, size_t size)
    {
        T *tmp = new T[size];
        std::copy(arr, arr + size, tmp);
        std::sort(tmp, tmp + size);
    
        T median;
        if (size % 2 == 1)
        {
            median = tmp[size / 2];
        }
        else
        {
            median = (tmp[size / 2 - 1] + tmp[size / 2]) / 2.0;
        }
    
        delete[] tmp;
        return median;
    }

    template<typename T>
    inline T variance(const T *arr, size_t size)
    {
        if (size == 0) return 0.f;

        T mean = 0.f;
        T variance = 0.f;
        for (size_t i = 0; i < size; i++)
        {
            mean += arr[i];
            variance += std::pow(arr[i], 2);
        }

        return (variance / size) - std::pow(mean / size, 2);
    }
    
    template<typename T>
    inline T variance(const T *arr, const T *probabilities, size_t size)
    {
        T mean = 0.f;
        T variance = 0.f;
        for (size_t i = 0; i < size; i++)
        {
            mean += arr[i] * probabilities[i];
            variance += std::pow(arr[i], 2) * probabilities[i];
        }

        return variance - std::pow(mean, 2);
    }

    template<typename T>
    inline T sample_variance(const T *arr, size_t size)
    {
        if (size <= 1) return 0.f;

        T mean = 0.f;
        T variance = 0;
        for (size_t i = 0; i < size; i++)
        {
            mean += arr[i];
            variance += std::pow(arr[i], 2);
        }

        return (variance - (std::pow(mean, 2) / size)) / (size - 1);
    }

    template<typename T>
    inline T std_deviation(const T *arr, size_t size)
    {
        return std::sqrt(variance(arr, size));
    }

    template<typename T>
    T std_deviation(const T *arr, const T *probabilities, size_t size)
    {
        return std::sqrt(variance(arr, probabilities, size));
    }

    template<typename T>
    inline T sample_std_deviation(const T *arr, size_t size)
    {
        return std::sqrt(sample_variance(arr, size));
    }
} // namespace seq
} // namespace mathops

#endif // SEQ_STATISTICALS_INL