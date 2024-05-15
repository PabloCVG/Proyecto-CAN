/*
 * UART.h
 *
 *  Created on: 30 ene 2024
 *      Author: aresi
 */

/*Bibliotecas y cabeceros*/

#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"

#ifndef UART_H_
#define UART_H_

void UART_Init(uint8_t UARTx_clk);
void UART_Set_Baud_Rate(uint8_t UARTx_clk, uint32_t Baud_Rate_Entero, float Baud_Rate_Fraccion);
void UART_Conf_Line(uint8_t UARTx_clk, bool Two_Stop, bool FIFO,
                    bool Parity_Enable, bool Parity_Select, uint16_t Word_Len);
void UART_Interrup(uint8_t UARTx_clk, uint8_t FIFO_Tx, uint8_t FIFO_Rx, bool End_Tx,
                   bool Error_Pari, bool Tx, bool Rx, uint8_t Prio);
#endif /* UART_H_ */
