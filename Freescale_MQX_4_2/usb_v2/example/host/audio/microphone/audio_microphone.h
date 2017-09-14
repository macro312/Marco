
/**HEADER********************************************************************
*
* Copyright (c) 2011, 2013 - 2014 Freescale Semiconductor;
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
* $FileName: audio_microphone.h$
* $Version :
* $Date    :
*
* Comments:
*
*   This file contains audio types and definitions.
*
*END************************************************************************/
#ifndef __audio_microphone_h__
#define __audio_microphone_h__

#define  HIGH_SPEED                         (0)

#if HIGH_SPEED
#define CONTROLLER_ID                       USB_CONTROLLER_EHCI_0
#else
#define CONTROLLER_ID                       USB_CONTROLLER_KHCI_0
#endif

/***************************************
**
** Application-specific definitions
**
****************************************/

#define MAX_SUPPORT_FREQUENCY        48

#define AUDIO_MICROPHONE_FREQUENCY   1000

#define MAX_FRAME_SIZE              1024
#define HOST_CONTROLLER_NUMBER      USBCFG_DEFAULT_HOST_CONTROLLER

#define NUMBER_OF_IT_TYPE 7
#define NUMBER_OF_OT_TYPE 8

#define USB_EVENT_CTRL              0x01
#define USB_EVENT_RECEIVED_DATA     0x02
#define USB_EVENT_SEND_DATA         0x04

#define MAX_ISO_PACKET_SIZE         512

#define USB_AUDIO_DEVICE_DIRECTION_IN                   0x00
#define USB_AUDIO_DEVICE_DIRECTION_OUT                  0x01
#define USB_AUDIO_DEVICE_DIRECTION_UNDEFINE             0xFF

#define USB_TERMINAL_TYPE           0x01
#define INPUT_TERMINAL_TYPE         0x02
#define OUTPUT_TERMINAL_TYPE        0x03

#define  USB_DEVICE_IDLE                   (0)
#define  USB_DEVICE_ATTACHED               (1)
#define  USB_DEVICE_CONFIGURED             (2)
#define  USB_DEVICE_SET_INTERFACE_STARTED  (3)
#define  USB_DEVICE_INTERFACED             (4)
#define  USB_DEVICE_SETTING_PROTOCOL       (5)
#define  USB_DEVICE_INUSE                  (6)
#define  USB_DEVICE_DETACHED               (7)
#define  USB_DEVICE_OTHER                  (8)

#define  TRANSFER_TYPE_NUM                  4
#define  SYNC_TYPE_NUM                      4
#define  DATA_TYPE_NUM                      4


#define  TRANSFER_TYPE_SHIFT                0
#define  SYNC_TYPE_SHIFT                    2
#define  DATA_TYPE_SHIFT                    4

#define BYTE0_SHIFT                         0
#define BYTE1_SHIFT                         8
#define BYTE2_SHIFT                         16

#define HOST_VOLUME_STEP      1
#define HOST_MIN_VOLUME       0
#define HOST_MAX_VOLUME      10
/*
** Following structs contain all states and pointers
** used by the application to control/operate devices.
*/


typedef struct audio_device_struct {
   uint32_t                          dev_state;  /* attach/detach state */
   usb_device_instance_handle        dev_handle;
   usb_interface_descriptor_handle   intf_handle;
   usb_class_handle                  class_handle;
} audio_control_device_struct_t;

typedef struct data_device_struct {
   uint32_t                          dev_state;  /* attach/detach state */
   usb_device_instance_handle        dev_handle;
   usb_interface_descriptor_handle   intf_handle;
   usb_class_handle                  class_handle; 
} audio_stream_device_struct_t;

typedef struct feature_control_struct {
    uint32_t                          FU;
} feature_control_struct_t;
/* Alphabetical list of Function Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

void usb_host_audio_control_event(usb_device_instance_handle,
   usb_interface_descriptor_handle, uint32_t);
void usb_host_audio_stream_event(usb_device_instance_handle,
   usb_interface_descriptor_handle, uint32_t);
void usb_host_audio_tr_callback(usb_pipe_handle ,void *,
    unsigned char *,uint32_t ,uint32_t );
void usb_host_audio_mute_ctrl_callback(usb_pipe_handle,void *,
    unsigned char *,uint32_t,uint32_t);
void usb_host_audio_ctrl_callback(usb_pipe_handle,void *,
    unsigned char *,uint32_t,uint32_t);
void usb_host_audio_interrupt_callback(usb_pipe_handle,void *,
    unsigned char *,uint32_t,uint32_t);
    void usb_host_audio_request_ctrl_callback(usb_pipe_handle,void *,unsigned char *,uint32_t,uint32_t);
    void config_channel(usb_audio_ctrl_desc_fu_t*,uint8_t);
#ifdef __cplusplus
}
#endif
#endif

/* EOF */
