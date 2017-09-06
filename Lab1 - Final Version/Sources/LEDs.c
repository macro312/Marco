/*
 * LEDs.c
 *
 *  Created on: Aug 28, 2017
 *      Author: macro
 */

#include "MK70F12.h"
#include "LEDs.h"

bool LEDs_Init(void){

  SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK; //Clock gating port A

  //Changing Pin on port as output, use a mask to change the SIM_SCG5 port mask Chapter 10
  PORTA_PCR10 = PORT_PCR_DSE_MASK | PORT_PCR_MUX(1);
  PORTA_PCR11 = PORT_PCR_DSE_MASK | PORT_PCR_MUX(1);
  PORTA_PCR28 = PORT_PCR_DSE_MASK | PORT_PCR_MUX(1);
  PORTA_PCR29 = PORT_PCR_DSE_MASK | PORT_PCR_MUX(1);

  //PORTA_PCR10 = MUX(1) | DSE -bit; Chapter 11
  //PORTA_PCR11 = MUX(1) | DSE -bit;
  //PORTA_PCR28 = MUX(1) | DSE -bit;
  //PORTA_PCR29 = MUX(1) | DSE -bit;
  //Setting PCR 10, 11, 28, 29 into multiplex (MUX) on bits 10, 9 and 8.
  //Setting DSE-Bit will be for Drive Strength Enabled.

  GPIOA_PDDR = LED_BLUE |LED_GREEN | LED_ORANGE | LED_YELLOW;

  LEDs_Off(LED_BLUE |LED_GREEN | LED_ORANGE | LED_YELLOW);

  //Setting GPIOA_PDDR, 32bit register that contains Blue | Orange | Yellow | Green
  //Chapter 59
  //GPIOA_PSOR  Port Set bit
  //GPIOA_PCOR  Port Clear bit
  //Example: Absolute 400F_F014 = 10000000000111111110 000 00010100

}

/*! @brief Turns an LED on.
 *
 *  @param color The color of the LED to turn on.
 *  @note Assumes that LEDs_Init has been called.
 */
void LEDs_On(const TLED color){

GPIOA_PCOR = color;

}

/*! @brief Turns off an LED.
 *
 *  @param color THe color of the LED to turn off.
 *  @note Assumes that LEDs_Init has been called.
 */
void LEDs_Off(const TLED color){

  GPIOA_PSOR = color;

}

/*! @brief Toggles an LED.
 *
 *  @param color THe color of the LED to toggle.
 *  @note Assumes that LEDs_Init has been called.
 */
void LEDs_Toggle(const TLED color){

GPIOA_PTOR = color;

}



