#ifndef _LIBGPIO_H
#define _LIBGPIO_H

#define HIGH '1'
#define LOW '0'
#define MODE_INPUT '0'
#define MODE_OUTPUT '1'
#define MODE_PULLUP '8'

#ifdef __cplusplus
extern "C" {
#endif

void gpio_open();

void setPinValue(int pin, unsigned char val);
void setPinMode(int pin, unsigned char mode);

unsigned char getPinValue(int pin);
unsigned char getPinMode(int pin);

void gpio_close();

#ifdef __cplusplus
}
#endif

#endif


