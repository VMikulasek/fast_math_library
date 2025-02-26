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
    inline float min(const float *arr, size_t size)
    {
        float min = arr[0];

        for (size_t i = 1; i < size; i++)
        {
            min = std::min(min, arr[i]);
        }

        return min;
    }

    inline float max(const float *arr, size_t size)
    {
        float max = arr[0];

        for (size_t i = 1; i < size; i++)
        {
            max = std::max(max, arr[i]);
        }

        return max;
    }

    inline float arithmetic_mean(const float *arr, size_t size)
    {
        if (size == 0) return 0;

        float sum = std::accumulate(arr, arr + size, 0.f);
        return sum / size;
    }

    inline float geometric_mean(const float *arr, size_t size)
    {
        if (size == 0) return 0;

        float product = arr[0];

        for (size_t i = 1; i < size; i++)
        {
            product *= arr[i];
        }

        return std::pow(product, 1.f / size);
    }

    inline float weighted_mean(const float *values, const float *weights, size_t size)
    {
        if (size == 0) return 0;

        float sum = values[0] * weights[0];
        float weightSum = weights[0];

        for (size_t i = 1; i < size; i++)
        {
            sum += values[i] * weights[i];
            weightSum += weights[i];
        }

        return sum / weightSum;
    }

    inline int mode(const int *arr, size_t size)
    {
        std::unordered_map<int, int> frequencyMap;

        for (size_t i = 0; i < size; i++)
        {
            frequencyMap[arr[i]]++;
        }

        int mode = 0;
        int maxCount = 0;

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

    inline float median(const float *arr, size_t size)
    {
        float *tmp = new float[size];
        std::copy(arr, arr + size, tmp);
        std::sort(tmp, tmp + size);
    
        float median;
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

    inline float median(const int *arr, size_t size)
    {
        int *tmp = new int[size];
        std::copy(arr, arr + size, tmp);
        std::sort(tmp, tmp + size);
    
        float median;
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

    inline float variance(const float *arr, size_t size)
    {
        float mean = arithmetic_mean(arr, size);

        float variance = 0;
        for (size_t i = 0; i < size; i++)
        {
            variance += std::pow(arr[i] - mean, 2);
        }

        return variance / size;
    }
    
    inline float variance(const float *arr, const float *probabilities, size_t size)
    {
        float mean = weighted_mean(arr, probabilities, size);

        float variance = 0;
        for (size_t i = 0; i < size; i++)
        {
            variance += std::pow(arr[i] - mean, 2) * probabilities[i];
        }

        return variance;
    }

    inline float std_deviation(const float *arr, size_t size)
    {
        return std::sqrt(variance(arr, size));
    }

    inline float sample_std_deviation(const float *arr, size_t size)
    {
        float mean = arithmetic_mean(arr, size);

        float variance = 0;
        for (size_t i = 0; i < size; i++)
        {
            variance += std::pow(arr[i] - mean, 2);
        }

        return std::sqrt(variance / (size - 1));
    }
} // namespace seq
} // namespace mathops

#endif // SEQ_STATISTICALS_INL