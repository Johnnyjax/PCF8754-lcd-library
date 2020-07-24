#include <util/delay.h>
#include "i2c.h"


// pc8754 address with write
#define PCF8754_ADDR   0x4E  

// pin definitions
#define RS             0x01
#define RW             0x02
#define EN             0x04
#define LED            0x08
#define D4             0x10
#define D5             0x20
#define D6             0x40
#define D7             0x80
    
// LCD command codes      
#define CLEAR_DISPLAY  0b00000001 // clears the display
#define HOME_CURSOR    0b00000010 // Sets the cursor to the home position
#define FUNC_SET       0b00101000 // Sets 4bit length, No of lines to 2 and sets the Font size
#define ENTRY_MOD_SET  0b00000100 // Increment Screen address and enable shifting
#define DISPLAY_ON     0b00001111 // Turn on Display, Display Cursor, No Blinking
#define CUR_RIGHT_SHFT 0b00010100 //Shift cursor to the right by 1
#define CUR_LEFT_SHFT  0b00010000 //Shift cursor to the left by 1
#define SCROLL_LEFT    0b00011000 //Shift the entire display to the left by 1
#define SCROLL_RIGHT   0b00011100 //Shift the entire display to the right by 1

uint8_t i2cData;
//Liquid Crystal init function
void LCD_Init();
void LCD_send4bits(uint8_t cmd, uint8_t mode);
void LCD_sendCmd(uint8_t cmd);
void LCD_sendData(uint8_t data);
void LCD_clear();
void LCD_home();
void LCD_setCursor(uint8_t col, uint8_t row);
void LCD_print(const char myString[]);
void LCD_shift_cursor();
void LCD_scrollDisplayLeft();
void LCD_scrollDisplayRight();
void LCD_autoscroll();
void LCD_noAutoscroll();

