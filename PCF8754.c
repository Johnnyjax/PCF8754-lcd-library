#include "PCF8754.h"







uint8_t i2cData = 0b00001000;

void LCD_Init() {
	initI2C();
	i2cStart();
	i2cSend(PCF8754_ADDR);
	
	//Initialization routine in datasheet figure 24
	_delay_ms(5);
	LCD_send4bits(3, 0);
	_delay_ms(5);
	LCD_send4bits(3, 0);
	_delay_ms(10);
	LCD_send4bits(3, 0);
	_delay_us(100);
	LCD_send4bits(2, 0);
	_delay_us(100);
	
	LCD_sendCmd(FUNC_SET);
	LCD_sendCmd(ENTRY_MOD_SET);
	LCD_sendCmd(DISPLAY_ON);
	LCD_sendCmd(CLEAR_DISPLAY);
	_delay_ms(2);
	
}

void LCD_send4bits(uint8_t cmd, uint8_t mode) {
	if(cmd & 0x01) {
		i2cData |= D4;
	} else {
		i2cData &= ~D4;
	}
	if(cmd & 0x02) {
		i2cData |= D5;
	} else {
		i2cData &= ~D5;
	}
	if(cmd & 0x04) {
		i2cData |= D6;
	} else {
		i2cData &= ~D6;
	}
	if(cmd & 0x08) {
		i2cData |= D7;
	} else {
		i2cData &= ~D7;
	}
	if(mode == 1) {
		i2cData |= RS;
	} else {
		i2cData &= ~RS;
	}
	
	i2cSend(i2cData);
	_delay_us(100);
	i2cData &= ~EN;
	i2cSend(i2cData);
	_delay_us(1);
	i2cData |= EN;
	i2cSend(i2cData);
	_delay_us(1);
	i2cData &= ~EN;
	i2cSend(i2cData);
	_delay_us(100);
	
}

void LCD_sendCmd(uint8_t cmd) {
	LCD_send4bits(cmd >> 4, 0);
	LCD_send4bits(0x0f & cmd, 0);
}

void LCD_sendData(uint8_t data) {
	LCD_send4bits(data >> 4, 1);
	LCD_send4bits(0x0f & data, 1);
}

void LCD_print(const char myString[]) {
	uint8_t i = 0;
	while (myString[i]) {
		LCD_sendData(myString[i]);
		i++;
	}
}

void LCD_shift_cursor() {
	LCD_sendCmd(CUR_RIGHT_SHFT);
}

void LCD_setCursor(uint8_t col, uint8_t row) {
	if(row == 0) {
		LCD_sendCmd(128 + col);
		} else {
		LCD_sendCmd(192 + col);
	}
}

void LCD_home() {
	LCD_sendCmd(HOME_CURSOR);
}

void LCD_scrollDisplayLeft() {
	LCD_sendCmd(SCROLL_LEFT);
}

void LCD_scrollDisplayRight() {
	LCD_sendCmd(SCROLL_RIGHT);
}