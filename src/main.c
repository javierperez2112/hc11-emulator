#include "hc11.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

/* THIS FILE IS ONLY FOR TESTING PURPOSES!!! */

void print_state(hc11_t *hc11)
{
	printf("---------------------------\n");
	printf("ACC_A: %02X\nACC_B: %02X\nPC: %04X\n", hc11->acc_a, hc11->acc_b, hc11->pc);
}

long get_mem_usage()
{
	struct rusage my_usage;
	getrusage(RUSAGE_SELF, &my_usage);
	return my_usage.ru_maxrss;
}

int main(int argc, char **argv)
{
	printf("# DEBUG #\n");
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
	print_state(&HC11);
	exec_inst(&HC11);
	print_state(&HC11);
	exec_inst(&HC11);
	print_state(&HC11);
	printf("Usage: %ld\n", get_mem_usage());
	fclose(fptr);
	end_mem(&HC11);
	end_inst();
	return 0;
}
