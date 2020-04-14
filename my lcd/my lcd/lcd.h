/*
 * lcd.h
 *
 * Created: 4/11/2020 9:04:00 AM
 *  Author: ahmad
 */ 


#ifndef LCD_H_
#define LCD_H_
#define f_cpu 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define  lcd_dd			DDRA
#define  lcd_port		PORTA
#define  lcd_con		PORTB
#define  lcd_con_dd		DDRB
#define  RS				1
#define  RW				2
#define  EN				3
#define set_bit(var,bit)		var|=(1<<bit)
#define clear_bit(var,bit)		var&~(1<<bit)
#define toggel_bit(var,bit)		var^(1<<bit)
#define get_bit(var,bit)		(var>>bit)&1

void lcd_init (void);
void lcd_command(unsigned char cmd);
void lcd_write (unsigned char data);
void lcd_str (char *str);
#endif /* LCD_H_ */