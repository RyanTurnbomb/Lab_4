/*
 * lcd.h
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Ryan.Turner
 */

#ifndef LCD_H_
#define LCD_H_

void initSPI();

void initLCD();

void clearLCD();

void moveCursorLine1();

void moveCursorLine2();

void writeChar(char asciiChar);

void writeString(char *string);

void scrollString(char *string_one, char *string_two);

void writeCommandNibble(char commandNibble);

void writeCommandByte(char commandByte);

void LCD_write_8(char byteToSend);

void LCD_write_4(char byteToSend);

void SPI_send(char byteToSend);

#endif /* LCD_H_ */
