#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>

#define PRESS "PRESSED 0x%X (%d)\n"
#define REALEASE "REALEASED 0x%X (%d)\n"
#define REPEAT "REPEAT 0x%X (%d)\n"


int main(){


	FILE *f = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	if(f == NULL)
	{
		printf("Error opening File!!!\n");
		return 1;
	}
	
	return 1;


}
