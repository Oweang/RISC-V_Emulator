#include <stdlib.h>

#include "gtest/gtest.h"
#include <CPU/cpu.h>

class RISCV_EMU_Rtype : public testing::Test
{
    public:
        Mem ram;
        CPU cpu;

        virtual void SetUp()
        {
            cpu.Reset(ram);
        }

        virtual void TearDown()
        {
            cpu.Reset(ram);
        }
};

TEST_F( RISCV_EMU_Rtype, SimpleTest )
{
    cpu.SetRegValue(1, 5);
    cpu.SetRegValue(2, 8);
    ram.SetWord(0, 0x2081B3);
    cpu.Execute(ram);

    EXPECT_EQ(cpu.GetRegValue(3), 13);
}

class RISCV_EMU_Itype : public testing::Test
{
    public:
        Mem ram;
        CPU cpu;

        virtual void SetUp()
        {
            cpu.Reset(ram);
        }

        virtual void TearDown()
        {
            cpu.Reset(ram);
        }
};

TEST_F( RISCV_EMU_Itype, SimpleITypeTest )
{
    u8 randrs1 = rand() % 100;
    u8 randimm = rand() % 100;

    u8 opcode = 0b0010011;
    u8 rd = 0x2;
    u8 funct3 = 0x0;
    u8 rs1 = 0x1;
    u8 imm = randimm;

    Word inst = (opcode) |
                (rd << 7) |
                (funct3 << 12) |
                (rs1 << 15) |
                (imm << 20);

    cpu.SetRegValue(rs1, randrs1);
    ram.SetWord(0, inst);
    cpu.Execute(ram);

    EXPECT_EQ(cpu.GetRegValue(rd), randrs1 + randimm);
}