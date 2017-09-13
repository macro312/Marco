#include <mqx.h>
#include <bsp.h>



#define MAIN_TASK 1
#define TASK_A 2
#define TASK_B 3
#define TASK_C 4
#define TASK_D 5

void Main_task(uint32_t);
void Task_A (uint32_t);
void Task_B (uint32_t);
void Task_C (uint32_t);
void Task_D (uint32_t);

TASK_TEMPLATE_STRUCT MQX_template_list[] =
{
		/*  Task number, Entry point, Stack, Pri, String, Auto? */
		{MAIN_TASK,   Main_task,   1500,  9,   "main", MQX_AUTO_START_TASK},
		{TASK_A,   Task_A,   1500,  10,   "Task A", 0},
		{TASK_B,   Task_B,   1500,  10,   "Task B", 0},
		{TASK_C,   Task_C,   1500,  10,   "Task C", 0},
		{TASK_D,   Task_D,   1500,  10,   "Task D", 0},
		{0,           0,           0,     0,   0,      0,                 }
};


_task_id ta, tb, tc, td;


void Main_task(uint32_t initial_data)
{
	printf("\n Using Tasks \n");

	ta = _task_create(0,TASK_A,0);
	if (ta == MQX_NULL_TASK_ID)
	{
		printf("Task_A could not be created. Error: 0x%X \n", ta);
	}
	else
	{
		printf("Task_A was created\n");
	}

	_task_block();
}


void Task_A(uint32_t initial_data)
{
	_task_id tb;
	while(1){
		printf("\nThis is Task A \n");
		_time_delay(500);

		tb = _task_create(0,TASK_B,0);
		if (tb == MQX_NULL_TASK_ID)
		{
			printf("Task_B could not be created. Error: 0x%X \n", tb);
		}
		else
		{
			printf("Task_B was created\n");
		}
		_task_block();
	}
}


void Task_B(uint32_t initial_data)
{
	_task_id tc;
	while(1){
		printf("\nThis is Task B \n");
		_time_delay(500);

		tc = _task_create(0,TASK_C,0);
		if (tc == MQX_NULL_TASK_ID)
		{
			printf("Task_C could not be created. Error: 0x%X \n", tc);
		}
		else
		{
			printf("Task_C was created\n");
		}
		_task_destroy(MQX_NULL_TASK_ID);
	}
}

void Task_C(uint32_t initial_data)
{
	_task_id td;
	while(1){
		printf("\nThis is Task C \n");
		_time_delay(500);

		td = _task_create(0,TASK_D,0);
		if (td == MQX_NULL_TASK_ID)
		{
			printf("Task_D could not be created. Error: 0x%X \n", td);
		}
		else
		{
			printf("Task_D was created\n");
		}
		_task_destroy(MQX_NULL_TASK_ID);
	}
}

void Task_D(uint32_t initial_data)
{
	while(1){
		printf("\nThis is Task D \n");
		_time_delay(500);
		_task_ready(_task_get_td(ta));
		_task_destroy(MQX_NULL_TASK_ID);
	}

}
/* EOF */

