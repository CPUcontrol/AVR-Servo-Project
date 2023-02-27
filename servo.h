#pragma once
#ifdef __cplusplus
extern "C" {
#endif

void init_servo();
void set_servo(unsigned char id, unsigned short val);

#ifdef __cplusplus
}
#endif
