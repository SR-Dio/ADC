/*
 * File:   LCD.c
 * Author: 21193665
 *
 * Created on 14 de Maio de 2021, 13:30
 */


#include "config.h"
#include <xc.h>

#define _XTAL_FREQ 4000000

#define DADOS  PORTB
#define EN  PORTDbits.RD7
#define RS  PORTDbits.RD6

void LCD_init( void )
{
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;  
    ANSELH = 0;
    TRISB = 0x00;
   
    DADOS = 0x00;
    EN = 1;
    RS = 0;
}

void LCD_on( void )
{
    RS = 0;
    EN = 1;
    DADOS = 0x0F;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void LCD_lincol(char lin, char col)
{
// ligar display LCD
    RS = 0;
    EN = 1;
    DADOS: 0x80 + ( (lin*40) + col);
    EN = 0;
    __delay_us(40);
    EN = 1;


}

void LCD_printChar( char c )
{
    RS = 1;
    DADOS = c;
    EN = 0;
    __delay_us(40);
    EN = 1;

}

void LCD_print( char *str )
{
    int i = 0;

    while( *(str+i) != 0 )
    {
        if(*(str+i) == '\n')
            LCD_lincol(1,0);
        else 
        { 
            if (i == 16 )
                LCD_lincol(1,0);
        
        }
    }                    
}