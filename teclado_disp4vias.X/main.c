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
    
    char cont_senha = 0;
    char senhaOK = 0;
    char estado_senha = 0;
    char senha[4] = {0,0,0,0};
    char senha_correta[4] = {'2','1','1','8'};
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
                    estado = 30;
                    break;
            case 20:
                    dispLCD(0,0,"Operando....    ");
                    dispLCD(1,0,"                "); 
                    if( tecla == '*')
                    estado = 10;
                    break;
            case 30:
                    dispLCD(0,0,"configurando....");
                    dispLCD(1,0,"                ");
                    if( tecla == '*')
                    estado = 32;
                    break;  
            case 32:
                     dispLCD(0,7,"senha");
                    if(estado_senha == 100)
                    estado = 39;
                    if(estado_senha ==  90)
                    estado = 38;
                    break;
            case 38: 
                    dispLCD(0,0,"senha incorreta!");
                    if( tecla == '*')
                    estado = 10;
                    break;
           case 39:
                    dispLCD(0,0,"senha correta!  ");
                    if(tecla == '*')
                    estado = 10;
                    break;
                
       }
       switch(estado_senha)
       {
           case 0:
               if(estado == 30)
                   estado_senha = 10;
               break;
           case 10:
               cont_senha = 0;
               senha[0] = 0;
               senha[1] = 0;
               senha[2] = 0;
               senha[3] = 0;
               senhaOK = 1;
               estado_senha = 12;
               break;
           case 12:
               
               
       }
    }
}
