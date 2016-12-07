#include <avr/io.h>
#include "test.h"

void init_peripheral()
{
	DDRC |= (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5);
	PORTC &= ~(1<<PC0) & ~(1<<PC1) & ~(1<<PC2) & ~(1<<PC3) & ~(1<<PC4) & ~(1<<PC5);
	
	DDRB |= (1<<PC0) | (1<<PC1);
	PORTB &= ~(1<<PC0) & ~(1<<PC1);
}

void set_green_led (uint8_t pin, uint8_t state)
{
	if(pin < 6)
	{
		if(state)
		{
			PORTC |= (1<<pin);
		}
		else
		{
			PORTC &= ~(1<<pin);
		}
	}
	else
	{
		pin -= 6;
		if(state)
		{
			PORTB |= (1<<pin);
		}
		else
		{
			PORTB &= ~(1<<pin);
		}
	}
}

