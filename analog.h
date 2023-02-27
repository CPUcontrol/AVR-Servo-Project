#pragma once
#ifdef __cplusplus
extern "C" {
#endif

void init_analog();
void start_analog(unsigned char pin);
unsigned short get_analog();

#define read_analog(pin) (start_analog(pin), get_analog())

#ifdef __cplusplus
}
#endif
