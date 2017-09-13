/*
 * server.c
 *
 *  Created on: May 16, 2013
 *      Author: b21665
 */

#include "main.h"
#include <string.h>
#include "server.h"





/*TASK*-----------------------------------------------------------------
 *
 * Function Name  : serverTask
 * Returned Value : void
 * Comments       :
 *
 *END------------------------------------------------------------------*/
void serverTask(uint32_t initial_data)
{
	sockaddr_in                laddr;
	uint32_t                    sock, listensock;
	uint32_t                    error;
	uint16_t                    remote_addr_len;
	sockaddr_in                remote_addr = {0};
	uint8_t                      cReadBuff[20]="Hola.\n";
	uint8_t                      cRecvBuff[20]={0};
	//uint32_t                    value;
	//uint32_t					  i;

	_time_delay(2000);
	printf("\n\nServer started\n\r");  
	laddr.sin_family      = AF_INET;  //if socket tcp or udp
	laddr.sin_port        = CONNECT_PORT;  //free port
	laddr.sin_addr.s_addr = INADDR_ANY;    //

	/* Listen on TCP port */
	listensock = socket(PF_INET, SOCK_STREAM, 0);  //creating the socket

	if (listensock == RTCS_SOCKET_ERROR) 
	{
		error = RTCSERR_OUT_OF_SOCKETS;
	} 

	error = bind(listensock, &laddr, sizeof(laddr)); //bind socket to IP address
	if (!error) 
	{
		error = listen(listensock, 0);
	} 

	// Waiting for connection 
	remote_addr_len = sizeof(remote_addr);
	printf("\nReady for connection... ");
	sock = accept(listensock, &remote_addr, &remote_addr_len);
	printf("Connection accepted!\n");

	if (sock==RTCS_SOCKET_ERROR) 
	{
		shutdown((uint32_t)sock, FLAG_CLOSE_TX);
	}


	//Receiving message.  
	error = recv(sock, (void *)cRecvBuff, sizeof(cRecvBuff), 0);
	if (error <= 0)
	{
		printf("There was an error trying to send to the server\n");
		return;
	}
	else
	{
		printf("Received: %s", cRecvBuff);
	}

	//Replying to Hello
	printf("Sending: %s", cReadBuff);      
	error = send(sock, (void *)cReadBuff, sizeof(cReadBuff), 0);
	if (error <= 0)
	{
		printf("There was an error trying to send to the server\n");
		return;
	}  

	InitializeIO();
	printf("\nReady for user input...\n\n");
	/*****Infinite loop waiting for user to push a button on client***/
	while (1){
		error = recv(sock, (void *)cRecvBuff, sizeof(cRecvBuff), 0);
		if (error <= 0)
		{
			printf("There was an error trying to send to the server\n");
			return;
		}
		if(cRecvBuff[0]=='T'){
			printf("LED was toggled\r\n");
			GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_BLUE);
		}
		if(cRecvBuff[0]=='G'){				
			printf("Received: %s\n", cRecvBuff);
			printf("Shutting down connection\n");
			shutdown(sock,FLAG_CLOSE_TX);
			_time_delay(2000);	
			_task_abort(MQX_NULL_TASK_ID);
		}
	}
}


void InitializeIO(void)
{

	GPIO_DRV_Init(switchPins, ledPins);
	GPIO_DRV_ClearPinOutput(BOARD_GPIO_LED_BLUE);
}
