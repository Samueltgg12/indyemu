cmake_minimum_required(VERSION 3.16)

project(IndyEmu LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)

# Fetch toml++ for TOML configuration parsing
include(FetchContent)
FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(tomlplusplus)

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
    src/io/hal2_audio.cpp
    src/io/ioc2.cpp
    src/io/serial.cpp
    src/io/system_controller.cpp
    src/system/rtc.cpp
    src/system/timer.cpp
    src/system/interrupt_controller.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
    src/system/memory_controller.cpp
)

target_include_directories(indyemu PRIVATE src)
target_link_libraries(indyemu PRIVATE tomlplusplus)

add_executable(memory_endianness_test
    tests/memory_endianness_test.cpp
    src/core/memory.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(memory_endianness_test PRIVATE src)

add_executable(cpu_jtype_test
    tests/cpu_jtype_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(cpu_jtype_test PRIVATE src)

add_executable(cpu_branch_test
    tests/cpu_branch_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(cpu_branch_test PRIVATE src)

add_executable(mips_iii_branch_likely_test
    tests/mips_iii_branch_likely_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(mips_iii_branch_likely_test PRIVATE src)

add_executable(cpu_mul_test
    tests/cpu_mul_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(cpu_mul_test PRIVATE src)

add_executable(register_io_map_test
    tests/register_io_map_test.cpp
    src/core/memory.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(register_io_map_test PRIVATE src)

add_executable(memory_map_test
    tests/memory_map_test.cpp
    src/core/memory.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(memory_map_test PRIVATE src)

add_executable(config_paths_test
    tests/config_paths_test.cpp
)

target_include_directories(config_paths_test PRIVATE src)

add_executable(cpu_cop1_test
    tests/cpu_cop1_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(cpu_cop1_test PRIVATE src)

add_executable(cop0_test
    tests/cop0_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(cop0_test PRIVATE src)

add_executable(cpu_r4400_test
    tests/cpu_r4400_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
    src/io/register_map.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
)

target_include_directories(cpu_r4400_test PRIVATE src)

add_executable(prom_reset_vector_test
    tests/prom_reset_vector_test.cpp
    src/core/memory.cpp
    src/core/cpu/mips_cpu.cpp
    src/core/indy_system.cpp
    src/core/audio.cpp
    src/core/framebuffer.cpp
    src/core/graphics.cpp
    src/gfx/xl_graphics.cpp
    src/io/register_map.cpp
    src/io/hal2_audio.cpp
    src/io/ioc2.cpp
    src/io/serial.cpp
    src/io/system_controller.cpp
    src/system/rtc.cpp
    src/system/timer.cpp
    src/system/interrupt_controller.cpp
    src/system/gio64_bus.cpp
    src/system/rex3.cpp
    src/system/memory_controller.cpp
)

target_include_directories(prom_reset_vector_test PRIVATE src)

add_test(NAME cpu_r4400_test COMMAND cpu_r4400_test)
add_test(NAME prom_reset_vector_test COMMAND prom_reset_vector_test)

add_executable(hardware_shell_test
    tests/hardware_shell_test.cpp
    src/io/register_map.cpp
    src/io/serial.cpp
    src/io/system_controller.cpp
    src/system/timer.cpp
    src/system/interrupt_controller.cpp
)

target_include_directories(hardware_shell_test PRIVATE src)

add_test(NAME memory_endianness_test COMMAND memory_endianness_test)
add_test(NAME cpu_jtype_test COMMAND cpu_jtype_test)
add_test(NAME cpu_branch_test COMMAND cpu_branch_test)
add_test(NAME mips_iii_branch_likely_test COMMAND mips_iii_branch_likely_test)
add_test(NAME cpu_mul_test COMMAND cpu_mul_test)
add_test(NAME register_io_map_test COMMAND register_io_map_test)
add_test(NAME memory_map_test COMMAND memory_map_test)
add_test(NAME cpu_cop1_test COMMAND cpu_cop1_test)
add_test(NAME cop0_test COMMAND cop0_test)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(indyemu_gui
    src/gui/main.cpp
    src/gui/main_window.cpp
)

target_include_directories(indyemu_gui PRIVATE src)
target_link_libraries(indyemu_gui PRIVATE Qt5::Widgets)