/****************************************************************************
* 
*   This file contains MQX only stationery code.
*
****************************************************************************/
#include "main.h"


#if !BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif


//#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
//#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
//#endif

#include "client.h"
#include <ipcfg.h>

TASK_TEMPLATE_STRUCT MQX_template_list[] = 
{ 
/*  Task number, Entry point, Stack, Pri, String, Auto? */
   {MAIN_TASK,   Main_task,   1500,  9,   "main", MQX_AUTO_START_TASK},
   {CLIENT_TASK, clientTask,  4500,  10,  "Client",   0,      },
   {0,           0,           0,     0,   0,      0,                 }
};


/*TASK*-----------------------------------------------------
* 
* Task Name    : Main_task
* Comments     :
*    This task prints " Hello World "
*
*END*-----------------------------------------------------*/

void Main_task(uint32_t initial_data)
{
	_task_id    result;
		
	initialize_networking(0);

	printf("\nNetworking initialized\n");
	
	result = _task_create(0, CLIENT_TASK, 0);
	if (result == MQX_NULL_TASK_ID) 
	{
		printf("\nCould not create client task.");
	}

	return;
}

/* EOF */
