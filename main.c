/*
 * i2c_lcd.c
 *
 * Created: 15/07/2020 1:59:35 pm
 * Author : John
 */ 

#include <avr/io.h>
#include "PCF8754.h"

int main(void)
{
	LCD_Init();
    LCD_print("HELLO");
    while (1) 
    {
    }
}

