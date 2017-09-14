#ifndef __ipc_ex_h__
#define __ipc_ex_h__
/*HEADER**********************************************************************
*
* Copyright 2008 Freescale Semiconductor, Inc.
* Copyright 1989-2008 ARC International
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
*   This file contains the source for the common definitions for the
*   IPC example
*
*
*END************************************************************************/

#define EXAMPLE_QUEUE_BASE 8
#define TEST_ID            1
#define IPC_TTN            9
#define MAIN_TTN           10
#define QUEUE_TO_TEST2     EXAMPLE_QUEUE_BASE
#define MAIN_QUEUE         EXAMPLE_QUEUE_BASE+1
#define TEST2_ID           2
#define RESPONDER_TTN      11
#define QUEUE_TO_TEST      EXAMPLE_QUEUE_BASE+2
#define RESPONDER_QUEUE    EXAMPLE_QUEUE_BASE+3

typedef struct the_message
{
   MESSAGE_HEADER_STRUCT  HEADER;
   uint32_t                DATA;
} THE_MESSAGE, * THE_MESSAGE_PTR;

#endif
/* EOF */
