#ifndef UART_H
#define UART_H
#include <stdint.h>

constexpr uint16_t calcBaud(const uint32_t targetBaud){
    return F_CPU/(16*targetBaud) - 1;
}
//завести флаг с енамами для фич usart`a
//!Async no 2xSpeed
void usartInit(const uint32_t baud);
void putChar(const unsigned char c);
#endif