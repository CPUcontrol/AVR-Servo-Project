#include <avr/interrupt.h>
#include <util/delay.h>

#include "analog.h"
#include "servo.h"

int main(void) {
	init_analog();
    init_servo();
    sei();
    for(;;){
		/*
		for(unsigned short i = 100; i < 7900; i+=100){
			for(unsigned char j = 0; j < 20; j++){
				set_servo(j, i);
			}
			_delay_ms(25);

		}
		for(unsigned short i = 100; i < 7900; i+=100){
			for(unsigned char j = 0; j < 20; j++){
				set_servo(j, 7999-i);
			}
			_delay_ms(25);
		}
		*/
		unsigned short a = read_analog(5);

		set_servo(10, 100 + 6*a);
	}
}
