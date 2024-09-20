#ifndef SIMD_OPERATIONS_AVX2_INT_HPP
#define SIMD_OPERATIONS_AVX2_INT_HPP

#include <simd/simd_common.hpp>
#include <simd/detail/operations/simd_operations_base.hpp>

#include <immintrin.h>

namespace simd
{
    template<>
    class SIMDOperations<int, InstructionSet::AVX2>
    {
    private:
        using NumType = int;
        static const InstructionSet INS_SET = InstructionSet::AVX2;

    public:
        using Avx2IReg = __m256i;

        /**
         * @brief Loads array of ints to register which is returned
         * 
         * @param arr Int array to load to register,
         * 8 ints will be loaded to register, so has to be
         * at least 8 ints long, also has to be aligned to 32 bytes
         * otherwise segmentation fault will be generated
         * 
         * @return Register with loaded vector
         */
        static Avx2IReg load_vector(const int *arr);

        /**
         * @brief Loads zeros to register which is returned
         * 
         * @return Register with zeros
         */
        static Avx2IReg set_register_zero();

        /**
         * @brief Sets every field of register to num
         */
        static Avx2IReg set_register(int num);

        /**
         * @brief Stores vector from register to int *dst
         * 
         * @param reg register to materialize
         * @param dst int * aligned to 32 bytes with at least 8 ints
         * of size
         */
        static void materialize_register(Avx2IReg &reg, int *dst);

        /**
         * @brief Adds vec2 to vec1 and returns result
         */
        static Avx2IReg add(Avx2IReg &vec1, Avx2IReg &vec2);

        /**
         * @brief Subtracts vec2 from vec1 and returns result
         */
        static Avx2IReg sub(Avx2IReg &vec1, Avx2IReg &vec2);

        /**
         * @brief Shift every int in reg left by count bits
         * while shifting in zeros
         * 
         * @param reg Register to shift
         * @param count Count of bits to shift, if more than 32,
         * then undefined behavior
         * @return Avx2IReg shifted result
         */
        static Avx2IReg shift_left(Avx2IReg &vec, int count);

        /**
         * @brief Shift every int in reg right by count bits
         * while shifting in zeros
         * 
         * @param reg Register to shift
         * @param count Count of bits to shift, if more than 32,
         * then undefined behavior
         * @return Avx2IReg Shifted result
         */
        static Avx2IReg shift_right(Avx2IReg &vec, int count);
    };
} // namespace simd

#include <simd/detail/operations/simd_operations_avx2_int.inl>

#endif // SIMD_OPERATIONS_AVX2_INT_HPP