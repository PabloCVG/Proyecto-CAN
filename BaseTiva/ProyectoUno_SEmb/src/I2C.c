/*
 * I2C.c
 *
 *  Created on: 12 feb 2024
 *      Author: aresi
 */

#include <stdbool.h>
#include <stdint.h>
#include "inclu/GPIO.h"
#include "inclu/Macros.h"
#include "inclu/I2C.h"

void I2C_Init(uint8_t I2Cx_clk){
    SET_BIT(SYSCTL_RCGCI2C_R, I2Cx_clk);
}

int I2C_TPR(I2C_SCL_clock_Speed){
    return (int)((16000000/(2*(6+4)*(I2C_SCL_clock_Speed)))-1);
}

void I2C_Conf(uint8_t I2Cx_clk, bool I2C_Mastermode, uint8_t I2C_SCL_clock_Speed){

    switch(I2Cx_clk){
    case I2C0_clk:
        //Modo Maestro
        if(I2C_Mastermode == true)
            SET_BIT(I2C0_MCR_R, 4);
       //Modo Esclavo
        else
            SET_BIT(I2C0_MCR_R, 5);

        /*CALCULO DEL Timer Period Register*/
        I2C0_MTPR_R |= I2C_TPR(I2C_SCL_clock_Speed);
        break;

    case I2C1_clk:
        //Modo Maestro
        if(I2C_Mastermode == true)
            SET_BIT(I2C1_MCR_R, 4);
       //Modo Esclavo
        else
            SET_BIT(I2C1_MCR_R, 5);

        /*CALCULO DEL Timer Period Register*/
        I2C1_MTPR_R |= I2C_TPR(I2C_SCL_clock_Speed);
        break;
    }
}
