/*
 * main.c
 * Created on: Oct 24, 2013
 * Author: C2C Ryan Turner
 * Description- writes to
 * an LCD screen
 */

#include <msp430.h> 
#include "lcd.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initSPI();
	initLCD();
	clearLCD();

	char *string_one = "ECE382 is my favorite class!";
	char *string_two = "Great Success!";
	scrollString(string_one, string_two);

	while (1) {

	}

	return 0;
}
