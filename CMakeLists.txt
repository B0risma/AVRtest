cmake_minimum_required(VERSION 3.22)
project(testAVR LANGUAGES C CXX)

set(PROJECT_NAME testAVR)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-c++)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-mmcu=atmega168 -DF_CPU=16000000UL -Os)
add_executable(${PROJECT_NAME} main.cpp uart.cpp)
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
COMMAND size ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.hex
)