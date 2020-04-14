/*
 * my lcd.c
 *
 * Created: 4/11/2020 9:03:07 AM
 * Author : ahmad
 */ 

#include <avr/io.h>
#include "lcd.h"


int main(void)
{
	lcd_init();
	lcd_command(0x81);
	lcd_str("amit");
	lcd_command(0x86);
	lcd_str("17");
	lcd_command(0xc4);
	lcd_str("ahmad");
    /* Replace with your application code */
    while (1) 
    {
    }
}

