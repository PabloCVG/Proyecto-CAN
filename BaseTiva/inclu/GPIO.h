/*
 * GPIO.h
 *
 *  Created on: 30 ene 2024
 *      Author: aresi
 */

/*ENCENDER Y APAGAR LEDS
 *LED1 == PN1
 *LED2 == PN0
 *LED3 == PF4
 *LED4 == PF0
 * */

/*USO DE PUSH BOTTON
 * PUSH1 == PJ0
 * PUSH2 == PJ1
 * */


#ifndef BIBLIOS_INC_GPIO_H_
#define BIBLIOS_INC_GPIO_H_

/*Funciones de configuración e inicialización*/
void GPIO_Init(uint8_t GPIOx_clk);
void GPIO_Conf(uint8_t GPIOx_clk, uint8_t GPIO_pin, bool GPIO_dir, bool GPIO_DEN,
               bool GPIO_AF, uint8_t GPIO_AF_Port_Mux_Control, bool GPIO_PDR, bool GPIO_ODrain);

/*Funciones de encendido y apagado de LEDS */
void LED_On(uint8_t LED_pin);
void LED_Off(uint8_t LED_pin);

#endif /* BIBLIOS_INC_GPIO_H_ */
