#ifndef __LED_H
#define __LED_H
#include <stdbool.h>
void LED_init(void);
void LED_SET(uint16_t pin, bool Cond);
void LED_turn(uint16_t pin);
#endif
