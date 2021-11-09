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

	struct timeval l = {0, 0};

	while (1){
		struct input_event event;
		fread(&event, sizeof(struct input_event), 1, f);
		
		if (event.type != EV_KEY)
			continue;
		
		printf("\033[1D");

		if (event.value == 0){
			printf(REALEASE, event.code, event.code);
		}else if (event.value == 1){
			printf(PRESS, event.code, event.code);
		}else{
			printf(REPEAT, event.code, event.code);
		}
		l = event.time;
	}
}
