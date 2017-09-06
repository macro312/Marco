/*
 * Buttons.c
 *
 *  Created on: Aug 28, 2017
 *      Author: macro
 */

//First find how the TSI works
//Implement Polling, cycling through the 4 TSI for find a bit
//when toggle bit for each TSI is on, turn LED on.
#include "MK70F12.h"
#include "Buttons.h"

//#define electrodeNumber[] = {5,7,8,9}

void TSI_init(void)
{

  SIM_SCGC5 |=  (SIM_SCGC5_PORTB_MASK)|(SIM_SCGC5_TSI_MASK); //Turn on clock-gating to PORTB and  to TSI module

  PORTA_PCR4 = PORT_PCR_MUX(0);      //Enable ALT0 for portA4 TSI0_CH5
  PORTB_PCR2 = PORT_PCR_MUX(0);      //Enable ALT0 for portB2 TSI0_CH7
  PORTB_PCR3 = PORT_PCR_MUX(0);      //Enable ALT0 for portB3 TSI0_CH8 YELLOW
  PORTB_PCR16 = PORT_PCR_MUX(0);      //Enable ALT0 for portB16 TSI0_CH9

  TSI0_GENCS |= TSI_GENCS_EOSF_MASK;	//Change TSI0_GENCS to EOSF_MASK, this clears the bit to 0, End of Scan Flag

  //Select General Control and Status Register, STPE and LPSCNITV has been ignored for 	MCU operational mode
  TSI0_GENCS |= (TSI_GENCS_NSCN(10))|
		(TSI_GENCS_PS(4))|
		TSI_GENCS_STPE_SHIFT|
		TSI_GENCS_LPSCNITV(7);
  //Set number of scans (NSCN), Prescalar (PS). Turn off Touch Input Interupt

  TSI0_SCANC |= ((TSI_SCANC_EXTCHRG(8))|
                (TSI_SCANC_REFCHRG(15))|
                (TSI_SCANC_SMOD(10))|
                (TSI_SCANC_AMPSC(1))|
		(TSI_SCANC_AMCLKS(0)));
  //Set EXTCHRG, REFCHRG, SMOD scan period, AMPSC Active Mode Pre-scale, ActiveMode CLKS

  TSI0_PEN |= TSI_PEN_PEN9_MASK | TSI_PEN_PEN8_MASK  | TSI_PEN_PEN7_MASK | TSI_PEN_PEN5_MASK; //PEN8 for Yellow

  //Pin 10 11 28 29 or 9 7 8 5 Enable register, do not change the settings when TSIEN is 1.
  //ELECTRODE_ENABLE_REG = ELECTRODE0_EN_MASK|ELECTRODE1_EN_MASK|ELECTRODE2_EN_MASK|ELECTRODE3_EN_MASK;

  TSI0_GENCS |= TSI_GENCS_TSIEN_MASK; //Enable the TSI module after the configuration is set
}

void TSI_SelfCalibration(void)
{
  TSI0_GENCS |= TSI_GENCS_SWTS_MASK; 		//Software trigger start mask

  while(!TSI0_GENCS&TSI_GENCS_EOSF_MASK){};	//Stuck in loop until End of Scan Flag is cleared

  //Simple calibration from demo talked about adding to the target voltage?

}

char TSI_Touch(const electrode_t button){

  TSI0_GENCS |= TSI_GENCS_SWTS_MASK;

  while(!TSI0_GENCS&TSI_GENCS_EOSF_MASK){}; 	//Scan while flags are not up

  TSI0_GENCS |= TSI_GENCS_EOSF_MASK; 		//End of scan flag cleared

//  uint16_t value = TSI0_CNTR1;
//  uint16_t value1 = TSI0_CNTR3;
//  uint16_t value2 = TSI0_CNTR5;
//  uint16_t value3 = TSI0_CNTR7;

  uint16_t value4 = (*(button.reg)) >> button.shift;
//  uint16_t value4 = TSI0_CNTR9; //Yellow TSI_CNTR9_CTN();

//
//  uint16_t value5 = TSI0_CNTR11;
//  uint16_t value6 = TSI0_CNTR13;
//  uint16_t value7 = TSI0_CNTR15;


  //  TSI0_
  //TSI_CH[electrodeNumber[pinnumber]] ??

  if(value4 > 0x2000){//{ //electrodeNumber[] = {5,7,8,9};
      for(int i = 0; i < 1000; i++){
      };
      return 1;
  }
  else
    return 0;
//  return *(TSI0_CNTR[electrode]);

//  }

    //16 bit value from TSIx_CNTRn

    //getPin Value for targeted electrodes
    //Register value for GPIO_Pins are used to read the value
    //return *(TSI0_CNTR)

    //returned valued should be the oscilation counter between the two clocks, REf and Ext
    //return *(counterRegister);

}


