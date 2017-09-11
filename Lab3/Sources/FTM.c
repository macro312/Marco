/*! @file
 *
 *  @brief Routines for setting up the FlexTimer module (FTM) on the TWR-K70F120M.
 *
 *  This contains the functions for operating the FlexTimer module (FTM).
 *
 *  @author PMcL
 *  @date 2015-09-04
 */

// new types
#include "FTM.h"
#include "types.h"
#include "MK70F12.h"


/*! @brief Sets up the FTM before first use.
 *
 *  Enables the FTM as a free running 16-bit counter.
 *  @return bool - TRUE if the FTM was successfully initialized.
 */
bool FTM_Init(){

}
/*! @brief Sets up a timer channel.
 *
 *  @param aFTMChannel is a structure containing the parameters to be used in setting up the timer channel.
 *    channelNb is the channel number of the FTM to use.
 *    delayCount is the delay count (in module clock periods) for an output compare event.
 *    timerFunction is used to set the timer up as either an input capture or an output compare.
 *    ioType is a union that depends on the setting of the channel as input capture or output compare:
 *      outputAction is the action to take on a successful output compare.
 *      inputDetection is the type of input capture detection.
 *    userFunction is a pointer to a user callback function.
 *    userArguments is a pointer to the user arguments to use with the user callback function.
 *  @return bool - TRUE if the timer was set up successfully.
 *  @note Assumes the FTM has been initialized.
 */
bool FTM_Set(const TFTMChannel* const aFTMChannel){

}


/*! @brief Starts a timer if set up for output compare.
 *
 *  @param aFTMChannel is a structure containing the parameters to be used in setting up the timer channel.
 *  @return bool - TRUE if the timer was started successfully.
 *  @note Assumes the FTM has been initialized.
 */
bool FTM_StartTimer(const TFTMChannel* const aFTMChannel){

}

/*! @brief Interrupt service routine for the FTM.
 *
 *  If a timer channel was set up as output compare, then the user callback function will be called.
 *  @note Assumes the FTM has been initialized.
 */
void __attribute__ ((interrupt)) FTM0_ISR(void){

}

//#include <stdint.h>
//#include "derivative.h"
//#include "nvic.h"
//#include "flexTimer.h"
//
///* For an overall description of the FlexTimer, see 43.4 on labeled
// * page 1251 (PDF page 1258) of the K70 Sub-Family Reference Manual,
// * Rev. 4, Oct 2015 (see 44.4 on page 1275 of the K70 Sub-Family
// * Reference Manual, Rev. 2, Dec 2011) */
//
///* For the FlexTimer block diagram, see Figure 43-1 on labeled page
// * 1201 (PDF page 1208) of the K70 Sub-Family Reference Manual,
// * Rev. 4, Oct 2015 (see Figure 44-1 on page 1219 of the K70
// * Sub-Family Reference Manual, Rev. 2, Dec 2011) */
//
///* It appears to be possible to use the 32.768KHz crystal that is
// * normally used for the RTC oscillator as the fixed frequency clock
// * for the FlexTimers by choosing it as the MCG FLL external reference
// * clock using the OSCSEL bit using the MCG Control 7 Register (MCG_C7).
// * Of course, this could not be done if the FLL clock were being used
// * for the MCGOUTCLK.  Once this clock were divided by 32768, it would
// * yield an accurate clock for a one second precision, but would not
// * help with a 1 msec precise timer. */
//
///* On the other hand, Table 5-2 on labeled page 224 (PDF page 231) of
// * the K70 Sub-Family Reference Manual, Rev. 4, Oct 2015 (Table 5-2 on
// * page 220 of the K70 Sub-Family Reference Manual, Rev. 2, Dec 2011)
// * indicates that the clocks used by the FlexTimers are either the Bus
// * clock, MCGFFCLK, or FTM_CLKINx.  Choosing the SYSTEM_CLOCK as the
// * clock for the FlexTimer (rather than the FIXED_FREQUENCY_CLOCK)
// * therefore uses the Bus clock.  After calling mcgInit, the Bus
// * (peripheral) clock is set to 60 MHz.  If the FlexTimer prescaler
// * divide factor is set to 32, that results in a FlexTimer clock of 60
// * MHz/32 or 1.875 MHz.  If the count used in the FlexTimer modulo
// * register is set to 1875, that will result in a FlexTimer interrupt
// * once every 1 ms. */
//
///**
// * initialize FlexTimer 0 hardware
// *
// * count is the number of 1/128 second time periods
// */
//void flexTimer0Init(uint16_t count) {
//  /* Enable the clock for FTM0 (FlexTimer 0) using the SIM_SCGC6 register
//   * (System Clock Gating Control Register 6) (See 12.2.14 on labeled
//   * page 349 (PDF page 356) of the K70 Sub-Family Reference Manual,
//   * Rev. 4, Oct 2015) (See 12.2.14 on page 344 of the K70 Sub-Family
//   * Reference Manual, Rev. 2, Dec 2011) */
//  SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;
//
//  /* Turn off FlexTimer 0 and clear any pending Timer Overflow Flag
//   * (TOF) using the FTM0_SC register (Status and Control register for
//   * FlexTimer 0) (See 43.3.3 on labeled page 1209 (PDF page 1216) of
//   * the K70 Sub-Family Reference Manual, Rev. 4, Oct 2015) (See
//   * 44.3.3 on page 1230 of the K70 Sub-Family Reference Manual,
//   * Rev. 2, Dec 2011) */
//  /* The TOF bit is set by hardware when the FTM counter passes the
//   * value in the MOD register.  The TOF bit is cleared by reading the SC
//   * register while TOF is set and then writing a 0 to TOF bit.  Writing a
//   * 1 to TOF has no effect.  If another FTM overflow occurs between the
//   * read and write operations, the write operation has no effect;
//   * therefore, TOF remains set indicating an overflow has occurred.  In
//   * this case a TOF interrupt request is not lost due to the clearing
//   * sequence for a previous TOF. */
//  /* The read of FTM0_SC cannot be optimzed out because it is declared
//   * as volatile and, as the C Standard says, "A volatile declaration may
//   * be used to describe an object corresponding to a memory-mapped
//   * input/output port or an object accessed by an asynchronously
//   * interrupting function.  Actions on objects so declared shall not be
//   * 'optimized out' by an implementation or reordered except as
//   * permitted by the rules for evaluating expressions." */
//  FTM0_SC;
//  FTM0_SC = 0;
//
//  /* Disable write protection for FlexTimer 0 (even though this is the
//   * default) using the FTM0_FMS and FTM0_MODE registers (Features
//   * Mode Selection register for FlexTimer 0) (See 43.3.10 on labeled
//   * page 1271 (PDF page 1224) of the K70 Sub-Family Reference Manual,
//   * Rev. 4, Oct 2015) (See 44.3.10 on page 1240 of the K70 Sub-Family
//   * Reference Manual, Rev. 2, Dec 2011) */
//  FTM0_FMS; /* Read the WPEN (Write Protection Enable bit) */
//  FTM0_MODE = FTM_MODE_WPDIS_MASK;
//
//  /* Select FTM CLKIN0 as the external pin used to drive the external clock
//   * to the FTM0 module (this is already the default configuration on reset) */
//  SIM_SOPT4 &= ~SIM_SOPT4_FTM0CLKSEL_MASK;
//
//  /* If clock is 32kHz/2 (= 16kHz), and we divide that by 128, we end up
//   * with a clock of 128Hz */
//
//  /* Enable FTM overflow interrupts, Up counting mode,
//   * Select no clock (disable), Prescaler to divide by 128 */
//  FTM0_SC = FTM_SC_TOIE_MASK |
//    FTM_SC_CLKS(FTM_SC_CLKS_NO_CLOCK) |
//    FTM_SC_PS(FTM_SC_PS_DIVIDE_BY_128);
//
//  /* Set the initial counter value (16-bit value) in the counter initial
//   * value register */
//  FTM0_CNTIN = 0;
//
//  /* Set the counter value (16-bit value) in the counter register */
//  FTM0_CNT = 0;
//
//  /* Load timer count (16-bit value) into the modulo register */
//  FTM0_MOD = count;
//
//  /* Enable interrupts from FTM0 and set its interrupt priority */
//  NVICEnableIRQ(FTM0_IRQ_NUMBER, FTM0_INTERRUPT_PRIORITY);
//}
//
///**
// * start FlexTimer 0
// */
//void flexTimer0Start(void) {
//  /* Enable FTM overflow interrupts, Up counting mode,
//   * Select the Fixed Frequency Clock, Prescaler to divide by 128 */
//  FTM0_SC = FTM_SC_TOIE_MASK |
//    FTM_SC_CLKS(FTM_SC_CLKS_FIXED_FREQUENCY_CLOCK) |
//    FTM_SC_PS(FTM_SC_PS_DIVIDE_BY_128);
//}
//
///**
// * stop FlexTimer 0
// */
//void flexTimer0Stop(void) {
//  /* Enable FTM overflow interrupts, Up counting mode,
//   * Select no clock (disable), Prescaler to divide by 128 */
//  FTM0_SC = FTM_SC_TOIE_MASK |
//    FTM_SC_CLKS(FTM_SC_CLKS_NO_CLOCK) |
//    FTM_SC_PS(FTM_SC_PS_DIVIDE_BY_128);
//}
//
///**
// * FlexTimer 0 Interrupt Service Routine (ISR)
// */
//void flexTimer0Isr(void) {
//  /* The TOF bit is cleared by reading the SC register while TOF is set
//   * and then writing a 0 to TOF bit */
//
//  /* Clear the pending Timer Overflow Flag by reading the FTM0_SC register
//   * (Status and Control register for FlexTimer 0) (See 43.3.3 on
//   * labeled page 1209 (PDF page 1216) of the K70 Sub-Family Reference
//   * Manual, Rev. 4, Oct 2015) (See 44.3.3 on page 1230 of the K70
//   * Sub-Family Reference Manual, Rev. 2, Dec 2011) */
//  /* The TOF bit is set by hardware when the FTM counter passes the
//   * value in the MOD register.  The TOF bit is cleared by reading the SC
//   * register while TOF is set and then writing a 0 to TOF bit.  Writing a
//   * 1 to TOF has no effect.  If another FTM overflow occurs between the
//   * read and write operations, the write operation has no effect;
//   * therefore, TOF remains set indicating an overflow has occurred.  In
//   * this case a TOF interrupt request is not lost due to the clearing
//   * sequence for a previous TOF. */
//  /* The read of FTM0_SC cannot be optimzed out because it is declared
//   * as volatile and, as the C Standard says, "A volatile declaration may
//   * be used to describe an object corresponding to a memory-mapped
//   * input/output port or an object accessed by an asynchronously
//   * interrupting function.  Actions on objects so declared shall not be
//   * 'optimized out' by an implementation or reordered except as
//   * permitted by the rules for evaluating expressions." */
//  FTM0_SC;
//  /* Clear timer overflow flag (TOF), Enable FTM overflow interrupts,
//   * Up counting mode, Select the Fixed Frequency Clock, Prescaler to
//   * divide by 128 */
//  FTM0_SC = FTM_SC_TOIE_MASK |
//    FTM_SC_CLKS(FTM_SC_CLKS_FIXED_FREQUENCY_CLOCK) |
//    FTM_SC_PS(FTM_SC_PS_DIVIDE_BY_128);
//
//  /* Perform the user's action */
//  flexTimer0Action();
//}
