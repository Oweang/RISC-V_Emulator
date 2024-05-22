cmake_minimum_required(VERSION 3.0.0)
project(RISC-V_EMU VERSION 0.1.0 LANGUAGES C CXX)


add_subdirectory(src)
add_subdirectory(emu)

add_subdirectory(src/test)
