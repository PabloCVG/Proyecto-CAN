/*
 * NVIC.c
 *
 *  Created on: 1 feb 2024
 *      Author: aresi
 */

#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"
#include "inclu/Macros.h"

/*Función de activación de interrupción en NVIC para GPIO*/

void NVIC_Act(uint8_t Interrup){

    if (Interrup < 32 && Interrup >= 0){

        SET_BIT(NVIC_EN0_R, Interrup);

    }else if (Interrup < 64 && Interrup >= 32){

        SET_BIT(NVIC_EN1_R, (Interrup - 32));

    }else if (Interrup < 96 && Interrup >= 64){

        SET_BIT(NVIC_EN2_R, (Interrup - 64));

    }else if (Interrup < 114 && Interrup >= 96){

        SET_BIT(NVIC_EN3_R, (Interrup - 96));
    }
}



