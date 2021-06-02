/*
 * File:   main.c
 * Author: 21193665
 *
 * Created on 20 de Maio de 2021, 15:54
 */


#include "config.h" 
#include <xc.h>
#include "delay.h"
#define A1     PORTDbits.RD0 // a+
#define A2     PORTDbits.RD1 // b+
#define B1     PORTDbits.RD2 // a-
#define B2     PORTDbits.RD3 // b-


char passh [8] = { 0x08,0x0C,0x04,0x06,0x02,0x03,0x01,0x09}; // 0x08+0x01 = 0x09/0x04+0x02= 0x06

int ppr;


void portd_init (int passos_motor)
{
    TRISD = 0;
    PORTD = 0;
    
    ppr = passos_motor;
}



void main(void) 
{
    portd_init();
    int i = 0;
    
    
    for(i =0; i<9; i++ )
                        
    {
        PORTD = passh[i];
        delay(500);
    }  
}
    

void motor_ihm (int graus, int sentido, int t )
{
   int x = (graus * ppr)/360;
}

void graus (int graus)
{
    360/ 7,5;
}