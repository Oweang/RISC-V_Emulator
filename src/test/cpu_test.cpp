#include "gtest/gtest.h"
#include <CPU/cpu.h>

class RISCV_EMU : public testing::Test
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

TEST_F( RISCV_EMU, SimpleTest )
{
    cpu.SetRegValue(1, 5);
    cpu.SetRegValue(2, 8);
    ram.SetWord(0, 0x2081B3);
    cpu.Execute(ram);

    EXPECT_EQ(cpu.GetRegValue(3), 13);
}