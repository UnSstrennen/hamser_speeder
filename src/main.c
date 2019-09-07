#include <avr/io.h>
#include <avr/interrupt.h>

#define M_PI 3.14159265358979323846
#define MAX_MODE 4

#define button PB1
#define hall PB3
#define pot PB4

unsigned char mode;

void buttonPressed() {
  // change the mode
  mode++;
  if (mode > MAX_MODE) {
    mode = 0;
  }
  switch (mode) {
    case 0:
    break;
  }
}

ISR(ANALOG_COMP_vect)
{
  // magnet detected
}

int main (void)
{
  // inputs
  DDRB &= ~(1<<button);

  // EXINT
  GIMSK |= (1<<INT0);
  MCUCR |= (1<<ISC00)|(1<<ISC01);

  // comparator
  ACSR |= (1<<ACIS0)|(1<<ACIS1);  // choose the mode
  ACSR |= (1<<ACIE);  // allow interrupts

  sei();

  while(1)
  {
    if (PORTB & (1<<button)) {
      buttonPressed();
    }
  }
}
