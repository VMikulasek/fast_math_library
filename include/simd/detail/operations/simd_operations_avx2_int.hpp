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
         * at least 8 ints long, also has to be aligned to 32 bits
         * otherwise segmentation fault will be generated
         * 
         * @return Register with loaded vector
         */
        static Avx2IReg load_vector(const int *arr);
    };
} // namespace simd

#endif // SIMD_OPERATIONS_AVX2_INT_HPP