#include <Arduino.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL

char a = 0;
void config_IE (void){
  EIMSK |= (1<<INT0);
  EICRA |= (1<<ISC01);
  DDRD &= ~(0x04);
  PORTD |= 0X04;
}

ISR (INT0_vect){
  a++;
  if(a>1){
    a = 0;
  }
}

int main(void){
  DDRD |= 0xE0;
  PORTD &= ~(0xE0);
  DDRB |= 0x07;
  config_IE();
  sei();

  while(1){
    if(a==1){
      PORTD &= ~(0XE0);
      PORTB &= ~(0x07);

      PORTD |= 0x20;
      PORTB |= 0X04;
      _delay_ms(5000);
      PORTD &= ~(0XE0);
      PORTB &= ~(0x07);
      PORTD |= 0x40;
      PORTB |= 0X04;
      _delay_ms(1000);
      PORTD &= ~(0XE0);
      PORTB &= ~(0x07);
      PORTD |= 0x80;
      PORTB |= 0X01;

      _delay_ms(5000);
      PORTD &= ~(0xE0);
      PORTD &= ~(0x07);
      PORTD |= 0x80;
      PORTB |= 0x02;
      _delay_ms(1000);
      
    }
  }
}