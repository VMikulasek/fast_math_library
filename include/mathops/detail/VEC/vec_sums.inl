#ifndef VEC_SUMS_INL
#define VEC_SUMS_INL

#include <mathops/detail/VEC/vec_sums.hpp>
#include <mathops/detail/SEQ/seq_sums.hpp>
#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>

namespace mathops
{
namespace vec
{
    template<typename T, simd::InstructionSet S>
    inline typename simd::SIMDOperations<T, S>::Reg _load_reg(const T *&arr, size_t &size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        auto reg = Ops::load_vector(arr);
        arr += Ops::REG_SIZE;
        size -= Ops::REG_SIZE;
        return reg; 
    }

    template<typename T, simd::InstructionSet S>
    inline T sum(const T *arr, size_t size)
    {
        using Ops = simd::SIMDOperations<T, S>;

        if (size < Ops::REG_SIZE)
        {
            return seq::sum(arr, size);
        }

        typename Ops::Reg tmpResultReg = _load_reg<T, S>(arr, size);

        typename Ops::Reg secondOpReg;

        while (size >= Ops::REG_SIZE)
        {
            secondOpReg = _load_reg<T, S>(arr, size);
            tmpResultReg = Ops::add(tmpResultReg, secondOpReg);
        }

        T tailSum = seq::sum(arr, size);

        // merge all sums to the 0th and 4th indexes
        tmpResultReg = Ops::horizontal_add(tmpResultReg, tmpResultReg);
        tmpResultReg = Ops::horizontal_add(tmpResultReg, tmpResultReg);

        return Ops::materialize_register_at_index(tmpResultReg, 0)
             + Ops::materialize_register_at_index(tmpResultReg, 4)
             + tailSum;
    }

    template<typename T, simd::InstructionSet S>
    inline void prefix_sum(const T *arr, size_t size, T *dstArr)
    {
        using Ops = simd::SIMDOperations<T, S>;

        typename Ops::Reg zeroVec = Ops::set_register_zero();

        typename Ops::Reg lastElemOfCalculatedSequenceDistributed = Ops::set_register_zero();

        while (size >= Ops::REG_SIZE)
        {
            typename Ops::Reg res = _load_reg<T, S>(arr, size);

            // calculate prefix sum for halves isolated
            typename Ops::Reg shifted = Ops::rotate_halves_right_32bits(res);
            shifted = Ops::template blend<0b11101110>(zeroVec, shifted);
            res = Ops::add(res, shifted);
            shifted = Ops::rotate_halves_64bits(res);
            shifted = Ops::template blend<0b11001100>(zeroVec, shifted);
            res = Ops::add(res, shifted);

            // calculate prefix sum for whole register isolated
            typename Ops::Reg lastElemOfFirstHalf = Ops::template permute_reg_inside_halves<0b11111111>(res);
            lastElemOfFirstHalf = Ops::template blend<0b00001111>(zeroVec, lastElemOfFirstHalf);
            lastElemOfFirstHalf = Ops::swap_halves(lastElemOfFirstHalf);
            res = Ops::add(res, lastElemOfFirstHalf);

            // calculate prefix sum for whole register
            res = Ops::add(res, lastElemOfCalculatedSequenceDistributed);

            // update last elem distribution register
            lastElemOfCalculatedSequenceDistributed = Ops::template permute_reg_inside_halves<0b11111111>(res);
            lastElemOfCalculatedSequenceDistributed = Ops::distribute_high_half(lastElemOfCalculatedSequenceDistributed);

            Ops::materialize_register(res, dstArr);
            dstArr += Ops::REG_SIZE;
        }

        alignas(Ops::ALIGNMENT) T tmp[8];
        Ops::materialize_register(lastElemOfCalculatedSequenceDistributed, tmp);

        T lastElemOfCalculatedSequence = tmp[0];
        for (; size > 0; size--, arr++, dstArr++)
        {
            lastElemOfCalculatedSequence = *dstArr = *arr + lastElemOfCalculatedSequence;
        }
    }
} // namespace vec
} // namespace math

#endif // VEC_SUMS_INL