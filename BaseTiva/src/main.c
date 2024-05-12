/**
 * main.c
 */

///*** PROGRAMA QUE CONFIGURA EL PERIFÉRICO SSI ***
//*** EN EL TIVA TM4C1294 COMO MAESTRO Y EL MCP41010 COMO ESCLAVO***

//Librerias
#include <stdint.h>
#include <stdbool.h>
#include "inclu/GPIO.h"
#include "inclu/TIMER.h"
#include "inclu/NVIC.h"
#include "inclu/SSI.h"
#include "inclu/Macros.h"
#include "inc/tm4c1294ncpdt.h" //TIVAWARE

uint8_t x = 0x00; // Valor inicial.

void SSI0_sendData (uint16_t dat) {
    // Envia dato de 16-bit
    SSI0_DR_R = dat; // envia dato.
}

void pot_setVal(uint8_t slider) {
    //Combine el valor del control deslizante con el código de comando de escritura.
    // Estructura del mensaje SPI: [comando (8-bits)][deslizador (8-bits)]
    SSI0_sendData(0x1100 | slider);
}

//*** INTERRUPCIONES ****//
void TIMER_Inte(){
    SET_BIT(TIMER1_ICR_R, 8);
    pot_setVal(x++);
}

void SSI0_Inte(void){
    CLEAR_BIT(SSI0_ICR_R, 6);
    SET_BIT(TIMER1_CTL_R, 8); //TIMER1 SUB B
}

//*** PROGRAMA PRINCIPAL ****//

void main(){
    /*INICIALIZACIÓN DE PERIFÉRICOS Y PUERTOS*/

    //Inicialización de Puerto A y Puerto N
    GPIO_Init(GPIOA_clk);
    GPIO_Init(GPION_clk);

    //Inicialización de TIMER 1
    TIMER_Init(TIM1_clk);

    //Inicialización de SSI 0
    SSI_Init(SSI0_clk);

    /*CONFIGURACIÓN DE PERIFÉRICOS*/

    //Configuración del TIMER 1-B
    TIMER_Conf(TIM1_clk, false, false, true, 0x80, 0x2);
    TIMER_Interrup_Conf(TIM1_clk, false);

    //Configuración de puerto PN
    GPIO_Conf(GPION_clk, 0, true, true, false, NULL, false, false);

    //Configuración de puerto PA
    GPIO_Conf(GPIOA_clk, 2, true, true, true, 15, false, false);
    GPIO_Conf(GPIOA_clk, 3, true, true, true, 15, false, false);
    GPIO_Conf(GPIOA_clk, 4, true, true, true, 15, false, false);

    //Configuración del periférico SSI0
    SSI_Conf(SSI0_clk, 0x2, 0x100, false, true, true, 0x0F);
    SSI_interrup_Conf(SSI0_clk);

    /*Primer dato enviado*/
    SSI0_CR1_R |= SSI_CR1_SSE; // Habilita SSI0.
    while ((SSI0_SR_R & SSI_SR_BSY) != 0); // espero si el bus está ocupado
    pot_setVal(x++);

    //*** PROCESO PRINCIPAL ****//
    while(1){
        XOR_BIT(GPIO_PORTN_DATA_R, 0);
    }
}
