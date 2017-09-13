/*
 * client.h
 *
 *  Created on: May 16, 2013
 *      Author: b21665
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "main.h"

#define DESTPORT     1030

void initialize_networking(bool dhcp);
void clientTask(uint32_t initial_data);
void InitializeIO(void);

/* IP address macros */
#define A 192
#define B 168
#define C 1
#define D 202

//#define ENET_IPADDR   IPADDR(192,168,1,6) 
#define ENET_IPMASK  IPADDR(255,255,255,0) 
#define ENET_IPGATEWAY  IPADDR(192,168,1,1) 
#define ENET_IPDNS    	IPADDR(192,168,1,1) 

#endif /* CLIENT_H_ */
