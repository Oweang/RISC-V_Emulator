#include "ram.h"

std::unordered_map<u32, Byte> Mem::RAM;

void Mem::Reset()
{
    RAM.clear();

    RAM[0] = 0b10110011;
    RAM[1] = 0b10000001;
    RAM[2] = 0b00100000;
    RAM[3] = 0b00000000;
}

Word Mem::ReadWord(XLEN Address)
{
    Word buf;
    buf = 0;
    buf =   ((Word) RAM[Address]);
    buf |=  ((Word) RAM[Address + 1] << 8);
    buf |=  ((Word) RAM[Address + 2] << 16);
    buf |=  ((Word) RAM[Address + 3] << 24);

    return buf;
}

bool Mem::SetWord(XLEN Address, Word value)
{
    // verify address is correct

    RAM[Address] = value & 0xFF;
    RAM[Address + 1] = (value & 0xFF00) >> 8;
    RAM[Address + 2] = (value & 0xFF0000) >> 16;
    RAM[Address + 3] = (value & 0xFF000000) >> 24;

    return true;
}