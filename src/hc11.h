#ifndef _HC11_H
#define _HC11_H

#include <stdint.h>
#include <stdio.h>

#define MEM_SIZE 0x10000 // HC11 memory size

typedef struct
{
	union
	{
		struct
		{
			uint8_t acc_a; // Accumulator A
			uint8_t acc_b; // Accumulator B
		};
		uint16_t acc_d; // Accumulator D (A|B)
	};
	uint16_t ind_x; // Index X
	uint16_t ind_y; // Index Y
	uint16_t pc;	// Program counter
	uint16_t sp;	// Stack pointer
	union
	{
		uint8_t ccr; // Condition code register
		struct
		{
			uint8_t carry : 1;
			uint8_t overflow : 1;
			uint8_t zero : 1;
			uint8_t negative : 1;
			uint8_t int_mask : 1;
			uint8_t h_carry : 1;
			uint8_t x_int : 1;
			uint8_t stp_dis : 1;
		};
	};
	uint8_t *memory; // HC11 memory map
} hc11_t;			 // HC11 state

/* Memory related functions */
int init_mem(hc11_t *hc11);				   // Allocate HC11 memory
void end_mem(hc11_t *hc11);				   // Free HC11 memory
int load_mem(hc11_t *hc11, FILE *fileptr); // Load S19 into memory

/* Instruction related functions */

void init_inst(void);			// Initialize instruction search tree
void exec_inst(hc11_t *hc11);	// Fetch-decode-execute one instruction

#endif // _HC11_H
