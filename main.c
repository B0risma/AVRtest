#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <iom168pa.h>



void main(){
    DDRB = 1 << DDB5;
    while(1){
        PORTB ^= 1 << PORT5;
        _delay_ms(200);
        }
}