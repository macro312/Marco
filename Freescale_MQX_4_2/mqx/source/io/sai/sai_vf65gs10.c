/*HEADER**********************************************************************
*
* Copyright 2008 Freescale Semiconductor, Inc.
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
*   This file contains board-specific SAI initialization functions.
*
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include "sai.h"
#include "sai_ksai.h"
#include "sai_ksai_prv.h"

/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_sai_base_address
* Returned Value   : address if successful, NULL otherwise
* Comments         :
*    This function returns the base register address of the corresponding SAI device.
*
*END*********************************************************************/

void *_bsp_get_sai_base_address
(
    uint8_t dev_num
)
{
    void   *addr;

    switch (dev_num)
    {
        case 0:
            addr = (void *)I2S0_BASE_PTR;
            break;
        case 1:
            addr = (void *)I2S1_BASE_PTR;
            break;
        case 2:
            addr = (void *)I2S2_BASE_PTR;
            break;
        case 3:
            addr = (void *)I2S3_BASE_PTR;
            break;
        default:
            addr = NULL;
            break;
    }
    
    return addr;
}

/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_sai_tx_vector
* Returned Value   : vector number if successful, 0 otherwise
* Comments         :
*    This function returns desired interrupt tx vector number for specified SAI device.
*
*END*********************************************************************/

uint32_t _bsp_get_sai_tx_vector
(
    uint8_t dev_num
)
{
    uint32_t vector = 0;
    
#if PSP_MQX_CPU_IS_VYBRID_A5
    switch (dev_num)
    {
        case 0:
            vector = 132;   // SAI0
            break;
        case 1:
            vector = 133;   // SAI1
            break;
        case 2:
            vector = 134;   // SAI2
            break;
        case 3:
            vector = 135;   // SAI3
            break;
    }
#elif PSP_MQX_CPU_IS_VYBRID_M4
    switch (dev_num)
    {
        case 0:
            vector = 100;   // SAI0
            break;
        case 1:
            vector = 101;   // SAI1
            break;
        case 2:
            vector = 102;   // SAI2
            break;
        case 3:
            vector = 103;   // SAI3
            break;
    }
#else
    #error "Unsupported core"
#endif
    
    return vector;
}

/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_sai_rx_vector
* Returned Value   : vector number if successful, 0 otherwise
* Comments         :
*    This function returns desired interrupt rx vector number for specified SAI device.
*
*END*********************************************************************/

uint32_t _bsp_get_sai_rx_vector
(
    uint8_t dev_num
)
{
    uint32_t vector = 0;
    
#if PSP_MQX_CPU_IS_VYBRID_A5
    switch (dev_num)
    {
        case 0:
            vector = 132;   // SAI0
            break;
        case 1:
            vector = 133;   // SAI1
            break;
        case 2:
            vector = 134;   // SAI2
            break;
        case 3:
            vector = 135;   // SAI3
            break;
    }
#elif PSP_MQX_CPU_IS_VYBRID_M4
    switch (dev_num)
    {
        case 0:
            vector = 100;   // SAI0
            break;
        case 1:
            vector = 101;   // SAI1
            break;
        case 2:
            vector = 102;   // SAI2
            break;
        case 3:
            vector = 103;   // SAI3
            break;
    }
#else
    #error "Unsupported core"
#endif
    
    return vector;
}

/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_sai_tx_dma_source
* Returned Value   : dma request source number if successful, 0 otherwise
* Comments         :
*    This function returns dma request source number for specified SAI device.
*
*END*********************************************************************/
uint32_t _bsp_get_sai_tx_dma_source(uint8_t dev_num)
{
    uint32_t source = 0;
    switch (dev_num)
    {
        case 0:
            source = 17;
            break;
        case 1:
            source = 19;
            break;
        case 2:
            source = 21;
            break;
        case 3:
            source = 9;
            break;        
        default:
            source = 0;
            break;
    }
    return source;
}

/*FUNCTION****************************************************************
*
* Function Name    : _bsp_get_sai_rx_dma_source
* Returned Value   : dma request source number if successful, 0 otherwise
* Comments         :
*    This function returns dma request source number for specified SAI device.
*
*END*********************************************************************/
uint32_t _bsp_get_sai_rx_dma_source(uint8_t dev_num)
{
    uint32_t source = 0;
    switch (dev_num)
    {
        case 0:
            source = 16;
            break;
        case 1:
            source = 18;
            break;
        case 2:
            source = 20;
            break;
        case 3:
            source = 8;
            break;        
        default:
            source = 0;
            break;
    }
    return source;
}

uint8_t _bsp_get_sai_dma_channel_mask(uint8_t dev_num)
{
    uint32_t mask = 0;
    switch (dev_num)
    {
        case 0:
            mask = 9;
            break;
        case 1:
            mask = 9;
            break;
        case 2:
            mask = 9;
            break;
        case 3:
            mask = 6;
            break;
        default:
            mask = 0;
            break;
    }
    return mask;
}

/* EOF */
