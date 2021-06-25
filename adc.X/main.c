/*
 * File:   main.c
 * Author: 21193665
 *
 * Created on 25 de Junho de 2021, 14:02
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "adc.h"

void main(void) 
{
    dispLCD_init();
    adc_init();
    int adcv;
    adcv = ADRESH;
    
    dispLCD(0,0,"ADC:            ");
    
     while( 1 )
     {
         dispLCD_num(0,10,adc(),4 );
     }
   
}
