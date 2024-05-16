#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"
#include "IEEE_CAN.h"
#include "driverlib/sysctl.h"

uint64_t Rx[3];
uint8_t count_int=1;
uint8_t C=1;
uint16_t W=0;
uint64_t Ciro = 0x111;
uint64_t Jaime = 0x444;
uint64_t Pablo = 0x555;
uint64_t Joshua = 0x222;


//--------------------------------------------------------------------
//%%%%%%    INICIALIZACI�N DE PUERTOS ASOCIADOS AL CAN0    %%%%%%%%%%%
//                 CAN0Rx: PA0    CAN0Tx: PA1
//--------------------------------------------------------------------
void Leds(void);
void Config_Puertos(void){                      //(TM4C1294NCPDT)
    SYSCTL_RCGCGPIO_R|=0x01;                     //Reloj Puerto A
    while((SYSCTL_PRGPIO_R&0x01)==0){}
    GPIO_PORTA_AHB_AFSEL_R=0x3;                 //PA0 y PA1 funci�n alterna
    GPIO_PORTA_AHB_PCTL_R=0x77;                 //Funci�n CAN a los pines PA0-PA1
    GPIO_PORTA_AHB_DEN_R=0x3;   
    SYSCTL_RCGCGPIO_R |= 0X1100;    // Habilita reloj para puerto J y N
    while((SYSCTL_PRGPIO_R & 0x1100)==0){}

  GPIO_PORTJ_AHB_DIR_R &= ~0x01;       // (c) PJ0 dirección entrada - boton SW1
  GPIO_PORTJ_AHB_DEN_R |= 0x01;        //     PJ0 se habilita
  GPIO_PORTJ_AHB_PUR_R |= 0x01;        //     habilita weak pull-up on PJ1
  GPIO_PORTJ_AHB_IS_R &= ~0x01;        // (d) PJ1 es sensible por flanco
  GPIO_PORTJ_AHB_IBE_R &= ~0x01;       //     PJ1 no es sensible a dos flancos
  GPIO_PORTJ_AHB_IEV_R &= ~0x01;       //     PJ1 detecta eventos de flanco de bajada
  GPIO_PORTJ_AHB_ICR_R = 0x01;         // (e) limpia la bandera 0
  GPIO_PORTJ_AHB_IM_R |= 0x01;         // (f) Se desenmascara la interrupcion PJ0 y se envia al controlador de interrupciones
  NVIC_PRI12_R = (NVIC_PRI12_R&0x00FFFFFF)|0x00000000; // (g) prioridad 0 (pag 159)         //(h) habilita la interrupción 51 en NVIC (Pag. 154)
  NVIC_EN1_R|=((1<<(51-32)) & 0xFFFFFFFF);

  //Para LEDS
  GPIO_PORTN_DIR_R |= 0X01;   // PN0 como salida
  GPIO_PORTN_DEN_R |= 0X01;   // Habilita PN0
  GPIO_PORTN_DATA_R &= ~0x01;     // Se apaga PN0
}


//--------------------------------------------------------------------
//%%%%%%%%%%%%%%%%%%%%    INICIALIZACI�N CAN0     %%%%%%%%%%%%%%%%%%%%
//--------------------------------------------------------------------
void Config_CAN(void){
    SYSCTL_RCGCCAN_R=0x1;                       //Reloj modulo 0 CAN
    while((SYSCTL_PRCAN_R&0x1)==0){}
                                                //Bit Rate= 1 Mbps      CAN clock=16 [Mhz]
    CAN0_CTL_R=0x41;                            //Deshab. modo prueba, Hab. cambios en la config. y hab. inicializacion
    CAN0_BIT_R=0x4900;                          //TSEG2=4   TSEG1=9    SJW=0    BRP=0
                                                //Lenght Bit time=[TSEG2+TSEG1+3]*tq
                                                //               =[(Phase2-1)+(Prop+Phase1-1)+3]*tq
    CAN0_CTL_R&=~0x41;                          //Hab. cambios en la config. y deshab. inicializacion
    CAN0_CTL_R|=0x02;                            //Hab de interrupci�n en el m�dulo CAN
    NVIC_EN1_R|=((1<<(38-32)) & 0xFFFFFFFF);    //(TM4C1294NCPDT)

}


void CAN_Error(void){
    static int ent=0;
    if(CAN0_STS_R&0x80){
        if(ent){
            NVIC_APINT_R|=0x4;                      //Reinicio de todo el sistema
        }else{
            CAN0_CTL_R=0x41;                        //Hab. cambios en la config. y hab. inicializacion
            CAN0_CTL_R|=0x80;                       //Hab. modo prueba
            CAN0_TST_R|=0x4;                        //Hab. Modo silencio
            CAN0_CTL_R&=~0x41;                      //Hab. cambios en la config. y deshab. inicializacion
            SysCtlDelay(333333);
            CAN0_CTL_R=0x41;                        //Hab. cambios en la config. y hab. inicializacion
            CAN0_TST_R&=~0x4;                       //Deshab. Modo silencio
            CAN0_CTL_R&=~0x41;                      //Hab. cambios en la config. y deshab. inicializacion
            ent++;
        }
    }
}

//--------------------------------------------------------------------
//%%%%%%%%%%%%%%%%%    INTERRUPCI�N DEL CAN0    %%%%%%%%%%%%%%%%%%%%%%
//--------------------------------------------------------------------
void Inter_CAN0(void){
    uint8_t NoInt;
    NoInt=CAN0_INT_R;                           //Lectura del apuntador de interrupciones
    CAN0_STS_R&=~0x10;                          //Limpieza del bit de recepcion
    if(NoInt==0x1){
        Rx[0]=CAN_Rx(NoInt);                //Recepci�n de datos
    }
    if(NoInt==0x3){
        Rx[1]=CAN_Rx(NoInt);                //Recepci�n de datos
        Leds();
    }
    if(NoInt==0x5){
        Rx[2]=CAN_Rx(NoInt);                //Recepci�n de datos
        Leds();
    }
    //    CAN_Error();
}
void GPIOPortJ_Handler(void)
{
  GPIO_PORTJ_AHB_ICR_R = 0x01;      // bandera0 de confirmación
  count_int = count_int + 1;
  C++;
  CAN_Memoria_Dato(0xCC|(C<<8),0x04);
  CAN_Memoria_Dato(0xDD|(C<<8),0x06);
  switch (count_int)
  {
  case 2:
CAN_Tx(0x3);
Leds();
    break;
  case 3:
//CAN_Tx(0x5);
Leds();
    break;
  case 4:
      count_int=1;
    break;
  }
}
void Leds(void){
  GPIO_PORTN_DATA_R = 0x01;
  SysCtlDelay(500000);
  GPIO_PORTN_DATA_R = 0x00;
  SysCtlDelay(500000);
  GPIO_PORTN_DATA_R = 0x01;
  SysCtlDelay(500000);
  GPIO_PORTN_DATA_R = 0x00;
  SysCtlDelay(500000);
}

//------------------------------------------------------------------
//%%%%%%%%%%%%%%%%%%%%    PROGRAMA PRINCIPAL    %%%%%%%%%%%%%%%%%%%%
//------------------------------------------------------------------




void main(void){


    Config_Puertos();
    Config_CAN();

    //Localidad 1 Rx con Msk
    //Configuración para recepción sencilla localidad #1
    CAN_Memoria_Arb(0xDD,false,0x1);                   //ID, TxRx, Localidad
    CAN_Memoria_CtrlMsk(0xFFF,2,false,true,false,0x1);  //Mask, DLC, TxIE, RxIE, Remote, Localidad+
    
    //Localidad 2 Tx
    //Configuración para la transmisión sencilla #2
    CAN_Memoria_Arb(0xFF,true,0x2);                    //ID, TxRx, Localidad
    CAN_Memoria_CtrlMsk(0xFFF,8,false,false,false,0x2);     //Mask, DLC, TxIE, RxIE, Remote, Localidad
    CAN_Memoria_Dato(C,0x02);


    //Localidad 3 Trama remota Rx
    //Configuración de trama remota con con recepción
    CAN_Memoria_Arb(0xAA,false,0x3);                   //ID, TxRx, Localidad
    CAN_Memoria_CtrlMsk(0xFFF,4,false,true,true,0x3);  //Mask, DLC, TxIE, RxIE, Remote, Localidad
    
    // //Localidad 4 Respuesta a trama remota
     CAN_Memoria_Arb(0xCC,true,0x4);                   //ID, TxRx, Localidad
     CAN_Memoria_CtrlMsk(0xFFF,4,false,false,true,0x4);  //Mask, DLC, TxIE, RxIE, Remote, Localidad
     CAN_Memoria_Dato(0xCC,0x04);

    //Localidad 5 Trama remota Rx
    CAN_Memoria_Arb(0xBB,false,0x5);                   //ID, TxRx, Localidad
    CAN_Memoria_CtrlMsk(0xFFF,4,false,true,true,0x5);  //Mask, DLC, TxIE, RxIE, Remote, Localidad

    // //Localidad 6 Respuesta a trama remota
     CAN_Memoria_Arb(0x11,true,0x6);                   //ID, TxRx, Localidad
     CAN_Memoria_CtrlMsk(0xFFF,4,false,false,true,0x6);  //Mask, DLC, TxIE, RxIE, Remote, Localidad
     CAN_Memoria_Dato(0x11,0x06);
int i;
    while(1){
      for ( i = 0; i < 500000; i++)
      {}
        W++;
        CAN_Memoria_Dato(W,0x02);
        CAN_Tx(0x2);


}
}
