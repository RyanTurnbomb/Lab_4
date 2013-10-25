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
    LCDinit();
    LCDclear();

    char* string = "ECE382 is my favorite class!";
    char* string2 = "Great Success!";

    while(1){
    }

	return 0;
}
