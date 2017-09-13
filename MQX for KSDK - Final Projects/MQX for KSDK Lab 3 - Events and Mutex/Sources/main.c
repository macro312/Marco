#include <stdio.h>
#include <mqx.h>
#include <bsp.h>
#include <mutex.h>

/* Task IDs */
#define MAIN_TASK	 1
#define TASK_A 		 2
#define TASK_B		 3
#define TASK_C 		 4

extern void Main_task(uint32_t);
extern void Task_A(uint32_t);
extern void Task_B(uint32_t);
extern void Task_C(uint32_t);

_task_id ta, tb, tc, td;

//Priority of task B and C must be lower than Main_Task and higher than Task_A
const TASK_TEMPLATE_STRUCT  MQX_template_list[] =
{
   /* Task Index,   Function,   Stack,  Priority, Name,     Attributes,          Param, Time Slice */
    {MAIN_TASK,   Main_task,   1500,   9,  		 "main",   MQX_AUTO_START_TASK,	0,	    0},
    {TASK_A,		 Task_A, 	  1500, 11, "Task A", 0,	0,	    0},
    {TASK_B,		 Task_B, 	  1500, 10, "Task B", 0,	0,	    0},//Priority must be lower than Main_Task and higher than Task_A
    {TASK_C,		 Task_C, 	  1500, 10, "Task C", 0,	0,	    0},
    { 0 }
};


uint32_t result;
_task_id t1,t2,t3;
LWEVENT_STRUCT lwevent;
MUTEX_STRUCT my_mutex;


void Main_task(uint32_t initial_data) {
	printf("\n Start Main Task: Events and Mutex\n");

	/*Init LED and buttons*/
	GPIO_DRV_Init(switchPins, ledPins);

	t1 = _task_create(0, TASK_A, 0); //in this moment, Task A was added to the queue
	if (t1 == MQX_NULL_TASK_ID ) {
		printf("\nCould not create Task A. \n");
	} else {
		printf("\nTask A was created. \n");
	}

	t2 = _task_create(0, TASK_B, 0); //in this moment, Task B was added to the queue
	if (t2 == MQX_NULL_TASK_ID ) {
		printf("\nCould not create Task B. \n");
	} else {
		printf("\nTask B was created. \n");
	}

	t3 = _task_create(0, TASK_C, 0); //in this moment, Task C was added to the queue
	if (t3 == MQX_NULL_TASK_ID ) {
		printf("\nCould not create Task C. \n");
	} else {
		printf("\nTask C was created. \n");
	}

	if (_lwevent_create(&lwevent, 0) != MQX_OK) { //Creation of the event
		printf("\nMake event failed");
		_task_block();
	} else {
		printf("\nEvent was created successfully");
	}

	_mutex_init(&my_mutex, NULL );
	_task_block(); //block this Task and continue with the Task list
	_mqx_exit(0);
}

void Task_A(uint32_t initial_data) {
	uint32_t count1 = 0;
	uint32_t count2 = 0;
	while (1) {
		_mutex_lock(&my_mutex);
		if (GPIO_DRV_ReadPinInput(kGpioSW1) == 0) { //0 = PRESS BUTTON
			result = _lwevent_set(&lwevent, 0x01); //Activation of the event
			if (result != MQX_OK) {
				printf("\nSetting event failed. Error: 0x%X", result);
			} else {
				count1++;
				printf("\nButton 1 was pressed %d times.", count1);
			}
		}
		if (GPIO_DRV_ReadPinInput(kGpioSW2) == 0) { //LOW VALUE = PRESS BUTTON
			result = _lwevent_set(&lwevent, 0x02); //Activation of the event
			if (result != MQX_OK) {
				printf("\nSetting event failed. Error: 0x%X", result);
			} else {
				count2++;
				printf("\nButton 2 was pressed %d times.", count2);
			}
		}
		_mutex_unlock(&my_mutex);
	}
}

void Task_B(uint32_t initial_data) {
	while (1) {
		result = _lwevent_wait_ticks(&lwevent, 0x01, FALSE, 0); //wait for event
		if (result != MQX_OK) {
			printf("\nWaiting event failed. Error: 0x%X", result);
		}
		_mutex_lock(&my_mutex);
		GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_BLUE);
		_time_delay(1000);
		_mutex_unlock(&my_mutex);
		_lwevent_clear(&lwevent, 0x01); // Clear the event flag
	}
}

void Task_C(uint32_t initial_data) {
	while (1) {
		result = _lwevent_wait_ticks(&lwevent, 0x02, FALSE, 0);
		if (result != MQX_OK) {
			printf("\nWaiting event failed. Error: 0x%X", result);
		}
		_mutex_lock(&my_mutex);
		GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_RED);
		_time_delay(1000);
		_mutex_unlock(&my_mutex);
		_lwevent_clear(&lwevent, 0x02);
	}
}

/* EOF */
