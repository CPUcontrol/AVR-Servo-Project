#include <avr/io.h>

#include "analog.h"

void init_analog(){
    ADMUX  = (1<<REFS0);
    ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}
void start_analog(unsigned char pin){
    ADMUX   = (ADMUX & 0xF8) | (pin & 7); 
    ADCSRA |= (1<<ADSC);
}
unsigned short get_analog(){
    while( !(ADCSRA & (1<<ADIF)) );

    return ADC;
}
