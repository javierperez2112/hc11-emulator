#include "hc11.h"
#include <stdio.h>
#include <stdlib.h>

/* THIS FILE IS ONLY FOR TESTING PURPOSES!!! */

int main(int argc, char **argv)
{
	hc11_t HC11;
	int m = init_mem(&HC11);
	printf("HC11 memory: %d bytes\n", m);
	FILE *fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("Could not open file!\n");
		return 1;
	}
	printf("File address: %p\n", (void *)fptr);
	(void)load_mem(&HC11, fptr);
	/*
	for (uint16_t i = 0x2000; i <= 0x2050; i += 2)
	{
		printf("addr %04X: %04X\n", i, (HC11.memory[i] << 8) + HC11.memory[i + 1]);
	}
	*/
	HC11.pc = 0x2000;
	init_inst();
	exec_inst(&HC11);
	fclose(fptr);
	end_mem(&HC11);
	return 0;
}
