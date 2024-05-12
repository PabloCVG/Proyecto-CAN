/*
 * SSI.h
 *
 *  Created on: 18 feb 2024
 *      Author: aresi
 */

#ifndef INCLU_SSI_H_
#define INCLU_SSI_H_

void SSI_Init(uint8_t SSIx_clk);
void SSI_Conf(uint8_t SSIx_clk, uint16_t Clock_Pres, uint16_t SCR, bool Formato_Trama, bool Polarity, bool Phase, uint8_t Tamaño_Trama);
void SSI_interrup_Conf(uint8_t SSIx_clk);


#endif /* INCLU_SSI_H_ */
