/*
 * Buttons.h
 *
 *  Created on: Aug 28, 2017
 *      Author: macro
 */
#ifndef SOURCES_BUTTONS_H_
#define SOURCES_BUTTONS_H_

#include "Types.h"

typedef struct
{
  volatile uint32_t *reg;
  uint8_t shift;
}electrode_t;

//typedef enum
//{
//  electrodeTSI0 = (1 << 5),
//  electrodeTSI1 = (1 << 7),
//  electrodeTSI2 = (1 << 8),
//  electrodeTSI3 = (1 << 9)
//} electrodeTSI; 		//Pin number


void TSI_init(void);

void TSI_SelfCalibration(void);

char TSI_Touch(const electrode_t button);

#endif /* SOURCES_BUTTONS_H_ */

