#include "uart.h"
#include <avr/io.h>
#include <stdint.h>

void usartInit(const uint32_t baud){
    UBRR0H = (uint8_t)calcBaud(baud) >> 8;
    UBRR0H = (uint8_t)calcBaud(baud);
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); //8bit frame
}
void putChar(const unsigned char c){
    if(c == '\n')
        putChar('\r');
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}