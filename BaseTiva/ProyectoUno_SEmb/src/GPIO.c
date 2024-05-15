/*
 * GPIO.c
 *
 *  Created on: 30 ene 2024
 *      Author: aresi
 */

#include <stdbool.h>
#include <stdint.h>
#include "inclu/GPIO.h"
#include "inclu/Macros.h"
#include "inc/tm4c1294ncpdt.h"

/*Función de inicialización para GPIOx: x = A, B, C, D...*/
void GPIO_Init(uint8_t GPIOx_clk){
    SET_BIT(SYSCTL_RCGCGPIO_R, (GPIOx_clk)); //Activa reloj del puerto
}

/*Función de inicialización para GPIOx: x = A, B, C, D...*/
void GPIO_Conf(uint8_t GPIOx_clk, uint8_t GPIO_pin, bool GPIO_dir, bool GPIO_DEN,
               bool GPIO_AF, uint8_t GPIO_AF_Port_Mux_Control, bool GPIO_PDR, bool GPIO_ODrain){

    switch(GPIOx_clk){
    case GPIOA_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTA_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTA_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTA_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTA_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }
        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTA_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTA_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTA_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOB_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTB_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTB_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTB_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTB_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }
        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTB_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTB_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTB_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOC_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
           SET_BIT(GPIO_PORTC_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTC_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTC_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTC_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTC_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTC_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTC_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOD_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
           SET_BIT(GPIO_PORTD_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTD_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTD_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTD_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTD_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTD_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTD_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOE_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTE_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTE_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTE_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTE_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTE_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTE_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTE_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOF_clk:

        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTF_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTF_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTF_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTF_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTF_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTF_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTF_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOG_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTG_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTG_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTG_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTG_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTG_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTG_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTG_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOH_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTH_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTH_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTH_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTH_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTH_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTH_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTH_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOJ_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTJ_AHB_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTJ_AHB_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTJ_AHB_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTJ_AHB_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTJ_AHB_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTJ_AHB_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTJ_AHB_PDR_R, GPIO_pin);
        break;

    case GPIOK_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTK_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTK_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTK_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTK_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTK_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTK_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTK_PDR_R, GPIO_pin);
        break;

    case GPIOL_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTL_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTL_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTL_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTL_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTL_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTL_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTL_PDR_R, GPIO_pin);
        break;

    case GPIOM_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTM_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTM_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTM_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTM_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTM_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTM_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTM_PDR_R, GPIO_pin);
        break;

    case GPION_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTN_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTN_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTN_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTN_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTN_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTN_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTN_PDR_R, GPIO_pin);
        break;

    case GPIOP_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTP_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTP_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTP_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTP_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTP_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTP_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTP_PDR_R, GPIO_pin);
        break;

    case GPIOQ_clk:
        if(GPIO_ODrain == true) /*Activamos Open Drain en el pin correspondiente del puerto GPIO*/
            SET_BIT(GPIO_PORTQ_ODR_R, GPIO_pin);

        if(GPIO_dir == true) /*Marca dirección de salida*/
            SET_BIT(GPIO_PORTQ_DIR_R, GPIO_pin);

        if(GPIO_AF == true){
            SET_BIT(GPIO_PORTQ_AFSEL_R, GPIO_pin); //Activa la función alterna
            /*Función que determina función alterna en el pin deseado
             * El valor debe ser propuesto por el usuario
             * */
            SET_AFx_BIT(GPIO_PORTQ_PCTL_R, (GPIO_AF_Port_Mux_Control), (GPIO_pin));
        }

        if(GPIO_DEN == true)
            SET_BIT(GPIO_PORTQ_DEN_R, (GPIO_pin)); //Función digital activa
        else
            CLEAR_BIT(GPIO_PORTQ_DEN_R, (GPIO_pin));

        if(GPIO_PDR == true) //Resistencia de Pull Down
            SET_BIT(GPIO_PORTQ_PDR_R, GPIO_pin);
        break;

    default:
        return;
    }
}

/*Funció para encender un LED*/
void LED_On(uint8_t LED_pin){
    switch(LED_pin){
    case LED1:
        SET_BIT(GPIO_PORTN_DATA_R, 1);
        break;

    case LED2:
        SET_BIT(GPIO_PORTN_DATA_R, 0);
        break;

    case LED3:
        SET_BIT(GPIO_PORTF_AHB_DATA_R, 4);
        break;

    case LED4:
        SET_BIT(GPIO_PORTF_AHB_DATA_R, 0);
        break;
    }
}

/*Funció para apagar un LED*/
void LED_Off(uint8_t LED_pin){
    switch(LED_pin){
    case LED1:
        CLEAR_BIT(GPIO_PORTN_DATA_R, 1);
        break;

    case LED2:
        CLEAR_BIT(GPIO_PORTN_DATA_R, 0);
        break;

    case LED3:
        CLEAR_BIT(GPIO_PORTF_AHB_DATA_R, 4);
        break;

    case LED4:
        CLEAR_BIT(GPIO_PORTF_AHB_DATA_R, 0);
        break;
    }
}
