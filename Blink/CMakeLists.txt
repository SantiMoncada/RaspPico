cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (Must be before project)
include(pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDAR 11)
set(CMAKE_CXX_STANDAR 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initilize the SDk
pico_sdk_init()

add_executable(blink blink.c)

target_link_libraries(blink pico_stdlib)

pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 0)

pico_add_extra_outputs(blink)
