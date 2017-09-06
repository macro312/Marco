/*
 * packet.c
 *
 *  Created on: Sep 2, 2017
 *      Author: macro
 */

// new types
#include "types.h"
#include "UART.h"
#include "packet.h"
// Packet structure


uint8_t Packet_Command,		/*!< The packet's command */
	Packet_Parameter1, 	/*!< The packet's 1st parameter */
	Packet_Parameter2, 	/*!< The packet's 2nd parameter */
	Packet_Parameter3,	/*!< The packet's 3rd parameter */
	Packet_Checksum;	/*!< The packet's checksum */


// Acknowledgement bit mask
const uint8_t PACKET_ACK_MASK = 0x80;

//Packet Position
static uint8_t Packet_Position; //_

/*! @brief Initializes the packets by calling the initialization routines of the supporting software modules.
 *
 *  @param baudRate The desired baud rate in bits/sec.
 *  @param moduleClk The module clock rate in Hz
 *  @return bool - TRUE if the packet module was successfully initialized.
 */
bool Packet_Init(const uint32_t baudRate, const uint32_t moduleClk){
  Packet_Position = 0;
  return UART_Init(baudRate, moduleClk); //Return UART INIT with True
  //8 data bits, no parity, and 1 stop bit
}

/*! @brief Aligns Packets to correct order for sorting
 *
 *  @return
 */
void Packet_Align(void){

  uint8_t Packet_Shift = Packet_Checksum;
	  Packet_Command = Packet_Parameter1;
	  Packet_Parameter1 = Packet_Parameter2;
	  Packet_Parameter2 = Packet_Parameter3;
	  Packet_Parameter3 =  Packet_Checksum;
}

static bool Checksum(void){
  volatile uint8_t ChecksumTemp = (Packet_Command^Packet_Parameter1^Packet_Parameter2^Packet_Parameter3);
  if (ChecksumTemp == Packet_Checksum){
      return(1);
  }
  return(0);
}

/*! @brief Attempts to get a packet from the received data.
 *
 *  @return bool - TRUE if a valid packet was received.
 */
bool Packet_Get(void){

  for(;;){
  switch(Packet_Position){
    case 0:
      UART_InChar(&Packet_Command);
      Packet_Position++;
      break;
    case 1:
      UART_InChar(&Packet_Parameter1);
      Packet_Position++;
      break;
    case 2:
      UART_InChar(&Packet_Parameter2);
      Packet_Position++;
      break;
    case 3:
      UART_InChar(&Packet_Parameter3);
      Packet_Position++;
      break;
    case 4:
      UART_InChar(&Packet_Checksum);
      Packet_Position++;
      break;
    case 5:
      if(Checksum()){
	  Packet_Position = 0;
	  return(1);
      }else{
	  Packet_Align(); //_
	  Packet_Position = 4;
	  return(0);
      }
      break;
  }

}
}
/*! @brief Builds a packet and places it in the transmit FIFO buffer.
 *
 *  @return bool - TRUE if a valid packet was sent.
 */
bool Packet_Put(const uint8_t command, const uint8_t param1, const uint8_t param2, const uint8_t param3){
  return(UART_OutChar(command)&&
	 UART_OutChar(param1) &&
	 UART_OutChar(param2) &&
	 UART_OutChar(param3) &&
	 UART_OutChar(command^param1^param2^param3));

}


