/*
 * I2C.h
 *
 *  Created on: 12 feb 2024
 *      Author: aresi
 */

#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"

#ifndef BIBLIOS_INCLU_I2C_H_
#define BIBLIOS_INCLU_I2C_H_

#define I2C0_clk    0
#define I2C1_clk    1
#define I2C2_clk    2
#define I2C3_clk    3

#define I2C_100Kbps 100000
#define I2C_400Kbps 400000
#define I2C_1Mbps 1000000

#define I2C_MCS_ACK 0x00000008 //Transmmitter Acknowledge Enable
#define I2C_MCS_DATACK 0x00000008 // Data Acknowledge Enable
#define I2C_MCS_ADRACK 0x00000004 // Acknowledge Address
#define I2C_MCS_STOP 0x00000004 // Generate STOP
#define I2C_MCS_START 0x00000002 // Generate START
#define I2C_MCS_ERROR 0x00000002 // Error
#define I2C_MCS_RUN 0x00000001 // I2C Master Enable

void I2C_Init(uint8_t I2Cx_clk);
void I2C_Conf(uint8_t I2Cx_clk, bool I2C_Mastermode, uint8_t I2C_SCL_clock_Speed);

#endif /* BIBLIOS_INCLU_I2C_H_ */
