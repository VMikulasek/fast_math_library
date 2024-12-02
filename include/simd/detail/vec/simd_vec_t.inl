#ifndef SIMDVECT_INL
#define SIMDVECT_INL

#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>

namespace simd
{
    template<size_t L, typename T>
    template<typename... Ts>
    inline Vec<L, T>::Vec(Ts... args) : data{args...}
    {
        static_assert((std::is_same_v<T, Ts> && ...), "All arguments must be of type T");
        static_assert(sizeof...(args) == L, "Number of arguments must match the templatesize L");
    }
    template<size_t L, typename T>
    inline Vec<L, T>::Vec() : data{}
    {}

    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator+(const Vec &other) const
    {
        return seq::addv(*this, other);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator-(const Vec<L, T> &other) const
    {
        return seq::subv(*this, other);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator*(const Vec<L, T> &other) const
    {
        return seq::mulv(*this, other);
    }
    template<size_t L, typename T>
    inline Vec<L, T> Vec<L, T>::operator/(const Vec<L, T> &other) const
    {
        return seq::divv(*this, other);
    }

    template<size_t L, typename T>
    inline T Vec<L, T>::dot(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        return seq::dotv(vec1, vec2);
    }
} // namespace simd

#endif // SIMDVECT_INL