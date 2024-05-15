/*
 * TIMER.h
 *
 *  Created on: 18 feb 2024
 *      Author: aresi
 */

#ifndef BIBLIOS_INCLU_TIMER_H_
#define BIBLIOS_INCLU_TIMER_H_

void TIMER_Init(uint8_t TIMx_clk);
void TIMER_Conf(uint8_t TIMx_clk, bool subTIMER, bool Mood_Period, bool direc, uint32_t Inter, uint16_t Pres);
void TIMER_Interrup_Conf(uint8_t TIMx_clk, bool subTIMER);


#endif /* BIBLIOS_INCLU_TIMER_H_ */
