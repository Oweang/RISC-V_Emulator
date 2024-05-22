#include "cpu.h"

void CPU::Reset(Mem& memory)
{
    pc = 0;
    
    for (int i = 0; i < NUM_REGISTER; i++)
    {
        regs[i] = 0;
    }

    memory.Reset();
}

Word CPU::FetchWord(Mem& memory)
{
    return memory.ReadWord(pc);
}

void CPU::ExecuteRType(Word Inst, Mem& memory)
{
    u8 rd       = (Inst >> 7) & 0b11111;
    u8 funct3   = (Inst >> 12) & 0b111;
    u8 rs1      = (Inst >> 15) & 0b11111;
    u8 rs2      = (Inst >> 20) & 0b11111;
    u8 funct7   = (Inst >> 25) & 0b1111111;

    switch (funct3)
    {
        case AddSubfunct3:
        {
            switch (funct7) 
            {
                case ADD:
                {
                    regs[rd] = regs[rs1] + regs[rs2];
                } break;

                case SUB:
                {
                    regs[rd] = regs[rs1] - regs[rs2];
                } break;

                default:
                {
                    std::cout << "unknown instruction" << std::endl;
                }
            }
        } break;

        case XOR:
        {
            regs[rd] = regs[rs1] ^ regs[rs2];
        } break;

        case OR:
        {
            regs[rd] = regs[rs1] | regs[rs2];
        } break;

        case AND:
        {
            regs[rd] = regs[rs1] & regs[rs2];
        } break;

        case SHIFTLL:
        {
            regs[rd] = regs[rs1] << regs[rs2];
        } break;

        case ShiftRfunct3:
        {
            switch (funct7)
            {
                case SHIFTRL:
                {
                    regs[rd] = regs[rs1] >> regs[rs2];
                } break;

                case SHIFTRA:
                {
                    regs[rd] = ((signed int) regs[rs1]) >> regs[rs2];
                } break;

                default:
                {
                    std::cout << "unknown instruction" << std::endl;
                }
            }
        } break;

        case SLT:
        {
            regs[rd] = ((signed int) regs[rs1] < (signed int) regs[rs2]) ? 1:0;
        } break;

        case SLTU:
        {
            regs[rd] = (regs[rs1] < regs[rs2]) ? 1:0;
        } break;

        default:
        {
            std::cout << "unknown instruction" << std::endl;
        }
    }

    pc += RTYPE_SIZE;
}

void CPU::Execute(Mem& memory)
{
    Word Inst = FetchWord(memory);
    u8 Opcode = Inst & 0b111111;

    switch (Opcode)
    {
        case Rtype:
        {
            ExecuteRType(Inst, memory);
        } break;

        default:
        {
            std::cout << "unknown instruction" << std::endl;
        }
    }
}