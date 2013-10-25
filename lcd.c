/*
 * lcd.c
 * Created on: Oct 24, 2013
 * Author: C2C Ryan Turner
 * Description- Implementation
 * of lcd.h
 */


#include <msp430.h>
#include "lcd.h"

#define RS_MASK 0x40

char LCDCON = 0;

void writeCommandNibble(char commandNibble);
void writeCommandByte(char commandByte);
void writeDataByte(char dataByte);
void LCD_write_8(char byteToSend);
void LCD_write_4(char byteToSend);
void SPI_send(char byteToSend);

void set_SS_lo(){
        P2OUT &= ~BIT1;
}

void set_SS_hi(){
        P2OUT |= BIT1;
}

void initSPI(){
        UCB0CTL1 |= UCSWRST;

        UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;

        UCB0CTL1 |= UCSSEL1;

        UCB0STAT |= UCLISTEN;

        P1SEL 	 |= BIT5;
        P1SEL2 	 |= BIT5;                             // clock P1.5

        P1SEL 	 |= BIT6;                             // SOMI P1.6
        P1SEL2 	 |= BIT6;

        P1SEL 	 |= BIT7;                             // SIMO P1.7
        P1SEL2 	 |= BIT7;

        UCB0CTL1 &= ~UCSWRST;

}
