#include <iostream>
#include <CPU/cpu.h>

int main()
{
    Mem memory;
    CPU cpu;
    std::cout << "test" << std::endl;
    cpu.Reset(memory);
    cpu.Execute(memory);
    std::cout << "finish" << std::endl;
}