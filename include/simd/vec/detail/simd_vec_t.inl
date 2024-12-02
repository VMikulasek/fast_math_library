#ifndef SIMDVECT_INL
#define SIMDVECT_INL

#include <simd/vec/detail/simd_vec_t.hpp>

namespace simd
{
    template <size_t L, typename T>
    template<typename... Ts>
    Vec<L, T>::Vec(Ts... args) : data{args...}
    {
        static_assert((std::is_same_v<T, Ts> && ...), "All arguments must be of type T");
        static_assert(sizeof...(args) == L, "Number of arguments must match the template size L");
    }

    template <size_t L, typename T>
    Vec<L, T> Vec<L, T>::operator+(const Vec &other) const
    {
        Vec result;

        for(size_t i = 0; i < L; i++)
        {
            result.data[i] = this->data[i] + other.data[i];
        }
    }
    template <size_t L, typename T>
    Vec<L, T> Vec<L, T>::operator-(const Vec<L, T> &other) const
    {
        Vec result;

        for(size_t i = 0; i < L; i++)
        {
            result.data[i] = this->data[i] - other.data[i];
        }
    }
    template <size_t L, typename T>
    Vec<L, T> Vec<L, T>::operator*(const Vec<L, T> &other) const
    {
        Vec result;

        for(size_t i = 0; i < L; i++)
        {
            result.data[i] = this->data[i] * other.data[i];
        }
    }
    template <size_t L, typename T>
    Vec<L, T> Vec<L, T>::operator/(const Vec<L, T> &other) const
    {
        Vec result;

        for(size_t i = 0; i < L; i++)
        {
            result.data[i] = this->data[i] / other.data[i];
        }
    }

    template <size_t L, typename T>
    T Vec<L, T>::dot(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        T result;

        for(size_t i = 0; i < L; i++)
        {
            result += vec1.data[i] * vec2.data[i];
        }
    }
} // namespace simd

#endif // SIMDVECT_INL