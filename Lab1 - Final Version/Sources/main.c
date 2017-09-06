/* ###################################################################
**     Filename    : main.c
**     Project     : Lab1
**     Processor   : MK70FN1M0VMJ12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-07-20, 13:27, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 1.0
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


// CPU module - contains low level hardware initialization routines
#include "Cpu.h"
#include "Events.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Buttons.h"
#include "MK70F12.h"
#include "LEDs.h"
#include "FIFO.h"
#include "UART.h"
#include "packet.h"
#include "Types.h"

#define BAUD_RATE 38400

//Global Variables
uint8_t Packet_NoAcknowledge;
TFIFO towerFIFO;

static uint16union_t twrNumber = {0x241A}; //4292 Student Number


void TowerVersion(void){

  Packet_Put(Packet_NoAcknowledge, 0x76, 0x01, 0x00);

}

void TowerStartup(void){

  Packet_Put(0x04, 0x00, 0x00, 0x00);
  TowerVersion();
  Packet_Put(0x08, 0x01, twrNumber.s.Hi, twrNumber.s.Lo); //Splitting uint16_t into two uint8_t, MSB, LSB

}

void CheckAcknowledgement(void){
  if(Packet_Command & PACKET_ACK_MASK == PACKET_ACK_MASK){
      Packet_Put(Packet_Command, Packet_Parameter1, Packet_Parameter2, Packet_Parameter3);
  }
}

void Packet_Handle(void){
uint8_t Packet_NoAcknowledge = Packet_Command & ~PACKET_ACK_MASK; //ACK bit

  switch(Packet_NoAcknowledge){ // Splitting Serial Protocols in read/write
    case 0x04: //Tower Startup Parameter 1: 0 | Parameter 2: 0 | Parameter 3: 0
      TowerStartup();
      break;

    case 0x09: //Special – Tower version Parameter 1: ‘v’ = version | Parameter 2: Major Version Number | Parameter 3: Minor Version Number (out of 100
      TowerVersion();
      break;

    case 0x0B: //Parameter 1: 1 = get Tower number, 2 = set Tower number | Parameter 2: LSB for a “set”, 0 for a “get” | Parameter 3: MSB for a “set”, 0 for a “get”
      if(Packet_Parameter1 == 2){
	  Packet_Put(0x08, Packet_Parameter1, Packet_Parameter2, Packet_Parameter3);
//	  twrNumber.s.Hi = Packet_Parameter2;
//	  twrNumber.s.Lo = Packet_Parameter3;
      }else{
	  Packet_Put(0x08, Packet_Parameter1, twrNumber.s.Hi, twrNumber.s.Lo);
      }break;

  }
  CheckAcknowledgement();
}



/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  Packet_Init(BAUD_RATE, CPU_BUS_CLK_HZ);
//  LEDs_Init();
  TowerStartup();
  for(;;){

//Packet_Put(command, param1, param2, param3);
//      if(Packet_Get()){
//	  Packet_Send();
//      }
      //if(Packet_Put); current config only sent TWR ver, number and std number
      UART_Poll();
//      Packet_Handle();
      if(Packet_Get())
	{
	  //callpacket process
	  Packet_Handle();
	}

  }


  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
