#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/iom168pa.h>
#include <avr/interrupt.h>

#include "uart.h"

//do echo with parsing json


int main(){
    usartInit(9600);
    DDRB = 1 << DDB5;
    while(1){
        PORTB ^= 1 << PORT5;
        _delay_ms(200);
        putChar('t');
        putChar('e');
        putChar('s');
        putChar('t');
        }
}