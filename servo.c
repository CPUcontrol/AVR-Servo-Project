#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

#include "servo.h"
#include "servo_conf.h"

static volatile unsigned short servopos[20] = {
	4000,4000,4000,4000,4000,
	4000,4000,4000,4000,4000,
	4000,4000,4000,4000,4000,
	4000,4000,4000,4000,4000
};
static volatile unsigned char cur_servo = 0;

void init_servo(void){
	unsigned char ddr_B = 0;
	unsigned char ddr_C = 0;
	unsigned char ddr_D = 0;

#define SERVO_DAT(port, bit) ddr_##port |= 1 << bit
#ifdef SERVO_0
	SERVO_0;
#endif
#ifdef SERVO_1
	SERVO_1;
#endif
#ifdef SERVO_2
	SERVO_2;
#endif
#ifdef SERVO_3
	SERVO_3;
#endif
#ifdef SERVO_4
	SERVO_4;
#endif
#ifdef SERVO_5
	SERVO_5;
#endif
#ifdef SERVO_6
	SERVO_6;
#endif
#ifdef SERVO_7
	SERVO_7;
#endif
#ifdef SERVO_8
	SERVO_8;
#endif
#ifdef SERVO_9
	SERVO_9;
#endif
#ifdef SERVO_10
	SERVO_10;
#endif
#ifdef SERVO_11
	SERVO_11;
#endif
#ifdef SERVO_12
	SERVO_12;
#endif
#ifdef SERVO_13
	SERVO_13;
#endif
#ifdef SERVO_14
	SERVO_14;
#endif
#ifdef SERVO_15
	SERVO_15;
#endif
#ifdef SERVO_16
	SERVO_16;
#endif
#ifdef SERVO_17
	SERVO_17;
#endif
#ifdef SERVO_18
	SERVO_18;
#endif
#ifdef SERVO_19
	SERVO_19;
#endif
#undef SERVO_DAT
	DDRB |= ddr_B;
	DDRC |= ddr_C;
	DDRD |= ddr_D;

	TCCR1B |= (1<<WGM12);

	OCR1A = 8000-1;
	TIMSK1 |= (1<<OCIE1A);
	TIMSK1 |= (1<<OCIE1B);
	//Clock divisor set to 1
	TCCR1B |= (1<<CS10);
}

void set_servo(unsigned char id, unsigned short val){
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
		servopos[id] = val;
	}
}


//Fires once every 1 ms to start a pulse
ISR (TIMER1_COMPA_vect){
	unsigned char idx = cur_servo;
	//Time after 1 ms to turn off
	OCR1B = servopos[idx];
#define SERVO_DAT(port, bit) PORT##port |= 1 << bit
	switch(idx){
	case  0:
#ifdef SERVO_1
		SERVO_1;
#endif
		break;

	case  1:
#ifdef SERVO_2
		SERVO_2;
#endif
		break;

	case  2:
#ifdef SERVO_3
		SERVO_3;
#endif
		break;

	case  3:
#ifdef SERVO_4
		SERVO_4;
#endif
		break;

	case  4:
#ifdef SERVO_5
		SERVO_5;
#endif
		break;

	case  5:
#ifdef SERVO_6
		SERVO_6;
#endif
		break;

	case  6:
#ifdef SERVO_7
		SERVO_7;
#endif
		break;

	case  7:
#ifdef SERVO_8
		SERVO_8;
#endif
		break;

	case  8:
#ifdef SERVO_9
		SERVO_9;
#endif
		break;

	case  9:
#ifdef SERVO_10
		SERVO_10;
#endif
		break;

	case 10:
#ifdef SERVO_11
		SERVO_11;
#endif
		break;

	case 11:
#ifdef SERVO_12
		SERVO_12;
#endif
		break;

	case 12:
#ifdef SERVO_13
		SERVO_13;
#endif
		break;

	case 13:
#ifdef SERVO_14
		SERVO_14;
#endif
		break;

	case 14:
#ifdef SERVO_15
		SERVO_15;
#endif
		break;

	case 15:
#ifdef SERVO_16
		SERVO_16;
#endif
		break;

	case 16:
#ifdef SERVO_17
		SERVO_17;
#endif
		break;

	case 17:
#ifdef SERVO_18
		SERVO_18;
#endif
		break;

	case 18:
#ifdef SERVO_19
		SERVO_19;
#endif
		break;

	case 19:
#ifdef SERVO_0
		SERVO_0;
#endif
		break;

	}
#undef SERVO_DAT
	//Advance to next servo
	cur_servo = idx+1 < 20 ? idx+1 : 0;
}
//Fires when the previous servo pulse is to end
ISR (TIMER1_COMPB_vect){
	unsigned char idx = cur_servo;

#define SERVO_DAT(port, bit) PORT##port &= ~(1 << bit)
	switch(idx){
	case  0:
#ifdef SERVO_19
		SERVO_19;
#endif
		break;

	case  1:
#ifdef SERVO_0
		SERVO_0;
#endif
		break;

	case  2:
#ifdef SERVO_1
		SERVO_1;
#endif
		break;

	case  3:
#ifdef SERVO_2
		SERVO_2;
#endif
		break;

	case  4:
#ifdef SERVO_3
		SERVO_3;
#endif
		break;

	case  5:
#ifdef SERVO_4
		SERVO_4;
#endif
		break;

	case  6:
#ifdef SERVO_5
		SERVO_5;
#endif
		break;

	case  7:
#ifdef SERVO_6
		SERVO_6;
#endif
		break;

	case  8:
#ifdef SERVO_7
		SERVO_7;
#endif
		break;

	case  9:
#ifdef SERVO_8
		SERVO_8;
#endif
		break;

	case 10:
#ifdef SERVO_9
		SERVO_9;
#endif
		break;

	case 11:
#ifdef SERVO_10
		SERVO_10;
#endif
		break;

	case 12:
#ifdef SERVO_11
		SERVO_11;
#endif
		break;

	case 13:
#ifdef SERVO_12
		SERVO_12;
#endif
		break;

	case 14:
#ifdef SERVO_13
		SERVO_13;
#endif
		break;

	case 15:
#ifdef SERVO_14
		SERVO_14;
#endif
		break;

	case 16:
#ifdef SERVO_15
		SERVO_15;
#endif
		break;

	case 17:
#ifdef SERVO_16
		SERVO_16;
#endif
		break;

	case 18:
#ifdef SERVO_17
		SERVO_17;
#endif
		break;

	case 19:
#ifdef SERVO_18
		SERVO_18;
#endif
		break;
	}
#undef SERVO_DAT
}
