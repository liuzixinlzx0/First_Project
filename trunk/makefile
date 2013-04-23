set_c = main.c process.c
set_c += func.c

all: $(set_c)
	gcc -Wall -g -o cap_pkt $? -lpcap

clean:
	rm *.o cap_pkt

