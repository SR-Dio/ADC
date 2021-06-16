/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 28 de Maio de 2021, 12:40:21
 *
 
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "timers.h"

void main(void)
{
    dispLCD_init();
    timer0_init();
    led();
    dispLCD(0,0,"Contador:       ");
    while( 1 )
    {
        dispLCD_num(0,10,cont(),5 );
        
    }
    
}
