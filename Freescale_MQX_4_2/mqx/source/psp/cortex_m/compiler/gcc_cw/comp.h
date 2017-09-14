/*HEADER**********************************************************************
*
* Copyright 2010 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale MQX RTOS License
* distributed with this Material.
* See the MQX_RTOS_LICENSE file distributed for more details.
*
* Brief License Summary:
* This software is provided in source form for you to use free of charge,
* but it is not open source software. You are allowed to use this software
* but you cannot redistribute it or derivative works of it in source form.
* The software may be used only in connection with a product containing
* a Freescale microprocessor, microcontroller, or digital signal processor.
* See license agreement file for full license terms including other
* restrictions.
*****************************************************************************
*
* Comments:
*
*   This file defines the GCC ARM build tools specific macros for MQX
*
*
*END************************************************************************/
#ifndef __comp_h__
#define __comp_h__   1

#ifdef __cplusplus
extern "C" {
#endif


#define _ASM_NOP()      __asm volatile ("nop")
#define _ASM_STOP(x)
#define _ASM_WFI()      __asm volatile ("wfi")

#define ISB()           __asm volatile ("isb")
#define DSB()           __asm volatile ("dsb")
#define DMB()           __asm volatile ("dmb")

#if PSP_MQX_CPU_IS_ARM_CORTEX_M4
#define __set_BASEPRI(basePri) __asm volatile ("msr BASEPRI, %0" : : "r" (basePri))
#define _PSP_SET_ENABLE_SR(x)   __set_BASEPRI(x)
#define _PSP_SET_DISABLE_SR(x)  _PSP_SET_ENABLE_SR(x)
#elif PSP_MQX_CPU_IS_ARM_CORTEX_M0P
#define _PSP_SET_ENABLE_SR(x)   __asm volatile ("cpsie i")
#define _PSP_SET_DISABLE_SR(x)  __asm volatile ("cpsid i")
#else
#error Invalid platform selected
#endif

#define _PSP_SYNC()


/* Kinetis User mode definitions */
#if MQX_ENABLE_USER_MODE
#error "Usermode is not supported"

#else /* MQX_ENABLE_USER_MODE */

#define KERNEL_ACCESS
#define USER_RW_ACCESS
#define USER_RO_ACCESS
#define USER_NO_ACCESS

#endif /* MQX_ENABLE_USER_MODE */

/*
 *      DATATYPE MODIFIERS
 */

#define _WEAK_SYMBOL(x)     x __attribute__((weak))
#define _WEAK_FUNCTION(x)   __attribute__((weak)) x

/* compiler dependent structure packing option */
#define PACKED_STRUCT_BEGIN
#define PACKED_STRUCT_END   __attribute__((__packed__))

/* compiler dependent union packing option */
#define PACKED_UNION_BEGIN
#define PACKED_UNION_END    __attribute__((__packed__))

/**
 */
typedef long ssize_t;
typedef long off_t;

#ifdef __cplusplus
}
#endif

#endif   /* __comp_h__ */
