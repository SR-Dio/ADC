/*
 * File:   main.c
 * Author: 21193665
 *
 * Created on 14 de Maio de 2021, 13:25
 */

#include "config.h"
#include "delay.h"
#include "dispLCD4vias.h"
#include "teclado.h"
#include "LCD.h"
#include <xc.h>

void main(void) 
{
    teclado_init();
    dispLCD_init();
    
    char tecla = 0;
    char estado = 0;    
    
    while(1)
    {
       tecla = teclado_scan();
       switch(estado)
       {
           case 0:
                    estado = 1;
                    break;
           case 1:
                    dispLCD(0,0,"playstation 2   ");
                    delay(3000);
                    estado = 10;
                    break;
           case 10:  
                    dispLCD(0,0," Tertos Terona  ");               
                    dispLCD(1,0,"1:Operacao C:cfg");
                    if(tecla == '1')
                        estado = 20;
                    if(tecla == 'C')
                        estado = 100;
                    break;
           case 20:
                    dispLCD(0,0,"Operando....    ");
                    dispLCD(1,0,"                "); 
                    if( tecla == '*')
                        estado = 10;
                    break;
           case 100:
                    dispLCD(0,0,"configurando....");
                    dispLCD(1,0,"                ");
                    if( tecla == '*')
                        estado = 10;
                    break;        
       }
    }
}
