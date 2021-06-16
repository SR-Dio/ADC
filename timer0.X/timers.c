/*
 * File:   timers.c
 * Author: sn1011701
 *
 * Created on 11 de Junho de 2021, 14:50
 */


#include <xc.h>

#include "lcd.h"



unsigned long t1seg;

int c = 0;
void led (void)
{
    ANSELH = 0;
    TRISB = 0;
    PORTB = 0;
   
}


void timer0_init( void )
{
    INTCONbits.GIE = 0;
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PSA = 1;
    TMR0 = 256-100;
    t1seg = 10000; 
    INTCONbits.T0IE = 1;
    INTCONbits.GIE = 1;
    
}



unsigned int cont (void)
{
    return (c);
}

void __interrupt() iqr (void)
{
    if( INTCONbits.T0IF )
    {
        INTCONbits.T0IF = 0;
        TMR0 = 256-100;
        --t1seg;
        if( t1seg == 0 )
        {
            t1seg = 10000;
            if(c<51)
                ++c;
            if(c==50)
                c=0;
            PORTBbits.RB0 = 1 ;                
            if(c>0)
            PORTBbits.RB0 = 0;
        }    
        
    }
}