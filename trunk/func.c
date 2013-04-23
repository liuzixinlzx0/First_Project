#include <stdio.h>
#include <sys/types.h>
#include "func.h"

void print_hex(char *str, int len)
{
	u_char *tmp_str;
	tmp_str = (u_char *)str;
	int i;
	printf("Pcaket hex is: \n");
	for(i = 0; i < len; i++){
		if((i+1)%4 == 0){
			if(((i+1)%8 == 0)){
				printf("%02x\n", tmp_str[i]);
			}else{
				printf("%02x    ", tmp_str[i]);
			}
		}else{
			printf("%02x ", tmp_str[i]);
		}
	}               
	printf("\n");
}
