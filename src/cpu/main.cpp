#include <iostream>

typedef unsigned int XLEN;

class CPU
{
    public:
        XLEN pc;

    private:
        const XLEN x0 = 0;
        XLEN x1;
        XLEN x2;
        XLEN x3;
        XLEN x4;
        XLEN x5;
        XLEN x6;
        XLEN x7;
        XLEN x8;
        XLEN x9;
        XLEN x10;
        XLEN x11;
        XLEN x12;
        XLEN x13;
        XLEN x14;
        XLEN x15;
        XLEN x16;
        XLEN x17;
        XLEN x18;
        XLEN x19;
        XLEN x20;
        XLEN x21;
        XLEN x22;
        XLEN x23;
        XLEN x24;
        XLEN x25;
        XLEN x26;
        XLEN x27;
        XLEN x28;
        XLEN x29;
        XLEN x30;
        XLEN x31;

    public:
        void Reset()
        {

        }
};

int main()
{
    CPU cpu;
    cpu.Reset();
}