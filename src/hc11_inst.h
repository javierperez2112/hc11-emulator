#ifndef _HC11_INST_H
#define _HC11_INST_H

#include <stdint.h>
#include "hc11.h"

#define LEVEL_SIZE 0x100

typedef struct
{
	uint8_t value;
	uint16_t address;
} arg_t;	// Return value for addressing mode functions


typedef struct
{
	char *mnemonic;						// Mnemonic (name)
	union
	{
		uint16_t opcode;				// Opcode	
		struct
		{
			uint16_t opcode_lsby : 8;	// Least significant byte
			uint16_t opcode_msby : 8;	// Most significant byte
		};
	};
	void (*op)(hc11_t*, arg_t (*)(hc11_t*));	// Operation function
	arg_t (*mode)(hc11_t*);					// Addressing mode function
	uint8_t cycles;								// Cycles taken (see instruction table)
} inst_t;	// Instruction data

#endif // _HC11_INST_H
