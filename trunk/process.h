
struct pcaket{
	struct ether_header *eth_head;
	struct iphdr *ip_head;
	struct tcphdr *tcp_head;
	struct udphdr *udp_head;
	char data[0];
};

void process_ether(char *ether);

void process_ip(char *ip_pkt);

void process_tcp(char *tcp_pkt);
