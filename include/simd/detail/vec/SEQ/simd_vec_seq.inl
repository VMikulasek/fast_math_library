#ifndef SIMDVECSEQ_INL
#define SIMDVECSEQ_INL

#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>

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