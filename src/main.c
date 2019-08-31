#include <avr/io.h>
#include <avr/interrupt.h>

#define button PB1
#define hall PB3

ISR(INT0_vect)
{
  // change the mode
}

int main (void)
{
  // inputs
  DDRB &= ~(1<<button);

  // EXINT
  GIMSK |= (1<<INT0);
  MCUCR |= (1<<ISC00)|(1<<ISC01);
  sei();

  while(1)
  {
    if ()
  }
}
