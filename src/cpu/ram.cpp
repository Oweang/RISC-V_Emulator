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
    buf = (RAM[Address] >> 24) |
            ((RAM[Address + 1] << 8) & 0x00FF0000) |
            ((RAM[Address + 2] >> 8) & 0x0000FF00) |
            (RAM[Address + 3] << 24);

    return buf;
}