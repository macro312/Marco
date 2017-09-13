/*
 * server.h
 *
 *  Created on: May 16, 2013
 *      Author: b21665
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "main.h"

#define CONNECT_PORT    1030

void initialize_networking(bool dhcp);
void InitializeIO(void);
void serverTask(uint32_t initial_data);

/* IP address macros */
#define A 192
#define B 168
#define C 1
#define D 200


//#define ENET_IPADDR   IPADDR(192,168,1,5) 
#define ENET_IPMASK  IPADDR(255,255,255,0) 
#define ENET_IPGATEWAY  IPADDR(192,168,1,1) 
#define ENET_IPDNS    	IPADDR(192,168,1,1) 

#endif /* SERVER_H_ */
