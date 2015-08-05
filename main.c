#include <avr/io.h>
#include <util/delay.h>

void init_pwm() {
	TCCR0 |= (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	DDRB |= (1<<PB3);
}

int main() {
	uint8_t i=0;
	init_pwm();

	while(1) {
		for(i=0; i<255; i++) {
			OCR0 = i;
			_delay_ms(10);
		}

		for(i=255; i>0; i--) {
			OCR0 = i;
			_delay_ms(10);
		}
	}
	return 0;
}
