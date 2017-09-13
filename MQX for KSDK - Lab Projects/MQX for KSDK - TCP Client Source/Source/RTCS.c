/*
 * RTCS.c
 *
 *  Created on: May 16, 2013
 *      Author: b21665
 */

#include "main.h"
#include "client.h"
#include  <ipcfg.h>
//#include "tfs.h"

void initialize_networking(bool dhcp) 
{
	uint32_t                error;
	uint32_t                ip_addr;
	uint32_t                 phy_addr;
	IPCFG_IP_ADDRESS_DATA ip_data;
	_enet_address  address; //= { 0x00, 0xcf, 0x52, 0x53, 0x54, 0xcc }; 


	/* runtime RTCS configuration */
	_RTCSPCB_init = 4; 
	_RTCSPCB_grow = 2; 
	_RTCSPCB_max = 20; 
	_RTCS_msgpool_init = 4; 
	_RTCS_msgpool_grow = 2; 
	_RTCS_msgpool_max = 20; 
	_RTCS_socket_part_init = 4; 
	_RTCS_socket_part_grow = 2; 
	_RTCS_socket_part_max = 20;

	_RTCSTASK_stacksize = 4500;

	ip_addr = IPADDR(A,B,C,D);
	phy_addr = BSP_DEFAULT_ENET_DEVICE;

	error = RTCS_create();
	if (error == RTCS_OK) 
	{
		ENET_get_mac_address(phy_addr, ip_addr, address);

		error = ipcfg_init_device (phy_addr, address);

		ip_data.ip = ip_addr;
		ip_data.mask = 0xFFFFFF00;
		ip_data.gateway = 0;

		// check link status
		printf("\nWaiting for ethernet cable plug in ... ");
		while(!ipcfg_get_link_active(phy_addr)) {};
		printf("Cable connected\n");

		/* If DHCP Enabled, get IP address from DHCP server */
		if (dhcp) 
		{
			printf("\nDHCP bind ... ");
			error = ipcfg_bind_dhcp_wait(phy_addr, 1, &ip_data);
			if (error != IPCFG_ERROR_OK) 
			{
				printf("Error %08x!\n", error);
			}
			else 
			{
				printf("Successful!\n");
			}
		} 
		else 
		{
			/* Else bind with static IP */
			printf ("\nStatic IP bind ... ");
			error = ipcfg_bind_staticip(phy_addr, &ip_data);

			if (error != IPCFG_ERROR_OK) 
			{
				printf("Error %08x!\n",error);
			}
			else 
			{
				printf("Successful!\n");
			}
		}

		if (error == IPCFG_ERROR_OK) 
		{
			ipcfg_get_ip(phy_addr, &ip_data);
			printf("\nIP Address      : %d.%d.%d.%d",IPBYTES(ip_data.ip));
			printf("\nIP Address HEX  : %X",ip_data.ip);
			printf("\nSubnet Address  : %d.%d.%d.%d",IPBYTES(ip_data.mask));
			printf("\nGateway Address : %d.%d.%d.%d",IPBYTES(ip_data.gateway));
			//printf("\nDNS Address     : %d.%d.%d.%d\n",IPBYTES(ipcfg_get_dns_ip(BSP_DEFAULT_ENET_DEVICE,0)));
		}
	}
	else 
	{
		printf("\nRTCS_Create failed !\n");
		_task_block();
	}
}


/* EOF */
