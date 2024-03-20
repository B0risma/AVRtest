cmake_minimum_required(VERSION 3.22)
project(testAVR LANGUAGES C)

set(PROJECT_NAME testAVR)
set(CMAKE_C_COMPILER avr-gcc)
add_compile_options(-mmcu=atmega168 -DF_CPU=16000000UL -Os)
add_executable(${PROJECT_NAME} main.c)
target_include_directories(testAVR 
    PUBLIC /lib/avr/include
    PUBLIC /lib/avr/include/avr
    PUBLIC /lib/avr/include/util
    PUBLIC /lib/avr/include/sys
    PUBLIC /lib/avr/include/compat) 
