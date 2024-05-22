#pragma once

#include <unordered_map>

typedef unsigned int XLEN;
typedef unsigned int Word;
typedef unsigned int u32;
typedef unsigned char Byte;

class Mem
{
    private:
        static std::unordered_map<u32, Byte> RAM;

    public:
        void Reset();

        Word ReadWord(XLEN Address);
};