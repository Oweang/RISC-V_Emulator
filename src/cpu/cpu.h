#pragma once

#include <iostream>
#include "ram.h"

#define NUM_REGISTER 32
#define RTYPE_SIZE 32

typedef unsigned int XLEN;
typedef unsigned char u8;
typedef unsigned int Word;

class CPU
{
    private:
        XLEN pc;
        XLEN regs[NUM_REGISTER];

        // Instruction types
        static constexpr u8 Rtype = 0b0110011;
        static constexpr u8 ItypeImm = 0b0010011;
        static constexpr u8 ItypeLd = 0b0000011;
        static constexpr u8 ItypeJ = 0b1100111;
        static constexpr u8 ItypeE = 0b1110011;

        // Rtype Instructions
        static constexpr u8 AddSubfunct3 = 0x0;
        static constexpr u8 ADD = 0x00;
        static constexpr u8 SUB = 0x20;

        static constexpr u8 XOR = 0x4;
        static constexpr u8 OR = 0x6;
        static constexpr u8 AND = 0x7;

        static constexpr u8 SHIFTLL = 0x1;

        static constexpr u8 ShiftRfunct3 = 0x5;
        static constexpr u8 SHIFTRL = 0x00;
        static constexpr u8 SHIFTRA = 0x20;

        static constexpr u8 SLT = 0x2;
        static constexpr u8 SLTU = 0x3;

        static constexpr u8 Itype = 0b0010011;

        // Itype Instructions
        // ItypeImm ins
        static constexpr u8 ADDI = 0x0;
        static constexpr u8 XORI = 0x4;
        static constexpr u8 ORI = 0x6;
        static constexpr u8 ANDI = 0x7;

        static constexpr u8 SLLI = 0x1;
        static constexpr u8 SLLIimm = 0x00;
        static constexpr u8 SRfunct3 = 0x5;
        static constexpr u8 SRLIimm = 0x00;
        static constexpr u8 SRAIimm = 0x20;






    public:
        void Reset(Mem& memory);

        Word FetchWord(Mem& memory);

        void ExecuteRType(Word Inst, Mem& memory);

        void ExecuteIType(Word Inst, Mem& memory, u8 Opcode);

        void ExecuteItypeImm(Word Inst, Mem& memory);

        void Execute(Mem& memory);

        unsigned int GetRegValue(int reg);

        bool SetRegValue(int reg, XLEN value);
};