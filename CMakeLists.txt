cmake_minimum_required(VERSION 3.22)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CROSS_COMPILING 1)
project(testAVR LANGUAGES C CXX ASM)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_CXX_STANDARD 11)
add_definitions(-DF_CPU=16000000UL)
add_compile_options(-mmcu=atmega168p -Os)
add_link_options(-mmcu=atmega168p)
add_executable(${PROJECT_NAME} main.cpp 
uart.cpp)
target_include_directories(testAVR 
    PUBLIC /lib/avr/include
    PUBLIC /lib/avr/include/avr
    PUBLIC /lib/avr/include/util
    PUBLIC /lib/avr/include/sys
    PUBLIC /lib/avr/include/compat) 

add_custom_target(generateHex
DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
COMMAND ${CMAKE_COMMAND} -E echo Generating HEX...
COMMAND avr-objcopy -j .text -j .data -O ihex 
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.hex
COMMAND avr-size --format=avr --mcu=atmega168p  ${PROJECT_NAME}
COMMAND ${CMAKE_COMMAND} -E rename ${PROJECT_NAME} ${PROJECT_NAME}.elf 
)