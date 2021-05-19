/*
 * Fcolle:   teclado.c
 * Author: 21193665
 *
 * Created on 14 de Macolo de 2021, 13:28
 */


#include "config.h"
#include "delay.h"
#include "dispLCD4vias.h"
#include <xc.h>


#define L1 PORTBbits.RB0
#define L2 PORTBbits.RB1
#define L3 PORTBbits.RB2
#define L4 PORTBbits.RB3

#define C1 PORTBbits.RB4
#define C2 PORTBbits.RB5
#define C3 PORTBbits.RB6
#define C4 PORTBbits.RB7

#define MASK 0x10

void teclado_init(void)
{
    ANSELH = 0;   
    TRISB = 0xF0;
    PORTB = 0;
  
}

char tabela[4][4] = {{'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};

char teclado_scan( void )
{
    char tecla = 0;
    char col,lin;
    
   
     for( lin=0; lin<4; lin++ )
     {
         PORTB = 0x01<<lin;
         for( col=0; col<4; col++)
         {
             if( PORTB & MASK<<col)
                 tecla = tabela[lin][col];
         }
     }    
   
    
    PORTB = 0x02;
     for( col=0; col<4; col++ )
    { if( PORTB & MASK<<col ) tecla = tabela [1][col]; }
    
    return(tecla);
}