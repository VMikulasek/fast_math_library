#ifndef TRANSCENDENTALS_INL
#define TRANSCENDENTALS_INL

#include <mathops/transcendentals.hpp>
#include <mathops/detail/VEC/vec_transcendentals.hpp>
#include <mathops/detail/SEQ/seq_transcendentals.hpp>
#include <common/detail/memory_common.inl>
#include <simd/simd_common.hpp>

#include <vector>
#include <cmath>
#include <numbers>
#include <stdexcept>
#include <type_traits>

namespace mathops
{
    template<typename T>
    inline T sqrt(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        return std::sqrt(num);
    }

    template<typename T>
    inline T fast_sqrt(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        if (num < 0)
        {
            return NAN;
        }

        num = fast_invsqrt(num);
        return 1 / num;
    }

    template<typename T>
    inline T invsqrt(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        return 1 / std::sqrt(num);
    }

    template<typename T>
    inline T fast_invsqrt(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        if (num < 0)
        {
            return NAN;
        }
        else if (num == 0)
        {
            return INFINITY;
        }
        
        T numHalf = 0.5f * num;
        int i = *(int *)&num;
        i = 0x5f375a86 - (i >> 1);
        num = *(T *)&i;
        num = num * (1.5f - numHalf * num * num);
        return num;
    }

    template<typename T>
    inline T sin(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        return std::sin(num);
    }
    template<typename T>
    inline T cos(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        return std::cos(num);
    }
    template<typename T>
    inline T tan(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        return std::sin(num) / std::cos(num);
    }
    template<typename T>
    inline T cot(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        return std::cos(num) / std::sin(num);
    }

    // source swiftshader
    template<typename T>
    inline T _sin5q(T x)
    {
        static_assert(std::is_floating_point_v<T>);

        T x2 = x * x;
        return x * (A + x2 * (B + x2 * C));
    }
    template<typename T>
    inline T fast_sin(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        T x_2 = 0.25f - num * pi2;
        T z = 0.25f - abs(x_2 - round(x_2));
        return _sin5q(z);
    }
    template<typename T>
    inline T fast_cos(T num)
    {
        static_assert(std::is_floating_point_v<T>);

        T x_2 = num * pi2;
        T z = 0.25f - abs(x_2 - round(x_2));
        return _sin5q(z);
    }

    template<typename T>
    inline T *fast_sqrt_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        if constexpr (std::is_same_v<T, float> && HAS_AVX && HAS_AVX2)
        {
            vec::fast_sqrt_arr<T, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(arr, size, dst);
        }
        else
        {
            seq::fast_sqrt_arr(arr, size, dst);
        }

        return dst;
    }

    template<typename T>
    inline T *fast_sqrt_arr(const std::vector<T> &arr)
    {
        return fast_sqrt_arr(arr.data(), arr.size());
    }

    template<typename T>
    inline T *fast_invsqrt_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        if constexpr (std::is_same_v<T, float> && HAS_AVX && HAS_AVX2)
        {
            vec::fast_invsqrt_arr<T, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(arr, size, dst);
        }
        else
        {
            seq::fast_invsqrt_arr(arr, size, dst);
        }

        return dst;
    }

    template<typename T>
    inline T *fast_invsqrt_arr(const std::vector<T> &arr)
    {
        return fast_invsqrt_arr(arr.data(), arr.size());
    }

    template<typename T>
    inline T *fast_sin_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            vec::fast_sin_arr<T, simd::InstructionSet::AVX>(arr, size, dst);
        }
        else
        {
            seq::fast_sqrt_arr(arr, size, dst);
        }

        return dst;
    }

    template<typename T>
    inline T *fast_sin_arr(const std::vector<T> &arr)
    {
        return fast_sin_arr(arr.data(), arr.size());
    }


    template<typename T>
    inline T *fast_cos_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        if constexpr (std::is_same_v<T, float> && HAS_AVX)
        {
            vec::fast_cos_arr<T, simd::InstructionSet::AVX>(arr, size, dst);
        }
        else
        {
            seq::fast_cos_arr(arr, size, dst);
        }

        return dst;
    }

    template<typename T>
    inline T *fast_cos_arr(const std::vector<T> &arr)
    {
        return fast_cos_arr(arr.data(), arr.size());
    }

    template<typename T>
    inline T *invsqrt_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        seq::invsqrt_arr(arr, size, dst);

        return dst;
    }

    template<typename T>
    inline T *invsqrt_arr(const std::vector<T> &arr)
    {
        return invsqrt_arr(arr.data(), arr.size());
    }

    template<typename T>
    inline T *sqrt_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        seq::sqrt_arr(arr, size, dst);

        return dst;
    }

    template<typename T>
    inline T *sqrt_arr(const std::vector<T> &arr)
    {
        return sqrt_arr(arr.data(), arr.size());
    }

    template<typename T>
    inline T *sin_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        seq::sin_arr(arr, size, dst);

        return dst;
    }

    template<typename T>
    inline T *sin_arr(const std::vector<T> &arr)
    {
        return sin_arr(arr.data(), arr.size());
    }

    template<typename T>
    inline T *cos_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        seq::cos_arr(arr, size, dst);

        return dst;
    }

    template<typename T>
    inline T *cos_arr(const std::vector<T> &arr)
    {
        return cos_arr(arr.data(), arr.size());
    }

    template<typename T>
    inline T *tan_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        seq::tan_arr(arr, size, dst);

        return dst;
    }

    template<typename T>
    inline T *tan_arr(const std::vector<T> &arr)
    {
        return tan_arr(arr.data(), arr.size());
    }

    template<typename T>
    inline T *cot_arr(const T *arr, size_t size)
    {
        static_assert(std::is_floating_point_v<T>);

        ALLOC_DST;

        seq::cot_arr(arr, size, dst);

        return dst;
    }

    template<typename T>
    inline T *cot_arr(const std::vector<T> &arr)
    {
        return cot_arr(arr.data(), arr.size());
    }
} // namespace mathops

#endif // TRANSCENDENTALS_INL