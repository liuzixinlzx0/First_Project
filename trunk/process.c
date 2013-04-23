#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>  
#include <netinet/ip.h>  
#include <netinet/udp.h>  
#include <netinet/tcp.h> 

#include "process.h"

extern struct pcaket *pkt;

char *tmp_pkt;

void process_ether(char *ether)
{
	int i;


	pkt->eth_head = (struct ether_header *)ether;
	printf("Packet destination MAC is:");
	for(i=0; i<6; i++){
		printf("%02X ", pkt->eth_head->ether_dhost[i]);
	}
	printf("\n");
		
	printf("Packet source MAC is:");
	for(i=0; i<6; i++){
		printf("%02X ", pkt->eth_head->ether_shost[i]);
	}
	printf("\n");

	printf("Packet next layer is %04X\n", pkt->eth_head->ether_type);

	tmp_pkt = ether + sizeof(struct ether_header);

	switch(pkt->eth_head->ether_type){
		case 0x0008:
			process_ip(tmp_pkt);
			break;
		default:
			break;
	}
}

void process_ip(char *ip_pkt)
{
	struct in_addr s_in;
	struct in_addr d_in;
	pkt->ip_head = (struct iphdr *)ip_pkt;

	s_in.s_addr = pkt->ip_head->saddr;
	d_in.s_addr = pkt->ip_head->daddr;

	printf("Packet source IP is: %s\n", inet_ntoa(s_in));
	printf("Packet destination IP is: %s\n", inet_ntoa(d_in));
	printf("Packet ip next layer is: %04x\n", pkt->ip_head->protocol);

}
