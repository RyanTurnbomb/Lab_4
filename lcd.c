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

char LCDCON;


void set_SS_lo(){
    P1OUT &= ~BIT0;
}

void set_SS_hi(){
	P1OUT |= BIT0;
}

void initSPI(){
        UCB0CTL1 |= UCSWRST;

        UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;

        UCB0CTL1 |= UCSSEL1;

        UCB0STAT |= UCLISTEN;

        P1DIR 	 |= BIT0;

        P1SEL 	 |= BIT5;
        P1SEL2 	 |= BIT5;                             // clock P1.5

        P1SEL 	 |= BIT6;                             // SOMI P1.6
        P1SEL2 	 |= BIT6;

        P1SEL 	 |= BIT7;                             // SIMO P1.7
        P1SEL2 	 |= BIT7;

        UCB0CTL1 &= ~UCSWRST;

}

void initLCD(){
    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x02);

    writeCommandByte(0x28);

    writeCommandByte(0x0C);

    writeCommandByte(0x01);

    writeCommandByte(0x06);

    writeCommandByte(0x01);

    writeCommandByte(0x02);

    SPI_send(0);
    __delay_cycles(40);
}

void clearLCD(){
    writeCommandByte(1);
}

void moveCursorLine1(){
	writeCommandByte(0x02);
	LCDCON |= RS_MASK;
	__delay_cycles(1630);
}

void moveCursorLine2(){
	writeCommandByte(0xC0);
	LCDCON |= RS_MASK;
	__delay_cycles(1630);
}


void writeCommandNibble(char commandNibble){
    LCDCON &= ~RS_MASK;
    LCD_write_4(commandNibble);
    __delay_cycles(1630);
}

void writeCommandByte(char commandByte){
    LCDCON &= ~RS_MASK;
    LCD_write_8(commandByte);
    __delay_cycles(1630);
}

void writeDataByte(char dataByte){
    LCDCON |= RS_MASK;
    LCD_write_8(dataByte);
    __delay_cycles(1630);
}

void LCD_write_8(char byteToSend){
    unsigned char sendByte = byteToSend;

    sendByte &= 0xF0;

    sendByte = sendByte >> 4;               // rotate to the right 4 times

    LCD_write_4(sendByte);

    sendByte = byteToSend;

    sendByte &= 0x0F;

    LCD_write_4(sendByte);
}

void LCD_write_4(char byteToSend){
	unsigned char sendByte = byteToSend;

	sendByte &= 0x0F;

	sendByte |= LCDCON;

	sendByte &= 0x7F;

	SPI_send(sendByte);

	__delay_cycles(40);

	sendByte |= 0x80;

	SPI_send(sendByte);

	__delay_cycles(40);

	sendByte &= 0x7F;

	SPI_send(sendByte);

	__delay_cycles(40);
}

void writeChar(char asciiChar){
	writeCommandByte(0x06);
	writeDataByte(asciiChar);
}

void writeString(char *string){
	int i;
	for (i = 0; i < 8; i++) {
		writeChar(string[i]);
	}
}

void scrollString(char* string_one, char* string_two){
	char* string1 = string_one;
	char* string2 = string_two;

	while(1){

	moveCursorLine1();
	writeString(string1);

	moveCursorLine2();
	writeString(string2);

	string1++;
	if(*string1 == 0){
		string1 = string_one;
	}

	string2++;
	if(*string2 == 0){
		string2 = string_two;
	}
	__delay_cycles(1630);
	}
}


void SPI_send(char byteToSend){
    volatile char readByte;

    set_SS_lo();

    UCB0TXBUF = byteToSend;

    while(!(UCB0RXIFG & IFG2)){
        // wait until you've received a byte
    }

    readByte = UCB0RXBUF;

    set_SS_hi();
}
