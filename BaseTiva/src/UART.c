/*
 * UART.c
 *
 *  Created on: 30 ene 2024
 *      Author: aresi
 */

/*Bibliotecas y cabeceros*/

#include <stdbool.h>
#include <stdint.h>
#include "inclu/UART.h"
#include "inclu/NVIC.h"
#include "inclu/Macros.h"
#include "inc/tm4c1294ncpdt.h"

/*Función para inicializar los UART*/

void UART_Init(uint8_t UARTx_clk){
    SET_BIT(SYSCTL_RCGCUART_R, UARTx_clk);
}

/*Función de monitoreo de UART para conocer estado*/

void UART_Monitoreo(){
    while((SYSCTL_PRUART_R & 0x0FF) == 0x00); //Monitoreamos si el reloj del UART esta listo
}

/*Funciones para inicializar UART*/

float UART_Baud_Rate_Frac(float Baud_Rate_Fraccion){
    return ((Baud_Rate_Fraccion) * 64 + 0.5);
}

/*Realizar operación
 *  BRD = BRDI + BRDF = UARTSysClk / (ClkDiv * Baud Rate)*/
void UART_Set_Baud_Rate(uint8_t UARTx_clk, uint32_t Baud_Rate_Entero, float Baud_Rate_Fraccion){

    /*Considerando que la frecuencia inicial es de 16 MHz*/
    switch(UARTx_clk){
    case UART0_clk:
        CLEAR_BIT(UART0_CTL_R, 0);
        SET_BR(UART0_IBRD_R, Baud_Rate_Entero); //Parte entera del Baud Rate

        /*Parte fraccionaria del Baud Rate*/
        SET_BR(UART0_FBRD_R, (int)(UART_Baud_Rate_Frac(Baud_Rate_Fraccion)));
        break;

    case UART1_clk:
        CLEAR_BIT(UART1_CTL_R, 0);
        SET_BR(UART1_IBRD_R, Baud_Rate_Entero); //Parte entera del Baud Rate

        /*Parte fraccionaria del Baud Rate*/
        SET_BR(UART1_FBRD_R, (int)(UART_Baud_Rate_Frac(Baud_Rate_Fraccion)));
        break;

    case UART2_clk:
        CLEAR_BIT(UART2_CTL_R, 0);
        SET_BR(UART2_IBRD_R, Baud_Rate_Entero); //Parte entera del Baud Rate

        /*Parte fraccionaria del Baud Rate*/
        SET_BR(UART2_FBRD_R, (int)(UART_Baud_Rate_Frac(Baud_Rate_Fraccion)));
        break;

    case UART3_clk:
        CLEAR_BIT(UART3_CTL_R, 0);
        SET_BR(UART3_IBRD_R, Baud_Rate_Entero); //Parte entera del Baud Rate

        /*Parte fraccionaria del Baud Rate*/
        SET_BR(UART3_FBRD_R, (int)(UART_Baud_Rate_Frac(Baud_Rate_Fraccion)));
        break;

    case UART4_clk:
        CLEAR_BIT(UART4_CTL_R, 0);
        SET_BR(UART4_IBRD_R, Baud_Rate_Entero); //Parte entera del Baud Rate

        /*Parte fraccionaria del Baud Rate*/
        SET_BR(UART4_FBRD_R, (int)(UART_Baud_Rate_Frac(Baud_Rate_Fraccion)));
        break;

    case UART5_clk:
        CLEAR_BIT(UART5_CTL_R, 0);
        SET_BR(UART5_IBRD_R, Baud_Rate_Entero); //Parte entera del Baud Rate

        /*Parte fraccionaria del Baud Rate*/
        SET_BR(UART5_FBRD_R, (int)(UART_Baud_Rate_Frac(Baud_Rate_Fraccion)));
        break;

    case UART6_clk:
        CLEAR_BIT(UART6_CTL_R, 0);
        SET_BR(UART6_IBRD_R, Baud_Rate_Entero); //Parte entera del Baud Rate

        /*Parte fraccionaria del Baud Rate*/
        SET_BR(UART6_FBRD_R, (int)(UART_Baud_Rate_Frac(Baud_Rate_Fraccion)));
        break;

    case UART7_clk:
        CLEAR_BIT(UART7_CTL_R, 0);
        SET_BR(UART7_IBRD_R, Baud_Rate_Entero); //Parte entera del Baud Rate

        /*Parte fraccionaria del Baud Rate*/
        SET_BR(UART7_FBRD_R, (int)(UART_Baud_Rate_Frac(Baud_Rate_Fraccion)));
        break;
    }
}

void UART_Conf_Line(uint8_t UARTx_clk, bool Two_Stop, bool FIFO,
                    bool Parity_Enable, bool Parity_Select, uint16_t Word_Len){

    switch(UARTx_clk){
    case UART0_clk:

        SET_BR(UART0_LCRH_R, (Word_Len & 0x60)); //Longitud de la palabra en bits, escrito en Hexa

        if(Parity_Enable == true)
            SET_BIT(UART0_LCRH_R, 1);
        if(Parity_Select == true)
            SET_BIT(UART0_LCRH_R, 2);
        if(Two_Stop == true)
            SET_BIT(UART0_LCRH_R, 3);
        if(FIFO == true)
            SET_BIT(UART0_LCRH_R, 4);
        break;

    case UART1_clk:
        SET_BR(UART1_LCRH_R, (Word_Len & 0x60)); //Longitud de la palabra en bits, escrito en Hexa

        if(Parity_Enable == true)
            SET_BIT(UART1_LCRH_R, 1);
        if(Parity_Select == true)
            SET_BIT(UART1_LCRH_R, 2);
        if(Two_Stop == true)
            SET_BIT(UART1_LCRH_R, 3);
        if(FIFO == true)
            SET_BIT(UART1_LCRH_R, 4);
        break;

    case UART2_clk:
        SET_BR(UART2_LCRH_R, (Word_Len & 0x60)); //Longitud de la palabra en bits, escrito en Hexa

        if(Parity_Enable == true)
            SET_BIT(UART2_LCRH_R, 1);
        if(Parity_Select == true)
            SET_BIT(UART2_LCRH_R, 2);
        if(Two_Stop == true)
            SET_BIT(UART2_LCRH_R, 3);
        if(FIFO == true)
            SET_BIT(UART2_LCRH_R, 4);
        break;

    case UART3_clk:
        SET_BR(UART3_LCRH_R, (Word_Len & 0x60)); //Longitud de la palabra en bits, escrito en Hexa

        if(Parity_Enable == true)
            SET_BIT(UART3_LCRH_R, 1);
        if(Parity_Select == true)
            SET_BIT(UART3_LCRH_R, 2);
        if(Two_Stop == true)
            SET_BIT(UART3_LCRH_R, 3);
        if(FIFO == true)
            SET_BIT(UART3_LCRH_R, 4);
        break;

    case UART4_clk:
        UART4_LCRH_R |= Word_Len; //Longitud de la palabra en bits, escrito en Hexa

        if(Parity_Enable == true)
            SET_BIT(UART4_LCRH_R, 1);
        if(Parity_Select == true)
            SET_BIT(UART4_LCRH_R, 2);
        if(Two_Stop == true)
            SET_BIT(UART4_LCRH_R, 3);
        if(FIFO == true)
            SET_BIT(UART4_LCRH_R, 4);
        break;

    case UART5_clk:
        SET_BR(UART5_LCRH_R, (Word_Len & 0x60)); //Longitud de la palabra en bits, escrito en Hexa

        if(Parity_Enable == true)
            SET_BIT(UART5_LCRH_R, 1);
        if(Parity_Select == true)
            SET_BIT(UART5_LCRH_R, 2);
        if(Two_Stop == true)
            SET_BIT(UART5_LCRH_R, 3);
        if(FIFO == true)
            SET_BIT(UART5_LCRH_R, 4);
        break;

    case UART6_clk:
        SET_BR(UART6_LCRH_R, (Word_Len & 0x60)); //Longitud de la palabra en bits, escrito en Hexa

        if(Parity_Enable == true)
            SET_BIT(UART6_LCRH_R, 1);
        if(Parity_Select == true)
            SET_BIT(UART6_LCRH_R, 2);
        if(Two_Stop == true)
            SET_BIT(UART6_LCRH_R, 3);
        if(FIFO == true)
            SET_BIT(UART6_LCRH_R, 4);
        break;

    case UART7_clk:
        SET_BR(UART7_LCRH_R, (Word_Len & 0x60)); //Longitud de la palabra en bits, escrito en Hexa

        if(Parity_Enable == true)
            SET_BIT(UART7_LCRH_R, 1);
        if(Parity_Select == true)
            SET_BIT(UART7_LCRH_R, 2);
        if(Two_Stop == true)
            SET_BIT(UART7_LCRH_R, 3);
        if(FIFO == true)
            SET_BIT(UART7_LCRH_R, 4);
        break;
    }
}

void UART_Interrup(uint8_t UARTx_clk, uint8_t FIFO_Tx, uint8_t FIFO_Rx, bool End_Tx,
                   bool Error_Pari, bool Tx, bool Rx, uint8_t Prio){
    switch(UARTx_clk){
    case UART0_clk:

        /*FIFO INTERRUPCIÓN*/
        //UART0_IFLS_R = 0x0;
        //UART0_IFLS_R |= (FIFO_Tx & 0x07); //Int en la FIFO, parte de transmisión
        //UART0_IFLS_R |= (FIFO_Rx & 0x038); //Int en la FIFO, parte de recepción

        /*ENMASCARAMIENTO*/
        if(End_Tx == true)
            SET_BIT(UART0_IM_R, 11);
        if(Error_Pari == true)
            SET_BIT(UART0_IM_R, 8);
        if(Tx == true)
            SET_BIT(UART0_IM_R, 5);
        if(Rx == true)
            SET_BIT(UART0_IM_R, 4);

        /*NVIC*/
        NVIC_Act(INTE_UART0);

        /*PRIO*/
        SET_BR(NVIC_PRI1_R, (Prio << 13));

        /*Inicializar*/
        SET_BIT(UART0_CTL_R, 0);
        break;

    case UART1_clk:
        /*FIFO INTERRUPCIÓN*/
        UART1_IFLS_R = (FIFO_Tx & 0x07); //Int en la FIFO, parte de transmisión
        UART1_IFLS_R = (FIFO_Rx & 0x038); //Int en la FIFO, parte de recepción

        /*ENMASCARAMIENTO*/
        if(End_Tx == true)
            SET_BIT(UART1_IM_R, 11);
        if(Error_Pari == true)
            SET_BIT(UART1_IM_R, 8);
        if(Tx == true)
            SET_BIT(UART1_IM_R, 5);
        if(Rx == true)
            SET_BIT(UART1_IM_R, 4);

        /*NVIC*/
        NVIC_Act(INTE_UART1);

        /*PRIO*/
        SET_BR(NVIC_PRI1_R, (Prio << 21));

        /*Inicializar*/
        SET_BIT(UART1_CTL_R, 0);
        break;

    case UART2_clk:
        /*FIFO INTERRUPCIÓN*/
        UART2_IFLS_R = (FIFO_Tx & 0x07); //Int en la FIFO, parte de transmisión
        UART2_IFLS_R = (FIFO_Rx & 0x038); //Int en la FIFO, parte de recepción

        /*ENMASCARAMIENTO*/
        if(End_Tx == true)
            SET_BIT(UART2_IM_R, 11);
        if(Error_Pari == true)
            SET_BIT(UART2_IM_R, 8);
        if(Tx == true)
            SET_BIT(UART2_IM_R, 5);
        if(Rx == true)
            SET_BIT(UART2_IM_R, 4);

        /*NVIC*/
        NVIC_Act(INTE_UART2);

        /*PRIO*/
        SET_BR(NVIC_PRI8_R, (Prio << 13));

        /*Inicializar*/
        SET_BIT(UART2_CTL_R, 0);
        break;

    case UART3_clk:
        /*FIFO INTERRUPCIÓN*/
        UART3_IFLS_R = (FIFO_Tx & 0x07); //Int en la FIFO, parte de transmisión
        UART3_IFLS_R = (FIFO_Rx & 0x038); //Int en la FIFO, parte de recepción

        /*ENMASCARAMIENTO*/
        if(End_Tx == true)
            SET_BIT(UART3_IM_R, 11);
        if(Error_Pari == true)
            SET_BIT(UART3_IM_R, 8);
        if(Tx == true)
            SET_BIT(UART3_IM_R, 5);
        if(Rx == true)
            SET_BIT(UART3_IM_R, 4);

        /*NVIC*/
        NVIC_Act(INTE_UART3);

        /*PRIO*/
        SET_BR(NVIC_PRI14_R, (Prio << 5));

        /*Inicializar*/
        SET_BIT(UART3_CTL_R, 0);
        break;

    case UART4_clk:
        /*FIFO INTERRUPCIÓN*/
        //UART4_IFLS_R = (FIFO_Tx & 0x07); //Int en la FIFO, parte de transmisión
        //UART4_IFLS_R = (FIFO_Rx & 0x038); //Int en la FIFO, parte de recepción

        /*ENMASCARAMIENTO*/
        if(End_Tx == true)
            SET_BIT(UART4_IM_R, 11);
        if(Error_Pari == true)
            SET_BIT(UART4_IM_R, 8);
        if(Tx == true)
            SET_BIT(UART4_IM_R, 5);
        if(Rx == true)
            SET_BIT(UART4_IM_R, 4);

        /*NVIC*/
        NVIC_Act(INTE_UART4);

        /*PRIO*/
        SET_BR(NVIC_PRI14_R, (Prio << 13));

        /*Inicializar*/
        SET_BIT(UART4_CTL_R, 0);
        break;

    case UART5_clk:
        /*FIFO INTERRUPCIÓN*/
        UART5_IFLS_R = (FIFO_Tx & 0x07); //Int en la FIFO, parte de transmisión
        UART5_IFLS_R = (FIFO_Rx & 0x038); //Int en la FIFO, parte de recepción

        /*ENMASCARAMIENTO*/
        if(End_Tx == true)
            SET_BIT(UART5_IM_R, 11);
        if(Error_Pari == true)
            SET_BIT(UART5_IM_R, 8);
        if(Tx == true)
            SET_BIT(UART5_IM_R, 5);
        if(Rx == true)
            SET_BIT(UART5_IM_R, 4);

        /*NVIC*/
        NVIC_Act(INTE_UART5);

        /*PRIO*/
        SET_BR(NVIC_PRI14_R, (Prio << 21));

        /*Inicializar*/
        SET_BIT(UART5_CTL_R, 0);
        break;

    case UART6_clk:
        /*FIFO INTERRUPCIÓN*/
        UART6_IFLS_R = (FIFO_Tx & 0x07); //Int en la FIFO, parte de transmisión
        UART6_IFLS_R = (FIFO_Rx & 0x038); //Int en la FIFO, parte de recepción

        /*ENMASCARAMIENTO*/
        if(End_Tx == true)
            SET_BIT(UART6_IM_R, 11);
        if(Error_Pari == true)
            SET_BIT(UART6_IM_R, 8);
        if(Tx == true)
            SET_BIT(UART6_IM_R, 5);
        if(Rx == true)
            SET_BIT(UART6_IM_R, 4);

        /*NVIC*/
        NVIC_Act(INTE_UART6);

        /*PRIO*/
        SET_BR(NVIC_PRI14_R, (Prio << 29));

        /*Inicializar*/
        SET_BIT(UART6_CTL_R, 0);
        break;

    case UART7_clk:
        /*FIFO INTERRUPCIÓN*/
        UART7_IFLS_R = (FIFO_Tx & 0x07); //Int en la FIFO, parte de transmisión
        UART7_IFLS_R = (FIFO_Rx & 0x038); //Int en la FIFO, parte de recepción

        /*ENMASCARAMIENTO*/
        if(End_Tx == true)
            SET_BIT(UART7_IM_R, 11);
        if(Error_Pari == true)
            SET_BIT(UART7_IM_R, 8);
        if(Tx == true)
            SET_BIT(UART7_IM_R, 5);
        if(Rx == true)
            SET_BIT(UART7_IM_R, 4);

        /*NVIC*/
        NVIC_Act(INTE_UART7);

        /*PRIO*/
        SET_BR(NVIC_PRI15_R, (Prio << 5));

        /*Inicializar*/
        SET_BIT(UART7_CTL_R, 0);
        break;
    }
}
