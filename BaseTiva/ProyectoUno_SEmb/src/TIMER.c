/*
 * TIMER.c
 *
 *  Created on: 18 feb 2024
 *      Author: aresi
 */
#include <stdint.h>
#include <stdbool.h>
#include "inclu/Macros.h"
#include "inclu/NVIC.h"
#include "inc/tm4c1294ncpdt.h"

void TIMER_Init(uint8_t TIMx_clk){
    SET_BIT(SYSCTL_RCGCTIMER_R, TIMx_clk);
}

void TIMER_Conf(uint8_t TIMx_clk, bool subTIMER, bool Mood_Period, bool direc, uint32_t Inter, uint16_t Pres){
    switch(TIMx_clk){

    case TIM0_clk:

        if(subTIMER == true){ //Configuramos subtimer A
            CLEAR_BIT(TIMER0_CTL_R, 1);
            SET_BR(TIMER0_CFG_R, 0x04);

            /*Modo de funcionamiento*/
            if(Mood_Period == true) //Modo periódico
                SET_BR(TIMER0_TAMR_R, 0x02);
            else //Modo One-Shot
                SET_BR(TIMER0_TAMR_R, 0x01);

            /*Dirección de conteo*/
            if(direc == true) //Modo UP
                SET_BIT(TIMER0_TAMR_R, 4);
            else    //Modo DOWN
                CLEAR_BIT(TIMER0_TAMR_R, 4);

            SET_BR(TIMER0_TAILR_R, Inter); //Cargar con F424
            SET_BR(TIMER0_TAPR_R, Pres);    //Carga el prescalador a 256
            break;

        }else{  //Configuramos subtimer B
            CLEAR_BIT(TIMER0_CTL_R, 8);
            SET_BR(TIMER0_CFG_R, 0x04);

            /*Modo de funcionamiento*/
            if(Mood_Period == true) //Modo periódico
                SET_BR(TIMER0_TBMR_R, 0x02);
            else //Modo One-Shot
                SET_BR(TIMER0_TBMR_R, 0x01);

            /*Dirección de conteo*/
            if(direc == true) //Modo UP
                SET_BIT(TIMER0_TBMR_R, 4);
            else    //Modo DOWN
                CLEAR_BIT(TIMER0_TBMR_R, 4);

            SET_BR(TIMER0_TBILR_R, Inter); //Cargar con F424 para un segundo
            SET_BR(TIMER0_TBPR_R, Pres);    //Carga el prescalador a 256
            break;
        }

    case TIM1_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            CLEAR_BIT(TIMER1_CTL_R, 1);
            SET_BR(TIMER1_CFG_R, 0x04);

            /*Modo de funcionamiento*/
            if(Mood_Period == true) //Modo periódico
                SET_BR(TIMER1_TAMR_R, 0x02);
            else //Modo One-Shot
                SET_BR(TIMER1_TAMR_R, 0x01);

            /*Dirección de conteo*/
            if(direc == true) //Modo UP
                SET_BIT(TIMER1_TAMR_R, 4);
            else    //Modo DOWN
                CLEAR_BIT(TIMER1_TAMR_R, 4);

            SET_BR(TIMER1_TAILR_R, Inter); //Cargar con F424
            SET_BR(TIMER1_TAPR_R, Pres);    //Carga el prescalador a 256
            break;

        }else{  //Configuramos subtimer B
            CLEAR_BIT(TIMER1_CTL_R, 8);
            SET_BR(TIMER1_CFG_R, 0x04);

            /*Modo de funcionamiento*/
            if(Mood_Period == true) //Modo periódico
                SET_BR(TIMER1_TBMR_R, 0x02);
            else //Modo One-Shot
                SET_BR(TIMER1_TBMR_R, 0x01);

            /*Dirección de conteo*/
            if(direc == true) //Modo UP
                SET_BIT(TIMER1_TBMR_R, 4);
            else    //Modo DOWN
                CLEAR_BIT(TIMER1_TBMR_R, 4);

            SET_BR(TIMER1_TBILR_R, Inter); //Cargar con F424
            SET_BR(TIMER1_TBPR_R, Pres);    //Carga el prescalador a 256
            break;
        }

    case TIM2_clk:

            if(subTIMER == true){ //Configuramos subtimer A
                CLEAR_BIT(TIMER2_CTL_R, 1);
                SET_BR(TIMER2_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER2_TAMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER2_TAMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER2_TAMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER2_TAMR_R, 4);

                SET_BR(TIMER2_TAILR_R, Inter); //Cargar con F424
                SET_BR(TIMER2_TAPR_R, Pres);    //Carga el prescalador a 256
                break;

            }else{  //Configuramos subtimer B
                CLEAR_BIT(TIMER2_CTL_R, 8);
                SET_BR(TIMER2_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER2_TBMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER2_TBMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER2_TBMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER2_TBMR_R, 4);

                SET_BR(TIMER2_TBILR_R, Inter); //Cargar con F424 para un segundo
                SET_BR(TIMER2_TBPR_R, Pres);    //Carga el prescalador a 256
                break;
            }

        case TIM3_clk:
            if(subTIMER == true){ //Configuramos subtimer A
                CLEAR_BIT(TIMER3_CTL_R, 1);
                SET_BR(TIMER3_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER3_TAMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER3_TAMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER3_TAMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER3_TAMR_R, 4);

                SET_BR(TIMER3_TAILR_R, Inter); //Cargar con F424
                SET_BR(TIMER3_TAPR_R, Pres);    //Carga el prescalador a 256
                break;

            }else{  //Configuramos subtimer B
                CLEAR_BIT(TIMER3_CTL_R, 8);
                SET_BR(TIMER3_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER3_TBMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER3_TBMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER3_TBMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER3_TBMR_R, 4);

                SET_BR(TIMER3_TBILR_R, Inter); //Cargar con F424 para un segundo
                SET_BR(TIMER3_TBPR_R, Pres);    //Carga el prescalador a 256
                break;
            }
/*==============================*/
        case TIM4_clk:

            if(subTIMER == true){ //Configuramos subtimer A
                CLEAR_BIT(TIMER4_CTL_R, 1);
                SET_BR(TIMER4_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER4_TAMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER4_TAMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER4_TAMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER4_TAMR_R, 4);

                SET_BR(TIMER4_TAILR_R, Inter); //Cargar con F424
                SET_BR(TIMER4_TAPR_R, Pres);    //Carga el prescalador a 256
                break;

            }else{  //Configuramos subtimer B
                CLEAR_BIT(TIMER4_CTL_R, 8);
                SET_BR(TIMER4_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER4_TBMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER4_TBMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER4_TBMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER4_TBMR_R, 4);

                SET_BR(TIMER4_TBILR_R, Inter); //Cargar con F424 para un segundo
                SET_BR(TIMER4_TBPR_R, Pres);    //Carga el prescalador a 256
                break;
            }

        case TIM5_clk:
            if(subTIMER == true){ //Configuramos subtimer A
                CLEAR_BIT(TIMER5_CTL_R, 1);
                SET_BR(TIMER5_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER5_TAMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER5_TAMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER5_TAMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER5_TAMR_R, 4);

                SET_BR(TIMER5_TAILR_R, Inter); //Cargar con F424
                SET_BR(TIMER5_TAPR_R, Pres);    //Carga el prescalador a 256
                break;

            }else{  //Configuramos subtimer B
                CLEAR_BIT(TIMER5_CTL_R, 8);
                SET_BR(TIMER5_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER5_TBMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER5_TBMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER5_TBMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER5_TBMR_R, 4);

                SET_BR(TIMER5_TBILR_R, Inter); //Cargar con F424 para un segundo
                SET_BR(TIMER5_TBPR_R, Pres);    //Carga el prescalador a 256
                break;
            }

        case TIM6_clk:

            if(subTIMER == true){ //Configuramos subtimer A
                CLEAR_BIT(TIMER6_CTL_R, 1);
                SET_BR(TIMER6_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER6_TAMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER6_TAMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER6_TAMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER6_TAMR_R, 4);

                SET_BR(TIMER6_TAILR_R, Inter); //Cargar con F424
                SET_BR(TIMER6_TAPR_R, Pres);    //Carga el prescalador a 256
                break;

            }else{  //Configuramos subtimer B
                CLEAR_BIT(TIMER6_CTL_R, 8);
                SET_BR(TIMER6_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER6_TBMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER6_TBMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER6_TBMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER6_TBMR_R, 4);

                SET_BR(TIMER6_TBILR_R, Inter); //Cargar con F424 para un segundo
                SET_BR(TIMER6_TBPR_R, Pres);    //Carga el prescalador a 256
                break;
            }

            case TIM7_clk:
            if(subTIMER == true){ //Configuramos subtimer A
                CLEAR_BIT(TIMER7_CTL_R, 1);
                SET_BR(TIMER7_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER7_TAMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER7_TAMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER7_TAMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER7_TAMR_R, 4);

                SET_BR(TIMER7_TAILR_R, Inter); //Cargar con F424
                SET_BR(TIMER7_TAPR_R, Pres);    //Carga el prescalador a 256
                break;

            }else{  //Configuramos subtimer B
                CLEAR_BIT(TIMER7_CTL_R, 8);
                SET_BR(TIMER7_CFG_R, 0x04);

                /*Modo de funcionamiento*/
                if(Mood_Period == true) //Modo periódico
                    SET_BR(TIMER7_TBMR_R, 0x02);
                else //Modo One-Shot
                    SET_BR(TIMER7_TBMR_R, 0x01);

                /*Dirección de conteo*/
                if(direc == true) //Modo UP
                    SET_BIT(TIMER7_TBMR_R, 4);
                else    //Modo DOWN
                    CLEAR_BIT(TIMER7_TBMR_R, 4);

                SET_BR(TIMER7_TBILR_R, Inter); //Cargar con F424 para un segundo
                SET_BR(TIMER7_TBPR_R, Pres);    //Carga el prescalador a 256
                break;
            }
    }
}

void TIMER_Interrup_Conf(uint8_t TIMx_clk, bool subTIMER){
    switch(TIMx_clk){
    case TIM0_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            SET_BR(TIMER0_IMR_R, 0x1);
            SET_BR(TIMER0_ICR_R, 0x1);
            NVIC_Act(INTE_TIMA0);
            break;
        }else{  //Configuramos subtimer B
            SET_BIT(TIMER0_IMR_R, 8);
            SET_BIT(TIMER0_ICR_R, 8);
            NVIC_Act(INTE_TIMB0);
            break;
        }

    case TIM1_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            SET_BR(TIMER1_IMR_R, 0x1);
            SET_BR(TIMER1_ICR_R, 0x1);
            NVIC_Act(INTE_TIMA1);
            break;
        }else{  //Configuramos subtimer B
            SET_BIT(TIMER1_IMR_R, 8);
            SET_BIT(TIMER1_ICR_R, 8);
            NVIC_Act(INTE_TIMB1);
            break;
        }

    case TIM2_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            SET_BR(TIMER2_IMR_R, 0x1);
            SET_BR(TIMER2_ICR_R, 0x1);
            NVIC_Act(INTE_TIMA2);
            break;
        }else{  //Configuramos subtimer B
            SET_BIT(TIMER2_IMR_R, 8);
            SET_BIT(TIMER2_ICR_R, 8);
            NVIC_Act(INTE_TIMB2);
            break;
        }

    case TIM3_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            SET_BR(TIMER3_IMR_R, 0x1);
            SET_BR(TIMER3_ICR_R, 0x1);
            NVIC_Act(INTE_TIMA3);
            break;
        }else{  //Configuramos subtimer B
            SET_BIT(TIMER3_IMR_R, 8);
            SET_BIT(TIMER3_ICR_R, 8);
            NVIC_Act(INTE_TIMB3);
            break;
        }

    case TIM4_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            SET_BR(TIMER4_IMR_R, 0x1);
            SET_BR(TIMER4_ICR_R, 0x1);
            NVIC_Act(INTE_TIMA4);
            break;
        }else{  //Configuramos subtimer B
            SET_BIT(TIMER4_IMR_R, 8);
            SET_BIT(TIMER4_ICR_R, 8);
            NVIC_Act(INTE_TIMB4);
            break;
        }

    case TIM5_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            SET_BR(TIMER5_IMR_R, 0x1);
            SET_BR(TIMER5_ICR_R, 0x1);
            NVIC_Act(INTE_TIMA5);
            break;
        }else{  //Configuramos subtimer B
            SET_BIT(TIMER5_IMR_R, 8);
            SET_BIT(TIMER5_ICR_R, 8);
            NVIC_Act(INTE_TIMB5);
            break;
        }

    case TIM6_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            SET_BR(TIMER6_IMR_R, 0x1);
            SET_BR(TIMER6_ICR_R, 0x1);
            NVIC_Act(INTE_TIMA6);
            break;
        }else{  //Configuramos subtimer B
            SET_BIT(TIMER6_IMR_R, 8);
            SET_BIT(TIMER6_ICR_R, 8);
            NVIC_Act(INTE_TIMB6);
            break;
        }

    case TIM7_clk:
        if(subTIMER == true){ //Configuramos subtimer A
            SET_BR(TIMER7_IMR_R, 0x1);
            SET_BR(TIMER7_ICR_R, 0x1);
            NVIC_Act(INTE_TIMA7);
            break;
        }else{  //Configuramos subtimer B
            SET_BIT(TIMER7_IMR_R, 8);
            SET_BIT(TIMER7_ICR_R, 8);
            NVIC_Act(INTE_TIMB7);
            break;
        }
    }
}
