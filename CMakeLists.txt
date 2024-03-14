cmake_minimum_required(VERSION 3.22)
project(testAVR LANGUAGES C)

set(PROJECT_NAME testAVR)
set(CMAKE_C_COMPILER avr-gcc)
add_compile_options(-mmcu=atmega168 -DF_CPU=16000000UL -Os)
add_executable(${PROJECT_NAME} main.c)
