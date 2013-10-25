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
void set_SS_lo();
void set_SS_hi();


void set_SS_lo(){
        P2OUT &= ~BIT1;
}

void set_SS_hi(){
        P2OUT |= BIT1;
}

