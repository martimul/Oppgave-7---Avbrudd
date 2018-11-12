/*
 * GccApplication2.cpp
 *
 * Created: 10/24/2018 10:40:00 PM
 * Author : Hans Martin
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int cliFlag = 0;

int main(void)
{
	
	DDRD &= ~(1 << DDD2);		// Clearer PD2 pinnen og setter PD2(INT0) som input


	PORTD = (1 << PD2);			// Slår på PD2(INT0) som input med pull-up resistor aktivert
	
	DDRB  = (1 << PB1);			// Setter PB1 som input
	
	
	EICRA |= (1 << ISC01);      // Setter INT0 til å "triggre" ved en endring, feks en knapp blir trykket. 
	EIMSK |= (1 << INT0);       // Slår på INT0


	
	while(1)
	{
		if(cliFlag == 0)	// cliFlag er en variabel som hvis lik 0, brukes til å sette sei();, som betyr set interrupt. 
							// Hvis den er lik 1 brukes den til å sette cli();, som betyr clear interrupt.
							// Hvis 
		{
			sei();
		}
		else
		{
			cli();
			_delay_ms(20);
			cliFlag = 0;
		}
	}
}

ISR (INT0_vect)
{
	PORTB ^= (1 << PB1);
	cliFlag = 1;
}

