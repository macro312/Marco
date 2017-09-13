/*
 * client.c
 *
 *  Created on: May 16, 2013
 *      Author: b21665
 */
#include <string.h>
#include "main.h"
#include "client.h"

#define LWGPIO_VALUE_LOW 0
/*TASK*-----------------------------------------------------------------
 *
 * Function Name  : clientTask
 * Returned Value : void
 * Comments       :
 *
 *END------------------------------------------------------------------*/
void clientTask(uint32_t initial_data)
{ 
	sockaddr_in    addr;
	uint32_t        sock;
	uint32_t        error;
	uint8_t          cReadBuff[20]="Hello.\n";

	printf("\n\nClient started\n\r");

	//Creating socket  
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == RTCS_SOCKET_ERROR) 
	{
		printf("Failed to create socket. Error 0x%X",sock);
		return;
	} 

	addr.sin_family      = AF_INET;
	addr.sin_port        = DESTPORT;
	addr.sin_addr.s_addr = IPADDR(192,168,1,200); //Server address 

	printf("\nConnecting to server... ");
	error = connect(sock, &addr, sizeof(addr));
	if (error != RTCS_OK) 
	{
		printf("Failed to connect. Error 0x%X",error);
		shutdown(sock, FLAG_ABORT_CONNECTION);
		return;
	}
	else
	{
		printf("Connection established!\n");
	}

	//Sending Hello.  
	printf("Sending: %s", cReadBuff);
	error = send(sock, (void *)cReadBuff, sizeof(cReadBuff), 0);
	if (error <= 0)
	{
		printf("There was an error trying to send to the server\n");
		return;
	}

	//Receiving answer form Hello
	error = recv(sock, (void *)cReadBuff, sizeof(cReadBuff), 0);
	if (error <= 0)
	{
		printf("There was an error trying to send to the server\n");
		return;
	}
	else
	{
		printf("Received: %s\n", cReadBuff);
		if (cReadBuff[0] != 'H')
		{
			shutdown(sock, FLAG_ABORT_CONNECTION);
		}
	}


	InitializeIO();
	printf("Ready for user input... \n\n");
	/*****Infinite loop waiting for user to push a button***/
	while(1){
		if(GPIO_DRV_ReadPinInput(kGpioSW1) == LWGPIO_VALUE_LOW)
		{
			_time_delay(150);
			sprintf((char *)cReadBuff, "Toggle\n");
			printf("Sending: %s", cReadBuff);
			error = send(sock, (void *)cReadBuff, sizeof(cReadBuff), 0);
			if (error <= 0)
			{
				printf("There was an error trying to send to the server\n");
				return;
			}
		}
		if(GPIO_DRV_ReadPinInput(kGpioSW2) == LWGPIO_VALUE_LOW)
		{
			_time_delay(150);
			sprintf((char *)cReadBuff, "GoodBye\n");
			printf("Sending: %s", cReadBuff);
			error = send(sock, (void *)cReadBuff, sizeof(cReadBuff), 0);
			if (error <= 0)
			{
				printf("There was an error trying to send to the server\n");
				return;
			}
			printf("Shutting down connection\n");
			shutdown(sock,FLAG_CLOSE_TX);
			_task_abort(MQX_NULL_TASK_ID);
		}
	}
	return;
}


void InitializeIO(void)
{
	//Init LED and Buttons
	GPIO_DRV_Init(switchPins,ledPins);
	GPIO_DRV_ClearPinOutput(BOARD_GPIO_LED_BLUE);


}
