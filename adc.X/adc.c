/*
 * File:   adc.c
 * Author: 21193665
 *
 * Created on 25 de Junho de 2021, 14:18
 */


#include <xc.h>


void adc_init (void)
{
    TRISA = 1;
    ANSEL = 1;
    ADCON0 = 0;
    ADCON1bits.VCFG0 = 0;
    ADCON1bits.VCFG1 = 0;
    ADCON0bits.CHS = 0;
    ADCON1bits.ADFM = 1;
    ADCON0bits.ADON = 1;
      
}


int adc (void)
{
    ADCON0bits.GO = 1;
    
    while(ADCON0bits.nDONE)
    {
      
    }
   
    return((ADRESH<<8)+ADRESL);
}
