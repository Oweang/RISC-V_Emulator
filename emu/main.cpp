#include <iostream>
#include <CPU/cpu.h>

// #define NUM_REGISTER 32

// #define RTYPE_SIZE 32

// typedef unsigned int XLEN;
// typedef unsigned char Byte;
// typedef unsigned int Word;
// typedef unsigned int u32;
// typedef unsigned long long u64;
// typedef unsigned char u8;

// class Mem
// {
//     private:
//         static std::unordered_map<u32, Byte> RAM;

//     public:
//         void Reset()
//         {
//             RAM.clear();

//             RAM[0] = 0b10110011;
//             RAM[1] = 0b10000001;
//             RAM[2] = 0b00100000;
//             RAM[3] = 0b00000000;
//         }

//         Word ReadWord(XLEN Address)
//         {
//             Word buf;
//             buf = (RAM[Address] >> 24) |
//                   ((RAM[Address + 1] << 8) & 0x00FF0000) |
//                   ((RAM[Address + 2] >> 8) & 0x0000FF00) |
//                   (RAM[Address + 3] << 24);

//             return buf;
//         }
// };

// class CPU
// {
//     private:
//         XLEN pc;
//         XLEN regs[NUM_REGISTER];

//         static constexpr u8 Rtype = 0b0110011;

//         static constexpr u8 AddSubfunct3 = 0x0;
//         static constexpr u8 ADD = 0x00;
//         static constexpr u8 SUB = 0x20;

//         static constexpr u8 XOR = 0x4;
//         static constexpr u8 OR = 0x6;
//         static constexpr u8 AND = 0x7;

//         static constexpr u8 SHIFTLL = 0x1;

//         static constexpr u8 ShiftRfunct3 = 0x5;
//         static constexpr u8 SHIFTRL = 0x00;
//         static constexpr u8 SHIFTRA = 0x20;

//         static constexpr u8 SLT = 0x2;
//         static constexpr u8 SLTU = 0x3;

//         static constexpr u8 Itype = 0b0010011;


//     public:
//         void Reset(Mem& memory)
//         {
//             pc = 0;
            
//             for (int i = 0; i < NUM_REGISTER; i++)
//             {
//                 regs[i] = 0;
//             }

//             memory.Reset();
//         }

//         Word FetchWord(Mem& memory)
//         {
//             return memory.ReadWord(pc);
//         }

//         void ExecuteRType(Word Inst, Mem& memory)
//         {
//             u8 rd       = (Inst >> 7) & 0b11111;
//             u8 funct3   = (Inst >> 12) & 0b111;
//             u8 rs1      = (Inst >> 15) & 0b11111;
//             u8 rs2      = (Inst >> 20) & 0b11111;
//             u8 funct7   = (Inst >> 25) & 0b1111111;

//             switch (funct3)
//             {
//                 case AddSubfunct3:
//                 {
//                     switch (funct7) 
//                     {
//                         case ADD:
//                         {
//                             regs[rd] = regs[rs1] + regs[rs2];
//                         } break;

//                         case SUB:
//                         {
//                             regs[rd] = regs[rs1] - regs[rs2];
//                         } break;

//                         default:
//                         {
//                             std::cout << "unknown instruction" << std::endl;
//                         }
//                     }
//                 } break;

//                 case XOR:
//                 {
//                     regs[rd] = regs[rs1] ^ regs[rs2];
//                 } break;

//                 case OR:
//                 {
//                     regs[rd] = regs[rs1] | regs[rs2];
//                 } break;

//                 case AND:
//                 {
//                     regs[rd] = regs[rs1] & regs[rs2];
//                 } break;

//                 case SHIFTLL:
//                 {
//                     regs[rd] = regs[rs1] << regs[rs2];
//                 } break;

//                 case ShiftRfunct3:
//                 {
//                     switch (funct7)
//                     {
//                         case SHIFTRL:
//                         {
//                             regs[rd] = regs[rs1] >> regs[rs2];
//                         } break;

//                         case SHIFTRA:
//                         {
//                             regs[rd] = ((signed int) regs[rs1]) >> regs[rs2];
//                         } break;

//                         default:
//                         {
//                             std::cout << "unknown instruction" << std::endl;
//                         }
//                     }
//                 } break;

//                 case SLT:
//                 {
//                     regs[rd] = ((signed int) regs[rs1] < (signed int) regs[rs2]) ? 1:0;
//                 } break;

//                 case SLTU:
//                 {
//                     regs[rd] = (regs[rs1] < regs[rs2]) ? 1:0;
//                 } break;

//                 default:
//                 {
//                     std::cout << "unknown instruction" << std::endl;
//                 }
//             }

//             pc += RTYPE_SIZE;
//         }

//         void Execute(Mem& memory)
//         {
//             Word Inst = FetchWord(memory);
//             u8 Opcode = Inst & 0b111111;

//             switch (Opcode)
//             {
//                 case Rtype:
//                 {
//                     ExecuteRType(Inst, memory);
//                 } break;

//                 default:
//                 {
//                     std::cout << "unknown instruction" << std::endl;
//                 }
//             }
//         }
// };

int main()
{
    Mem memory;
    CPU cpu;
    std::cout << "test" << std::endl;
    cpu.Reset(memory);
    cpu.Execute(memory);
    std::cout << "finish" << std::endl;
}