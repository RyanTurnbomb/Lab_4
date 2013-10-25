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

void scrollString(char* string1, char* string2);

#endif /* LCD_H_ */
