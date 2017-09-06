/*
 * UART.c
 *
 *  Created on: Aug 28, 2017
 *      Author: macro
 */
// new types
#include "types.h"
#include "MK70F12.h"
#include "FIFO.h"
#include "UART.h"

static TFIFO TX_FIFO, RX_FIFO;

/*! @brief Sets up the UART interface before first use.
 *
 *  @param baudRate The desired baud rate in bits/sec.
 *  @param moduleClk The module clock rate in Hz
 *  @return bool - TRUE if the UART was successfully initialized.
 */
bool UART_Init(const uint32_t baudRate, const uint32_t moduleClk)
{
SIM_SCGC4 |= SIM_SCGC4_UART2_MASK;	//Clock gating UART 4 and Port E
SIM_SCGC5 |=  (SIM_SCGC5_PORTE_MASK);

PORTE_PCR16 |= PORT_PCR_MUX(0x03); //Enable ALT3 for Mux, UART 2_TX and UART_RX from PortE
PORTE_PCR17 |= PORT_PCR_MUX(0x03);

//Disable Module while configuring
UART2_C2 &= ~UART_C2_RE_MASK;
UART2_C2 &= ~UART_C2_TE_MASK;

//UART2_C1 = UART2_C2 = 0x00;
//UART2_C2 |= UART_C2_RE_MASK | UART_C2_TE_MASK;
//UART2_C4 &= ~UART_C4_BRFA_MASK;		//Clear BaudRate Fine Adjust field
//UART2_C4 |= (0x04 & UART_C4_BRFA_MASK); //Set BRFA to 0x04
//UART2_C1 = 0x00;
//UART2_C2 = 0x00;


UART2_C4 &= ~UART_C4_BRFA_MASK; 	//Baud Rate Fine Adjust to 0
UART2_C4 |= (0x04 & UART_C4_BRFA_MASK);	//And 0x04 to BRFA.


uint16_t BRFD = moduleClk/(baudRate * 16); 	//Baud rate fractional divisor
UART2_BDH = (BRFD & 0x1F00) >> 8;		//13 Bit registry for SBR, 5 for High, 8 for Low. Must write High first then low.
UART2_BDL = (BRFD & 0x00FF);			//BRFD will not change, it is & with all bits in SBR for appropriate baudrate settings
						//Could be hard coded with BDH =0x00, BDL=0x20, BRFA(0x17); from 38400 Baud Rate, 20971520hz
UART2_C2 |= UART_C2_RE_MASK;
UART2_C2 |= UART_C2_TE_MASK;

FIFO_Init(&RX_FIFO);
FIFO_Init(&TX_FIFO);

return true;

//UART2_C4 BRFA fine tunes baud rate
//UART2_BDH;
//UART2_BDL;
//UART2_S1

/* List of registers to configure

UART2_C3
UART2_C4
UART2_S1
UART2_S2
UART2_BDH
UART2_BDL
UART2_MODEM
UART2_C5*/


/*! @brief Get a character from the receive FIFO if it is not empty.
 *
 *  @param dataPtr A pointer to memory to store the retrieved byte.
 *  @return bool - TRUE if the receive FIFO returned a character.
 *  @note Assumes that UART_Init has been called.
 */

}

/*! @brief Get a character from the receive FIFO if it is not empty.
 *
 *  @param dataPtr A pointer to memory to store the retrieved byte.
 *  @return bool - TRUE if the receive FIFO returned a character.
 *  @note Assumes that UART_Init has been called.
 */
bool UART_InChar(uint8_t * const dataPtr){
  return FIFO_Get(&RX_FIFO, dataPtr);

}

/*! @brief Put a byte in the transmit FIFO if it is not full.
 *
 *  @param data The byte to be placed in the transmit FIFO.
 *  @return bool - TRUE if the data was placed in the transmit FIFO.
 *  @note Assumes that UART_Init has been called.
 */
bool UART_OutChar(const uint8_t data){
  return FIFO_Put(&TX_FIFO, data);

}

/*! @brief Poll the UART status register to try and receive and/or transmit one character.
 *
 *  @return void
 *  @note Assumes that UART_Init has been called.
 */
void UART_Poll(void){
uint32_t statusReg = UART2_S1;
uint8_t uartDreg;

  if(statusReg & UART_S1_TDRE_MASK){ //Check TDRE mask, set if ready to send

      FIFO_Get(&TX_FIFO, (uint8_t *)&UART2_D);

  }

  if(statusReg & UART_S1_RDRF_MASK){ //Check RDRF mask, set if ready to receive

      uartDreg = UART2_D;
      FIFO_Put(&RX_FIFO, uartDreg);

  }

}


