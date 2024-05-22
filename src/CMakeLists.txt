add_library(
    RAM STATIC
    cpu/ram.h
    cpu/ram.cpp
)

add_library(
    CPU STATIC
    cpu/cpu.h
    cpu/cpu.cpp
)

target_link_libraries(CPU PRIVATE RAM)

target_include_directories(CPU PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")