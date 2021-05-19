/*
 * File:   delay.c
 * Author: 21193665
 *
 * Created on 14 de Maio de 2021, 13:27
 */


#include <xc.h>
#include "config.h"


void delay (unsigned int t)
{
    while( t )
    {
        --t;
        __delay_ms(1);
    }
}