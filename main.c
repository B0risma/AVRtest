#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/iom168pa.h>
#include <avr/interrupt.h>


ISR(INT1_vect){
    _delay_ms(10);
}

ISR(TIMER0_OVF_vect){
    TCNT0 = 0;
}

void main(){
    DDRB = 1 << DDB5;
    while(1){
        PORTB ^= 1 << PORT5;
        _delay_ms(200);
        }
}