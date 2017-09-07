/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.c
**     Project     : Lab3
**     Processor   : MK70FN1M0VMJ12
**     Component   : MK70FN1M0MJ15
**     Version     : Component 01.028, Driver 01.04, CPU db: 3.00.000
**     Repository  : Kinetis
**     Datasheet   : K70P256M150SF3RM, Rev. 2, Dec 2011
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-09-07, 17:13, # CodeGen: 1
**     Abstract    :
**
**     Settings    :
**          Component name                                 : Cpu
**          CPU type                                       : MK70FN1M0VMJ12
**          CPU                                            : CPU
**          MemModelDev                                    : MemModel_NoFlexMem
**          Clock settings                                 : 
**            Internal oscillator                          : 
**              Slow internal reference clock [kHz]        : 32.768
**              Initialize slow trim value                 : no
**              Fast internal reference clock [MHz]        : 4
**              Initialize fast trim value                 : no
**            RTC oscillator                               : Disabled
**            System oscillator 0                          : Enabled
**              Clock source                               : External reference clock
**                Clock input pin                          : 
**                  Pin name                               : EXTAL0/PTA18/FTM0_FLT2/FTM_CLKIN0
**                  Pin signal                             : 
**                Clock frequency [MHz]                    : 50
**            System oscillator 1                          : Disabled
**            Clock source settings                        : 1
**              Clock source setting 0                     : 
**                Internal reference clock                 : 
**                  MCGIRCLK clock                         : Enabled
**                  MCGIRCLK in stop                       : Disabled
**                  MCGIRCLK source                        : Slow
**                  MCGIRCLK clock [MHz]                   : 0.032768
**                External reference clock                 : 
**                  OSC0ERCLK clock                        : Enabled
**                  OSC0ERCLK in stop                      : Disabled
**                  OSC0ERCLK clock [MHz]                  : 50
**                  OSC1ERCLK clock                        : Enabled
**                  OSC1ERCLK in stop                      : Disabled
**                  OSC1ERCLK clock [MHz]                  : 0
**                  ERCLK32K clock source                  : System oscillator 0
**                  ERCLK32K. clock [kHz]                  : 50
**                MCG settings                             : 
**                  MCG mode                               : BLPE
**                  MCG output clock                       : External clock
**                  MCG output [MHz]                       : 50
**                  MCG external ref. clock source         : System oscillator 0
**                  MCG external ref. clock [MHz]          : 50
**                  Clock monitor                          : 
**                    System oscillator 0                  : Disabled
**                    RTC oscillator                       : Disabled
**                    System oscillator 1                  : Disabled
**                  FLL settings                           : 
**                    FLL module                           : Disabled
**                    FLL output [MHz]                     : 0
**                    MCGFFCLK clock [kHz]                 : 24.4140625
**                    Reference clock source               : External clock
**                      Reference clock divider            : Auto select
**                    FLL reference clock [kHz]            : 48.828125
**                    Multiplication factor                : Auto select
**                  PLL 0 settings                         : 
**                    PLL module                           : Disabled
**                    PLL module in Stop                   : Disabled
**                    External reference select            : System oscillator 0
**                    PLL output [MHz]                     : 0
**                    Reference clock divider              : Auto select
**                    PLL reference clock [MHz]            : 1
**                    Multiplication factor                : Auto select
**                    Loss of lock interrupt               : Disabled
**                  PLL 1 settings                         : 
**                    PLL module                           : Disabled
**                    PLL module in Stop                   : Disabled
**                    PLL output [MHz]                     : 0
**                    External reference select            : System oscillator 0
**                    Reference clock divider              : Auto select
**                    PLL reference clock [MHz]            : 1
**                    Multiplication factor                : Auto select
**                    Loss of lock interrupt               : Disabled
**          Initialization priority                        : minimal priority
**          Watchdog disable                               : yes
**          Internal peripherals                           : 
**            NMI pin                                      : Disabled
**            Reset control                                : Enabled
**              Reset pin                                  : RESET_b
**              Reset pin signal                           : 
**              Filter in STOP                             : Disabled
**              Filter in RUN/WAIT                         : Disabled
**              Filter width                               : 1
**            Debug interface (JTAG)                       : 
**              JTAG Mode                                  : JTAG
**                TDI                                      : Enabled
**                  TDI Pin                                : TSI0_CH2/PTA1/UART0_RX/FTM0_CH6/JTAG_TDI/EZP_DI
**                  TDI Pin signal                         : 
**                TDO                                      : Enabled
**                  TDO Pin                                : TSI0_CH3/PTA2/UART0_TX/FTM0_CH7/JTAG_TDO/TRACE_SWO/EZP_DO
**                  TDO Pin signal                         : 
**                TCK                                      : Enabled
**                  TCK Pin                                : TSI0_CH1/PTA0/UART0_CTS_b/UART0_COL_b/FTM0_CH5/JTAG_TCLK/SWD_CLK/EZP_CLK
**                  TCK Pin signal                         : 
**                TMS                                      : Enabled
**                  TMS Pin                                : TSI0_CH4/PTA3/UART0_RTS_b/FTM0_CH0/JTAG_TMS/SWD_DIO
**                  TMS Pin signal                         : 
**                nTRST                                    : Disabled
**            Flash memory organization                    : 
**              Flash blocks                               : 4
**                Flash block 0                            : PFlash
**                  Address                                : 0x0
**                  Size                                   : 262144
**                  Write unit size                        : 8
**                  Erase unit size                        : 4096
**                  Protection unit size                   : 32768
**                Flash block 1                            : PFlash
**                  Address                                : 0x40000
**                  Size                                   : 262144
**                  Write unit size                        : 8
**                  Erase unit size                        : 4096
**                  Protection unit size                   : 32768
**                Flash block 2                            : PFlash
**                  Address                                : 0x80000
**                  Size                                   : 262144
**                  Write unit size                        : 8
**                  Erase unit size                        : 4096
**                  Protection unit size                   : 32768
**                Flash block 3                            : PFlash
**                  Address                                : 0xC0000
**                  Size                                   : 262144
**                  Write unit size                        : 8
**                  Erase unit size                        : 4096
**                  Protection unit size                   : 32768
**            Flexible memory controller                   : Disabled
**            Flash configuration field                    : Enabled
**              Security settings                          : 
**                Flash security                           : Disabled
**                Freescale failure analysis access        : Enabled
**                Mass erase                               : Enabled
**                Backdoor key security                    : Disabled
**                Backdoor key 0                           : 255
**                Backdoor key 1                           : 255
**                Backdoor key 2                           : 255
**                Backdoor key 3                           : 255
**                Backdoor key 4                           : 255
**                Backdoor key 5                           : 255
**                Backdoor key 6                           : 255
**                Backdoor key 7                           : 255
**              Protection regions                         : 
**                P-Flash protection settings              : 
**                  Protection region size                 : 32768
**                  P-Flash protection                     : 0xFFFFFFFF
**                  Protection regions                     : 
**                    Protection region 0                  : Unprotected
**                    Protection region 1                  : Unprotected
**                    Protection region 2                  : Unprotected
**                    Protection region 3                  : Unprotected
**                    Protection region 4                  : Unprotected
**                    Protection region 5                  : Unprotected
**                    Protection region 6                  : Unprotected
**                    Protection region 7                  : Unprotected
**                    Protection region 8                  : Unprotected
**                    Protection region 9                  : Unprotected
**                    Protection region 10                 : Unprotected
**                    Protection region 11                 : Unprotected
**                    Protection region 12                 : Unprotected
**                    Protection region 13                 : Unprotected
**                    Protection region 14                 : Unprotected
**                    Protection region 15                 : Unprotected
**                    Protection region 16                 : Unprotected
**                    Protection region 17                 : Unprotected
**                    Protection region 18                 : Unprotected
**                    Protection region 19                 : Unprotected
**                    Protection region 20                 : Unprotected
**                    Protection region 21                 : Unprotected
**                    Protection region 22                 : Unprotected
**                    Protection region 23                 : Unprotected
**                    Protection region 24                 : Unprotected
**                    Protection region 25                 : Unprotected
**                    Protection region 26                 : Unprotected
**                    Protection region 27                 : Unprotected
**                    Protection region 28                 : Unprotected
**                    Protection region 29                 : Unprotected
**                    Protection region 30                 : Unprotected
**                    Protection region 31                 : Unprotected
**                D-Flash protection settings              : 
**                  Protection region size                 : 
**                  D-Flash protection                     : 0xFF
**                  Protection regions                     : 
**                    Protection region 0                  : Unprotected
**                    Protection region 1                  : Unprotected
**                    Protection region 2                  : Unprotected
**                    Protection region 3                  : Unprotected
**                    Protection region 4                  : Unprotected
**                    Protection region 5                  : Unprotected
**                    Protection region 6                  : Unprotected
**                    Protection region 7                  : Unprotected
**                Eeprom protection settings               : 
**                  Protection region size                 : 
**                  Eeprom protection                      : 0xFF
**                  Protection regions                     : 
**                    Protection region 0                  : Unprotected
**                    Protection region 1                  : Unprotected
**                    Protection region 2                  : Unprotected
**                    Protection region 3                  : Unprotected
**                    Protection region 4                  : Unprotected
**                    Protection region 5                  : Unprotected
**                    Protection region 6                  : Unprotected
**                    Protection region 7                  : Unprotected
**              Peripheral settings                        : 
**                EzPort operation at boot                 : Enabled
**                Low power boot                           : Disabled
**            MPU settings                                 : Enabled
**              MPU module                                 : Disabled
**            AXBS settings                                : Disabled
**            AIPS0 settings                               : Disabled
**            AIPS1 settings                               : Disabled
**            MCM settings                                 : Disabled
**            System control block settings                : Disabled
**            Power management controller                  : 
**              LVD reset                                  : Enabled
**              LVD voltage treshold                       : Low
**              LVW voltage treshold                       : Low
**              Bandgap buffer                             : Disabled
**              LVD interrupt                              : 
**                Interrupt                                : INT_LVD_LVW
**                Interrupt request                        : Disabled
**                Interrupt priority                       : 0 (Highest)
**                LVD interrupt                            : Disabled
**                LVW interrupt                            : Disabled
**            System Integration Module                    : 
**              CLKOUT pin control                         : Disabled
**              CMT/UART pad drive strength                : Single-pad drive
**              Clock gating control                       : Disabled
**          CPU interrupts/resets                          : 
**            NMI interrupt                                : Disabled
**            Hard Fault                                   : Disabled
**            Bus Fault                                    : Disabled
**            Usage Fault                                  : Disabled
**            Supervisor Call                              : Disabled
**            Pendable Service                             : Disabled
**            MCG                                          : Disabled
**          DDR module                                     : Disabled
**          External Bus                                   : Disabled
**          Low power mode settings                        : 
**            Allowed power modes                          : 
**              Very low power modes                       : Not allowed
**              Low leakage stop mode                      : Not allowed
**              Very low leakage stop mode                 : Not allowed
**            LLWU settings                                : Disabled
**            Operation mode settings                      : 
**              WAIT operation mode                        : 
**                Return to wait after ISR                 : no
**              SLEEP operation mode                       : 
**                Return to stop after ISR                 : no
**              STOP operation mode                        : Disabled
**          Clock configurations                           : 1
**            Clock configuration 0                        : 
**              __IRC_32kHz                                : 0.032768
**              __IRC_4MHz                                 : 2
**              __SYSTEM_OSC                               : 50
**              __OSC1                                     : 8
**              __RTC_OSC                                  : 0
**              Very low power mode                        : Disabled
**              Clock source setting                       : configuration 0
**                MCG mode                                 : BLPE
**                MCG output [MHz]                         : 50
**                MCGIRCLK clock [MHz]                     : 0.032768
**                OSCERCLK clock [MHz]                     : 50
**                ERCLK32K. clock [kHz]                    : 50
**                MCGFFCLK [kHz]                           : 24.4140625
**              System clocks                              : 
**                Core clock prescaler                     : Auto select
**                Core clock                               : 50
**                Bus clock prescaler                      : Auto select
**                Bus clock                                : 25
**                External clock prescaler                 : Auto select
**                External bus clock                       : 10
**                Flash clock prescaler                    : Auto select
**                Flash clock                              : 12.5
**                PLL/FLL clock selection                  : FLL
**                  Clock frequency [MHz]                  : 0
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.c
** @version 01.04
** @brief
**
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

/* {Default RTOS Adapter} No RTOS includes */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Global variables */
volatile uint8_t SR_reg;               /* Current value of the FAULTMASK register */
volatile uint8_t SR_lock = 0x00U;      /* Lock */

/*
** ===================================================================
**     Method      :  Cpu_SetBASEPRI (component MK70FN1M0MJ15)
**
**     Description :
**         This method sets the BASEPRI core register.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cpu_SetBASEPRI(uint32_t Level);

/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MK70FN1M0MJ15)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  PE_DEBUGHALT();
}


/*** !!! Here you can place your own code using property "User data declarations" on the build options tab. !!! ***/

/*lint -esym(765,__init_hardware) Disable MISRA rule (8.10) checking for symbols (__init_hardware). The function is linked to the EWL library */
/*lint -esym(765,Cpu_Interrupt) Disable MISRA rule (8.10) checking for symbols (Cpu_Interrupt). */
void __init_hardware(void)
{

  /*** !!! Here you can place your own code before PE initialization using property "User code before PE initialization" on the build options tab. !!! ***/

  /*** ### MK70FN1M0VMJ12 "Cpu" init code ... ***/
  /*** PE initialization code after reset ***/
  SCB_VTOR = (uint32_t)(&__vect_table); /* Set the interrupt vector table position */
  /* Disable the WDOG module */
  /* WDOG_UNLOCK: WDOGUNLOCK=0xC520 */
  WDOG_UNLOCK = WDOG_UNLOCK_WDOGUNLOCK(0xC520); /* Key 1 */
  /* WDOG_UNLOCK: WDOGUNLOCK=0xD928 */
  WDOG_UNLOCK = WDOG_UNLOCK_WDOGUNLOCK(0xD928); /* Key 2 */
  /* WDOG_STCTRLH: ??=0,DISTESTWDOG=0,BYTESEL=0,TESTSEL=0,TESTWDOG=0,??=0,??=1,WAITEN=1,STOPEN=1,DBGEN=0,ALLOWUPDATE=1,WINEN=0,IRQRSTEN=0,CLKSRC=1,WDOGEN=0 */
  WDOG_STCTRLH = WDOG_STCTRLH_BYTESEL(0x00) |
                 WDOG_STCTRLH_WAITEN_MASK |
                 WDOG_STCTRLH_STOPEN_MASK |
                 WDOG_STCTRLH_ALLOWUPDATE_MASK |
                 WDOG_STCTRLH_CLKSRC_MASK |
                 0x0100U;

  /* System clock initialization */
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=1,OUTDIV3=3,OUTDIV4=3,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0x00) |
                SIM_CLKDIV1_OUTDIV2(0x01) |
                SIM_CLKDIV1_OUTDIV3(0x03) |
                SIM_CLKDIV1_OUTDIV4(0x03); /* Set the system prescalers to safe value */
  /* SIM_SCGC5: PORTA=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;   /* Enable clock gate for ports to enable pin routing */
  if ((PMC_REGSC & PMC_REGSC_ACKISO_MASK) != 0x0U) {
    /* PMC_REGSC: ACKISO=1 */
    PMC_REGSC |= PMC_REGSC_ACKISO_MASK; /* Release IO pads after wakeup from VLLS mode. */
  }
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=1,OUTDIV3=4,OUTDIV4=3,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0x00) |
                SIM_CLKDIV1_OUTDIV2(0x01) |
                SIM_CLKDIV1_OUTDIV3(0x04) |
                SIM_CLKDIV1_OUTDIV4(0x03); /* Update system prescalers */
  /* SIM_SOPT2: PLLFLLSEL=0 */
  SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_PLLFLLSEL(0x03)); /* Select FLL as a clock source for various peripherals */
  /* SIM_SOPT1: OSC32KSEL=0 */
  SIM_SOPT1 &= (uint32_t)~(uint32_t)(SIM_SOPT1_OSC32KSEL_MASK); /* System oscillator drives 32 kHz clock for various peripherals */
  /* SIM_SCGC1: OSC1=1 */
  SIM_SCGC1 |= SIM_SCGC1_OSC1_MASK;
  /* PORTA_PCR18: ISF=0,MUX=0 */
  PORTA_PCR18 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* Switch to FBE Mode */
  /* MCG_C7: OSCSEL=0 */
  MCG_C7 &= (uint8_t)~(uint8_t)(MCG_C7_OSCSEL_MASK);
  /* MCG_C10: LOCRE2=0,??=0,RANGE1=0,HGO1=0,EREFS1=0,??=0,??=0 */
  MCG_C10 = MCG_C10_RANGE1(0x00);
  /* MCG_C2: LOCRE0=0,??=0,RANGE0=2,HGO0=0,EREFS0=0,LP=0,IRCS=0 */
  MCG_C2 = MCG_C2_RANGE0(0x02);
  /* OSC0_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC0_CR = OSC_CR_ERCLKEN_MASK;
  /* OSC1_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC1_CR = OSC_CR_ERCLKEN_MASK;
  /* MCG_C1: CLKS=2,FRDIV=5,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (MCG_C1_CLKS(0x02) | MCG_C1_FRDIV(0x05) | MCG_C1_IRCLKEN_MASK);
  /* MCG_C4: DMX32=0,DRST_DRS=0 */
  MCG_C4 &= (uint8_t)~(uint8_t)((MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x03)));
  /* MCG_C5: PLLREFSEL0=0,PLLCLKEN0=0,PLLSTEN0=0,??=0,??=0,PRDIV0=0 */
  MCG_C5 = MCG_C5_PRDIV0(0x00);
  /* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
  MCG_C6 = MCG_C6_VDIV0(0x00);
  /* MCG_C11: PLLREFSEL1=0,PLLCLKEN1=0,PLLSTEN1=0,PLLCS=0,??=0,PRDIV1=0 */
  MCG_C11 = MCG_C11_PRDIV1(0x00);
  /* MCG_C12: LOLIE1=0,??=0,CME2=0,VDIV1=0 */
  MCG_C12 = MCG_C12_VDIV1(0x00);
  while((MCG_S & MCG_S_IREFST_MASK) != 0x00U) { /* Check that the source of the FLL reference clock is the external reference clock. */
  }
  while((MCG_S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /* Switch to BLPE Mode */
  /* MCG_C2: LOCRE0=0,??=0,RANGE0=2,HGO0=0,EREFS0=0,LP=1,IRCS=0 */
  MCG_C2 = (MCG_C2_RANGE0(0x02) | MCG_C2_LP_MASK);
  while((MCG_S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code after PE initialization using property "User code after PE initialization" on the build options tab. !!! ***/

}

/*
** ===================================================================
**     Method      :  Cpu_SetBASEPRI (component MK70FN1M0MJ15)
**
**     Description :
**         This method sets the BASEPRI core register.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/*lint -save  -e586 -e950 Disable MISRA rule (2.1,1.1) checking. */
#ifdef _lint
  #define Cpu_SetBASEPRI(Level)  /* empty */
#else
void Cpu_SetBASEPRI(uint32_t Level) {
  __asm ("msr basepri, %[input]"::[input] "r" (Level):);
}
#endif
/*lint -restore Enable MISRA rule (2.1,1.1) checking. */


/*
** ===================================================================
**     Method      :  PE_low_level_init (component MK70FN1M0MJ15)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
      /* Initialization of the SIM module */
  /* SIM_SOPT2: CMTUARTPAD=0 */
  SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_CMTUARTPAD_MASK);
  /* PORTA_PCR4: MUX=0 */
  PORTA_PCR4 &= (uint32_t)~(uint32_t)(PORT_PCR_MUX(0x07)); /* Disable NMI function on the NMI pin */
        /* Initialization of the RCM module */
  /* RCM_RPFW: RSTFLTSEL=0 */
  RCM_RPFW &= (uint8_t)~(uint8_t)(RCM_RPFW_RSTFLTSEL(0x1F));
  /* RCM_RPFC: RSTFLTSS=0,RSTFLTSRW=0 */
  RCM_RPFC &= (uint8_t)~(uint8_t)(
               RCM_RPFC_RSTFLTSS_MASK |
               RCM_RPFC_RSTFLTSRW(0x03)
              );
        /* Initialization of the FTFL_FlashConfig module */
  /* SIM_SCGC7: MPU=1 */
  SIM_SCGC7 |= SIM_SCGC7_MPU_MASK;
        /* Initialization of the MPU module */
  /* MPU_CESR: SPERR=0,VLD=0 */
  MPU_CESR &= (uint32_t)~(uint32_t)((MPU_CESR_SPERR(0xFF) | MPU_CESR_VLD_MASK));
      /* Initialization of the PMC module */
  /* PMC_REGSC: ACKISO=0,BGBE=0 */
  PMC_REGSC &= (uint8_t)~(uint8_t)(
                PMC_REGSC_ACKISO_MASK |
                PMC_REGSC_BGBE_MASK
               );
  /* PMC_LVDSC1: LVDACK=1,LVDIE=0,LVDRE=1,LVDV=0 */
  PMC_LVDSC1 = (uint8_t)((PMC_LVDSC1 & (uint8_t)~(uint8_t)(
                PMC_LVDSC1_LVDIE_MASK |
                PMC_LVDSC1_LVDV(0x03)
               )) | (uint8_t)(
                PMC_LVDSC1_LVDACK_MASK |
                PMC_LVDSC1_LVDRE_MASK
               ));
  /* PMC_LVDSC2: LVWACK=1,LVWIE=0,LVWV=0 */
  PMC_LVDSC2 = (uint8_t)((PMC_LVDSC2 & (uint8_t)~(uint8_t)(
                PMC_LVDSC2_LVWIE_MASK |
                PMC_LVDSC2_LVWV(0x03)
               )) | (uint8_t)(
                PMC_LVDSC2_LVWACK_MASK
               ));
  /* SMC_PMPROT: ??=0,??=0,AVLP=0,??=0,ALLS=0,??=0,AVLLS=0,??=0 */
  SMC_PMPROT = 0x00U;                  /* Setup Power mode protection register */
  /* Common initialization of the CPU registers */
  /* NVICIP20: PRI20=0 */
  NVICIP20 = NVIC_IP_PRI20(0x00);
  /* Enable interrupts of the given priority level */
  Cpu_SetBASEPRI(0U);
}
  /* Flash configuration field */
  __attribute__ ((section (".cfmconfig"))) const uint8_t _cfm[0x10] = {
   /* NV_BACKKEY3: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY2: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY1: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY0: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY7: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY6: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY5: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY4: KEY=0xFF */
    0xFFU,
   /* NV_FPROT3: PROT=0xFF */
    0xFFU,
   /* NV_FPROT2: PROT=0xFF */
    0xFFU,
   /* NV_FPROT1: PROT=0xFF */
    0xFFU,
   /* NV_FPROT0: PROT=0xFF */
    0xFFU,
   /* NV_FSEC: KEYEN=1,MEEN=3,FSLACC=3,SEC=2 */
    0x7EU,
   /* NV_FOPT: ??=1,??=1,??=1,??=1,??=1,??=1,EZPORT_DIS=1,LPBOOT=1 */
    0xFFU,
   /* NV_FEPROT: EPROT=0xFF */
    0xFFU,
   /* NV_FDPROT: DPROT=0xFF */
    0xFFU
  };

/* END Cpu. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

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
