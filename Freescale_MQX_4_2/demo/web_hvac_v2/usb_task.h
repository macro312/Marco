/**HEADER********************************************************************
* 
* Copyright (c) 2008, 2013 - 2014 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: usb_task.h$
* $Version : $
* $Date    : $
*
* Comments:
*
*   
*
*END************************************************************************/
#ifndef __usb_task_h__
#define __usb_task_h__

#include "usb_host_config.h"
#include "usb.h"
//#include "usb_host_stack_interface.h"

//#include "usb_host_hub_sm.h"
//#include "usb_host_msd_bo.h"
//#include "usb_host_msd_ufi.h"

 /* USB device states */
#define  USB_DEVICE_IDLE                   (0)
#define  USB_DEVICE_ATTACHED               (1)
#define  USB_DEVICE_CONFIGURED             (2)
#define  USB_DEVICE_SET_INTERFACE_STARTED  (3)
#define  USB_DEVICE_INTERFACE_OPENED       (4)
#define  USB_DEVICE_SETTING_PROTOCOL       (5)
#define  USB_DEVICE_INUSE                  (6)
#define  USB_DEVICE_DETACHED               (7)
#define  USB_DEVICE_OTHER                  (8)
#define  USB_DEVICE_INTERFACE_CLOSED       (9)

#define  USB_STATE_CHANGED                 (0x01)
#define  HIGH_SPEED                        (1)
#if HIGH_SPEED
#define CONTROLLER_ID                      USB_CONTROLLER_EHCI_1
#else
#define CONTROLLER_ID                      USB_CONTROLLER_KHCI_0
#endif

#define DEMOCFG_USE_POOLS          0   /* enable external memory pools for USB */
#define USBCFG_MAX_INSTANCE        (1)

#if BSP_M52259EVB
    #define DEMOCFG_MFS_POOL_ADDR  (uint_32)(BSP_EXTERNAL_MRAM_RAM_BASE)
    #define DEMOCFG_MFS_POOL_SIZE  0x00010000
#elif DEMOCFG_USE_POOLS
    #warning External pools will not be used on this board.
#endif

typedef struct _device_struct
{
   uint32_t                         dev_state;  /* Attach/detach state */
   usb_device_instance_handle       dev_handle;
   usb_interface_descriptor_handle  intf_handle;
   usb_class_handle                 CLASS_HANDLE; /* Class-specific info */
   uint8_t                          mount;
   void *                           usb_mfs_handle;
} device_struct_t;


//#include <shell.h>

//extern void Shell_Task(uint32_t);
//extern void Main_Task(uint32_t);


#endif


/* EOF */
