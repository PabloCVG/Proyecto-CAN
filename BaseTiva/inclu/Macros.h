/*
 * Macros.h
 *
 *  Created on: 30 ene 2024
 *      Author: aresi
 */

#ifndef BIBLIOS_INCLU_MACROS_H_
#define BIBLIOS_INCLU_MACROS_H_

/*FUNCIONES MACRO PARA OPERACIÓN OR, AND negada y XOR*/

#define SET_BIT(registro, pin)   ((registro) |= (1 << pin))
#define CLEAR_BIT(registro, pin)   ((registro) &= ~(1 << pin))
#define XOR_BIT(registro, pin)   ((registro) ^= (1 << pin))

/*FUNCIONES MACRO PARA OPERAR FUNCIÓN ALTERNA EN GPIO*/

#define SET_AFx_BIT(registro, GPIO_AF_Port_Mux_Control, pin)   ((registro) |= (GPIO_AF_Port_Mux_Control << pin*4))

/*FUNCIÓN MACRO PARA COLOCAR BAUD RATE PARA UART O PARA COLOCAR VALORES HEXADECIMALES*/

#define SET_BR(registro, Baud_Rate)   ((registro) |= Baud_Rate)

/*DECLARACIÓN DE MACROS PARA USO DE GPIOx_clk*/

#define GPIOA_clk 0
#define GPIOB_clk 1
#define GPIOC_clk 2
#define GPIOD_clk 3
#define GPIOE_clk 4
#define GPIOF_clk 5
#define GPIOG_clk 6
#define GPIOH_clk 7
#define GPIOJ_clk 8
#define GPIOK_clk 9
#define GPIOL_clk 10
#define GPIOM_clk 11
#define GPION_clk 12
#define GPIOP_clk 13
#define GPIOQ_clk 14

/*DECLARACIÓN DE MACROS PARA USO DE NVIC*/

#define NULL 0

/*DECLARACIÓN DE MACROS PARA USO DE LEDS*/

#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4

/*MACROS PARA REALIZAR CONFIGURACIÓN DE UARTx_clk*/

#define UART0_clk 0
#define UART1_clk 1
#define UART2_clk 2
#define UART3_clk 3
#define UART4_clk 4
#define UART5_clk 5
#define UART6_clk 6
#define UART7_clk 7

/*NVIC INTERRUPCIONES
 * UART*/

#define INTE_UART0  5
#define INTE_UART1  6
#define INTE_UART2  33
#define INTE_UART3  56
#define INTE_UART4  57
#define INTE_UART5  58
#define INTE_UART6  59
#define INTE_UART7  60

/*DECLARACIÓN DE MACROS PARA USO DE TIMx_clk*/

#define TIM0_clk    0
#define TIM1_clk    1
#define TIM2_clk    2
#define TIM3_clk    3
#define TIM4_clk    4
#define TIM5_clk    5
#define TIM6_clk    6
#define TIM7_clk    7

/*NVIC INTERRUPCIONES
 * TIMER*/

#define INTE_TIMA0  19
#define INTE_TIMB0  20
#define INTE_TIMA1  21
#define INTE_TIMB1  22
#define INTE_TIMA2  23
#define INTE_TIMB2  24
#define INTE_TIMA3  35
#define INTE_TIMB3  36
#define INTE_TIMA4  63
#define INTE_TIMB4  64
#define INTE_TIMA5  65
#define INTE_TIMB5  66
#define INTE_TIMA6  98
#define INTE_TIMB6  99
#define INTE_TIMA7  100
#define INTE_TIMB7  101

/*DECLARACIÓN DE MACROS PARA USO DE SSIx_clk*/

#define SSI0_clk    0
#define SSI1_clk    1
#define SSI2_clk    2
#define SSI3_clk    3

/*NVIC INTERRUPCIONES
 * SSI*/

#define INTE_SSI0   7
#define INTE_SSI1   34
#define INTE_SSI2   54
#define INTE_SSI3   55


#endif /* BIBLIOS_INCLU_MACROS_H_ */
