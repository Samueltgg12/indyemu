cmake_minimum_required(VERSION 3.16)

project(IndyEmu LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)

add_executable(indyemu
    src/main.cpp
    src/core/memory.cpp
    src/core/framebuffer.cpp
    src/core/graphics.cpp
    src/core/audio.cpp
    src/core/cpu/mips_cpu.cpp
    src/core/indy_hardware.cpp
    src/core/indy_system.cpp
    src/gfx/xl_graphics.cpp
    src/io/register_map.cpp
    src/io/hal2_audio.cpp
    src/io/ioc2.cpp
    src/system/rtc.cpp
)

target_include_directories(indyemu PRIVATE src)

add_executable(memory_endianness_test
    tests/memory_endianness_test.cpp
    src/core/memory.cpp
)

target_include_directories(memory_endianness_test PRIVATE src)

add_executable(cpu_jtype_test
    tests/cpu_jtype_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
)

target_include_directories(cpu_jtype_test PRIVATE src)

add_executable(cpu_branch_test
    tests/cpu_branch_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
)

target_include_directories(cpu_branch_test PRIVATE src)

add_executable(config_paths_test
    tests/config_paths_test.cpp
)

target_include_directories(config_paths_test PRIVATE src)

add_executable(cop0_test
    tests/cop0_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
)

target_include_directories(cop0_test PRIVATE src)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(indyemu_gui
    src/gui/main.cpp
    src/gui/main_window.cpp
)

target_include_directories(indyemu_gui PRIVATE src)
target_link_libraries(indyemu_gui PRIVATE Qt5::Widgets)
