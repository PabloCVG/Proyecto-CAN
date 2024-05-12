/*
 * SSI.c
 *
 *  Created on: 18 feb 2024
 *      Author: aresi
 */

#include <stdint.h>
#include <stdbool.h>
#include "inclu/Macros.h"
#include "inclu/NVIC.h"
#include "inc/tm4c1294ncpdt.h"

void SSI_Init(uint8_t SSIx_clk){
    SET_BIT(SYSCTL_RCGCSSI_R, SSIx_clk);
}

void SSI_Conf(uint8_t SSIx_clk, uint16_t Clock_Pres, uint16_t SCR, bool Formato_Trama, bool Polarity, bool Phase, uint8_t Tamaño_Trama){
    switch(SSIx_clk){
    case SSI0_clk:
        CLEAR_BIT(SSI0_CR1_R, 1); //Deshabilitar el SSI
        CLEAR_BIT(SSI0_CR1_R, 2); //Habilitar modo maestro de SSI

        SET_BR(SSI0_CC_R, 0x0); //Seleccionamos el Reloj del System

        SET_BR(SSI0_CPSR_R, Clock_Pres); //Mínimo de 2 o máximo de 254

        SSI0_CR0_R &= ~(0xFFFF); //Reseteamos el registro de control 0

        SET_BR(SSI0_CR0_R, SCR); //SRC que viene de 1 a 255

        /*Seleccionamos el tipo de modo: SPI o TexasInstruments SF*/
        if(Formato_Trama == true) //Seleccionamos el modo que vamos a utilizar
            SET_BIT(SSI0_CR0_R, 4); //TexasInstruments SF
        else
            CLEAR_BIT(SSI0_CR0_R, 4); //SPI

        /*Seleccionamos el modo de la línea*/
        if(Polarity == true)
            SET_BIT(SSI0_CR0_R, 6);//La línea se mantiene en alto mientras no haya transmisión
        else
            CLEAR_BIT(SSI0_CR0_R, 6);//La línea se mantiene en bajo mientras no haya transmisión

        /*Seleccionamos el flanco en el que se hace la detección*/
        if(Phase == true)
            SET_BIT(SSI0_CR0_R, 7); //Segundo flanco
        else
            CLEAR_BIT(SSI0_CR0_R, 7); //Primer flanco

        SET_BR(SSI0_CR0_R, Tamaño_Trama); //Definimos el tamaño de la trama
        break;

    case SSI1_clk:
        CLEAR_BIT(SSI1_CR1_R, 1); //Deshabilitar el SSI
        CLEAR_BIT(SSI1_CR1_R, 2); //Habilitar modo maestro de SSI

        SET_BR(SSI1_CC_R, 0x0); //Seleccionamos el Reloj del System

        SET_BR(SSI1_CPSR_R, Clock_Pres); //Mínimo de 2 o máximo de 254

        SSI1_CR0_R &= ~(0xFFFF); //Reseteamos el registro de control 0

        SET_BR(SSI1_CR0_R, SCR); //SRC que viene de 1 a 255

        /*Seleccionamos el tipo de modo: SPI o TexasInstruments SF*/
        if(Formato_Trama == true) //Seleccionamos el modo que vamos a utilizar
            SET_BIT(SSI1_CR0_R, 4); //TexasInstruments SF
        else
            CLEAR_BIT(SSI1_CR0_R, 4); //SPI

        /*Seleccionamos el modo de la línea*/
        if(Polarity == true)
            SET_BIT(SSI1_CR0_R, 6);//La línea se mantiene en alto mientras no haya transmisión
        else
            CLEAR_BIT(SSI1_CR0_R, 6);//La línea se mantiene en bajo mientras no haya transmisión

        /*Seleccionamos el flanco en el que se hace la detección*/
        if(Phase == true)
            SET_BIT(SSI1_CR0_R, 7); //Segundo flanco
        else
            CLEAR_BIT(SSI1_CR0_R, 7); //Primer flanco

        SET_BR(SSI1_CR0_R, Tamaño_Trama); //Definimos el tamaño de la trama
        break;

    case SSI2_clk:
        CLEAR_BIT(SSI2_CR1_R, 1); //Deshabilitar el SSI
        CLEAR_BIT(SSI2_CR1_R, 2); //Habilitar modo maestro de SSI

        SET_BR(SSI2_CC_R, 0x0); //Seleccionamos el Reloj del System

        SET_BR(SSI2_CPSR_R, Clock_Pres); //Mínimo de 2 o máximo de 254

        SSI2_CR0_R &= ~(0xFFFF); //Reseteamos el registro de control 0

        SET_BR(SSI2_CR0_R, SCR); //SRC que viene de 1 a 255

        /*Seleccionamos el tipo de modo: SPI o TexasInstruments SF*/
        if(Formato_Trama == true) //Seleccionamos el modo que vamos a utilizar
            SET_BIT(SSI2_CR0_R, 4); //TexasInstruments SF
        else
            CLEAR_BIT(SSI2_CR0_R, 4); //SPI

        /*Seleccionamos el modo de la línea*/
        if(Polarity == true)
            SET_BIT(SSI2_CR0_R, 6);//La línea se mantiene en alto mientras no haya transmisión
        else
            CLEAR_BIT(SSI2_CR0_R, 6);//La línea se mantiene en bajo mientras no haya transmisión

        /*Seleccionamos el flanco en el que se hace la detección*/
        if(Phase == true)
            SET_BIT(SSI2_CR0_R, 7); //Segundo flanco
        else
            CLEAR_BIT(SSI2_CR0_R, 7); //Primer flanco

        SET_BR(SSI2_CR0_R, Tamaño_Trama); //Definimos el tamaño de la trama
        break;

    case SSI3_clk:
        CLEAR_BIT(SSI3_CR1_R, 1); //Deshabilitar el SSI
        CLEAR_BIT(SSI3_CR1_R, 2); //Habilitar modo maestro de SSI

        SET_BR(SSI3_CC_R, 0x0); //Seleccionamos el Reloj del System

        SET_BR(SSI3_CPSR_R, Clock_Pres); //Mínimo de 2 o máximo de 254

        SSI3_CR0_R &= ~(0xFFFF); //Reseteamos el registro de control 0

        SET_BR(SSI3_CR0_R, SCR); //SRC que viene de 1 a 255

        /*Seleccionamos el tipo de modo: SPI o TexasInstruments SF*/
        if(Formato_Trama == true) //Seleccionamos el modo que vamos a utilizar
            SET_BIT(SSI3_CR0_R, 4); //TexasInstruments SF
        else
            CLEAR_BIT(SSI3_CR0_R, 4); //SPI

        /*Seleccionamos el modo de la línea*/
        if(Polarity == true)
            SET_BIT(SSI3_CR0_R, 6);//La línea se mantiene en alto mientras no haya transmisión
        else
            CLEAR_BIT(SSI3_CR0_R, 6);//La línea se mantiene en bajo mientras no haya transmisión

        /*Seleccionamos el flanco en el que se hace la detección*/
        if(Phase == true)
            SET_BIT(SSI3_CR0_R, 7); //Segundo flanco
        else
            CLEAR_BIT(SSI3_CR0_R, 7); //Primer flanco

        SET_BR(SSI3_CR0_R, Tamaño_Trama); //Definimos el tamaño de la trama
        break;
    }
}

void SSI_interrup_Conf(uint8_t SSIx_clk){
    switch(SSIx_clk){
    case SSI0_clk:
        SET_BIT(SSI0_IM_R, 6);  //Interrupción de fin de transmisión
        CLEAR_BIT(SSI0_ICR_R, 6); //Limpiamos la interrupción
        NVIC_Act(INTE_SSI0);
        break;

    case SSI1_clk:
        SET_BIT(SSI1_IM_R, 6);  //Interrupción de fin de transmisión
        CLEAR_BIT(SSI1_ICR_R, 6); //Limpiamos la interrupción
        NVIC_Act(INTE_SSI1);
        break;

    case SSI2_clk:
        SET_BIT(SSI2_IM_R, 6);  //Interrupción de fin de transmisión
        CLEAR_BIT(SSI2_ICR_R, 6); //Limpiamos la interrupción
        NVIC_Act(INTE_SSI2);
        break;

    case SSI3_clk:
        SET_BIT(SSI3_IM_R, 6);  //Interrupción de fin de transmisión
        CLEAR_BIT(SSI3_ICR_R, 6); //Limpiamos la interrupción
        NVIC_Act(INTE_SSI3);
        break;
    }
}

