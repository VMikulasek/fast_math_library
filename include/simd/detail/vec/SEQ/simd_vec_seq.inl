#ifndef SIMDVECSEQ_INL
#define SIMDVECSEQ_INL

#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>
#include <mathops/transcedentals.hpp>

#include <cmath>

namespace simd
{
namespace seq
{
    template<size_t L, typename T>
    inline Vec<L, T> addv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        Vec<L, T> result;

        for(size_t i = 0; i < L; i++)
        {
            result.data[i] = vec1.data[i] + vec2.data[i];
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> subv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        Vec<L, T> result;

        for(size_t i = 0; i < L; i++)
        {
            result.data[i] = vec1.data[i] - vec2.data[i];
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> mulv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        Vec<L, T> result;

        for(size_t i = 0; i < L; i++)
        {
            result.data[i] = vec1.data[i] * vec2.data[i];
        }
        
        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> divv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        Vec<L, T> result;

        for(size_t i = 0; i < L; i++)
        {
            result.data[i] = vec1.data[i] / vec2.data[i];
        }
        
        return result;
    }

    template<size_t L, typename T>
    inline Vec<L, T> absv(const Vec<L, T> &vec)
    {
        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = std::abs(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> minv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = std::min(vec1.data[i], vec2.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> maxv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = std::max(vec1.data[i], vec2.data[i]);
        }

        return result;
    }

    template<size_t L, typename T>
    inline Vec<L, T> sqrtv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Square root only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::sqrt(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> fast_sqrtv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Fast square root only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::fast_sqrt(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> invsqrtv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Inverse square root only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::invsqrt(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> fast_invsqrtv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Fast inverse square root only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::fast_invsqrt(vec.data[i]);
        }

        return result;
    }

    template<size_t L, typename T>
    inline Vec<L, T> sinv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Sin only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::sin(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> cosv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Cos only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::cos(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> tanv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Tan only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::tan(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> cotv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Cot only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::cot(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> fast_sinv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Fast sin only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::fast_sin(vec.data[i]);
        }

        return result;
    }
    template<size_t L, typename T>
    inline Vec<L, T> fast_cosv(const Vec<L, T> &vec)
    {
        static_assert(std::is_floating_point_v<T>, "Fast cos only supported for floating point data types.");

        Vec<L, T> result;

        for (size_t i = 0; i < L; i++)
        {
            result.data[i] = mathops::fast_cos(vec.data[i]);
        }

        return result;
    }

    template<size_t L, typename T>
    inline T dotv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        T result = 0;

        for(size_t i = 0; i < L; i++)
        {
            result += vec1.data[i] * vec2.data[i];
        }

        return result;
    }
} // namespace seq
} // namespace simd

#endif // SIMDVECSEQ_INL