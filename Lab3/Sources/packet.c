/*
 * packet.c
 *
 *  Created on: Sep 2, 2017
 *      Author: macro
 */

#include "types.h"
#include "UART.h"
#include "packet.h"
// Packet structure


#define PKTcmdSpecial 0x04
#define PKTcmdVer 0x09
#define PKTcmdTwrNo 0x0B


#define packetAckMask 0x80
#define PKTversionNo 0x01
#define PKTtwrNoGetMask 0x01
#define PKTtwrNoSetMask 0x02

//Packet Position
static uint8_t packetPosition;
static uint16union_t twrNumber = {0x241A}; //4292 Student Number

static TPacket Packet;

/*! @brief Initializes the packets by calling the initialization routines of the supporting software modules.
 *
 *  @param baudRate The desired baud rate in bits/sec.
 *  @param moduleClk The module clock rate in Hz
 *  @return bool - TRUE if the packet module was successfully initialized.
 */
bool Packet_Init(const uint32_t baudRate, const uint32_t moduleClk){
  packetPosition = 0;
  return UART_Init(baudRate, moduleClk); //Return UART INIT with True
  //8 data bits, no parity, and 1 stop bit
}

/*! @brief Aligns Packets to correct order for sorting
 *
 *  @return
 */
void PacketAlign(void){

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

      switch(packetPosition){
	case 0:
	  if(UART_InChar(&Packet_Command))
	    packetPosition++;
	  break;
	case 1:
	  if(UART_InChar(&Packet_Parameter1))
	    packetPosition++;
	  break;
	case 2:
	  if(UART_InChar(&Packet_Parameter2))
	    packetPosition++;
	  break;
	case 3:
	  if(UART_InChar(&Packet_Parameter3))
	    packetPosition++;
	  break;
	case 4:
	  if(UART_InChar(&Packet_Checksum))
	    packetPosition++;
	  break;
	case 5:
	  if(Checksum()){
	    packetPosition = 0;
	    return(1);
	  }else{
	      PacketAlign(); //_
	      packetPosition = 4;
	  }break;

      }return(0);

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


void TowerVersion(const uint8_t command){

  Packet_Put(command, 0x76, PKTversionNo, 0x00);

}

void TowerStartup(const uint8_t command){

  Packet_Put(command, 0x00, 0x00, 0x00);
  TowerVersion(PKTcmdVer);
  Packet_Put(PKTcmdTwrNo, 0x01, twrNumber.s.Hi, twrNumber.s.Lo); //Splitting uint16_t into two uint8_t, MSB, LSB

}

void CheckAcknowledgement(const uint8_t command, const uint8_t command2){
  if(packetAckMask == command - command2){
     Packet_Put(Packet_Command, Packet_Parameter1, Packet_Parameter2, Packet_Parameter3);
  }
}

void Packet_Handle(void){

uint8_t Packet_NoAcknowledge = Packet_Command & ~packetAckMask; //ACK bit

  switch(Packet_NoAcknowledge){ // Splitting Serial Protocols in read/write
    case PKTcmdSpecial: 	//Tower Startup Parameter 1: 0 | Parameter 2: 0 | Parameter 3: 0
      TowerStartup(Packet_NoAcknowledge);
      break;

    case PKTcmdVer: 		//Special – Tower version Parameter 1: ‘v’ = version | Parameter 2: Major Version Number | Parameter 3: Minor Version Number (out of 100
      TowerVersion(Packet_NoAcknowledge);
      break;

    case PKTcmdTwrNo: 		//Parameter 1: 1 = get Tower number, 2 = set Tower number | Parameter 2: LSB for a “set”, 0 for a “get” | Parameter 3: MSB for a “set”, 0 for a “get”
      if(Packet_Parameter1 == 2){
	  twrNumber.s.Hi = Packet_Parameter2;
	  twrNumber.s.Lo = Packet_Parameter3;
	  Packet_Put(Packet_NoAcknowledge, Packet_Parameter1, Packet_Parameter2, Packet_Parameter3);
      }else{
	  Packet_Put(0x0B, Packet_Parameter1, twrNumber.s.Hi, twrNumber.s.Lo);
      }break;
  }
  CheckAcknowledgement(Packet_Command, Packet_NoAcknowledge);
}


