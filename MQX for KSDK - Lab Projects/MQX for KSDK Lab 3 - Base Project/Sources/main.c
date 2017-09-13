#include <mqx.h>
#include <bsp.h>

#define MAIN_TASK 1

void Main_task(uint32_t);

TASK_TEMPLATE_STRUCT MQX_template_list[] =
{
		/*  Task number, Entry point, Stack, Pri, String, Auto? */
		{MAIN_TASK,   Main_task,   1500,  9,   "main", MQX_AUTO_START_TASK},
		{0,           0,           0,     0,   0,      0,                 }
};


void Main_task(uint32_t initial_data)
{
	printf("\n Hello World \n");

	_task_block();
}


/* EOF */

