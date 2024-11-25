#ifndef SIMDVECT_INL

#include <simd/vec/detail/simd_vec_t.hpp>

namespace simd
{
    template <size_t L, typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Vec<L, T>::Vec(T... args) : data{args...}
    {
        static_assert(sizeof...(args) == L, "Number of arguments must match the template size L");
    }

    template <size_t L, typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Vec<L, T> Vec<L, T>::operator+(const Vec &other)
    {
        Vec result;
        for(size_t i = 0; i < L; i++)
        {
            Vec.data[i] = this->data[i] + other.data[i];
        }
    }
} // namespace simd

#endif // SIMDVECT_INL