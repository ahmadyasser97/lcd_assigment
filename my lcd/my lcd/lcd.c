/*
 * lcd.c
 *
 * Created: 4/11/2020 9:03:39 AM
 *  Author: ahmad
 */ 
#include "lcd.h"

void lcd_init (void){
	lcd_dd = 0xff;
	lcd_con_dd = 0x0f;
	set_bit(lcd_con_dd,2);
	_delay_us(20);
	lcd_command(0x33);
	lcd_command(0x32);
    lcd_command(0x28);
	lcd_command(0x0e);
	lcd_command(0x06);
	lcd_command(0x01);
	
}
void lcd_command(unsigned char cmd){
	lcd_port=(lcd_port & 0x0f)|(cmd & 0xf0);
	clear_bit(lcd_con,RS);
	set_bit(lcd_con,EN);
	_delay_us(10);
	clear_bit(lcd_con,EN);
	_delay_us(2000);
	lcd_port=(lcd_port & 0x0f)|(cmd <<4);
		clear_bit(lcd_con,RS);
		set_bit(lcd_con,EN);
		_delay_us(1);
		clear_bit(lcd_con,EN);
		_delay_ms(2);
}
void lcd_write (unsigned char	 data){
	
		lcd_port=(lcd_port & 0x0f)|(data & 0xf0);
		set_bit(lcd_con,RS);
		set_bit(lcd_con,EN);
		_delay_us(10);
		clear_bit(lcd_con,EN);
		_delay_us(2000);
		lcd_port=(lcd_port & 0x0f)|(data <<4);
		set_bit(lcd_con,RS);
		set_bit(lcd_con,EN);
		_delay_us(10);
		clear_bit(lcd_con,EN);
		_delay_ms(7);
}
void lcd_str (char *str){
	int i;
	while (str[i]!=0){
		lcd_write(str[i]);
		i++;
	}
}