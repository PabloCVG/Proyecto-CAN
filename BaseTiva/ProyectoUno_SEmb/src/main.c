/**
 * main.c
 */

///*** PROGRAMA QUE CONFIGURA EL PERIFÉRICO SSI ***
//*** EN EL TIVA TM4C1294 COMO MAESTRO Y EL MCP41010 COMO ESCLAVO***

//Librerias
#include <stdint.h>
#include <stdbool.h>
#include "inclu/GPIO.h"
#include "inclu/NVIC.h"
#include "inclu/UART.h"
#include "inclu/Macros.h"
#include "inc/tm4c1294ncpdt.h" //TIVAWARE
int x = 0;

//*** INTERRUPCIONES ****//
void UART4_Interrup(){
    char lectura = '0';

    lectura = UART4_DR_R;

    if (lectura == 'A'){
        LED_On(LED1);
    }else if(lectura == 'B'){
        LED_Off(LED1);
    }

    SET_BIT(UART4_ICR_R, 4);
}

//*** PROGRAMA PRINCIPAL ****//

void main(){
    /*INICIALIZACIÓN DE PERIFÉRICOS Y PUERTOS*/
    UART_Init(UART4_clk);

    //Inicialización de Puerto K y Puerto N
    GPIO_Init(GPION_clk);
    GPIO_Init(GPIOK_clk);

    /*CONFIGURACIÓN DE PERIFÉRICOS*/

    //Configuración de puerto PN
    GPIO_Conf(GPION_clk, 1, true, true, false, NULL, false, false);
    GPIO_Conf(GPION_clk, 0, true, true, false, NULL, false, false);

    //Configuración de puerto PK
    GPIO_Conf(GPIOK_clk, 1, true, true, true, 1, false, false);
    GPIO_Conf(GPIOK_clk, 0, false, true, true, 1, false, false);

    /*Configuración del periférico*/

    UART_Set_Baud_Rate(UART4_clk, 104, 0.1667);
    UART_Conf_Line(UART4_clk, false, false, false, false, 0x60);
    UART_Interrup(UART4_clk, NULL, NULL, false, false, false, true, 5);

    //*** PROCESO PRINCIPAL ****//
    while(1){
        while(x != 50000){
            x++;
        }
        x = 0;
        XOR_BIT(GPIO_PORTN_DATA_R, 0);
    }
}
