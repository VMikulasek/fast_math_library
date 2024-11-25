#ifndef SIMDVECT_HPP

#include <type_traits>
#include <cstddef>
#include <array>

namespace simd
{
    template <size_t L, typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    class Vec
    {
    public:
        std::array<T, L> data;

        Vec(T... args);

        Vec operator+(const Vec &other) const;
        Vec operator-(const Vec &other) const;
        Vec operator*(const Vec &other) const;
        Vec operator/(const Vec &other) const;
        T dot(const Vec &vec1, const Vec &vec2);

    private:
        Vec() = default;
    };
} // namespace simd

#include <simd/vec/detail/simd_vec_t.inl>

#endif // SIMDVECT_HPP