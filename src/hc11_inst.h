#ifndef _H11_INST_H
#define _HC11_INST_H

#include <stdint.h>
#include "hc11.h"

typedef struct
{
	char *mnemonic;
	union
	{
		uint16_t opcode;
		struct
		{
			uint16_t opcode_lsby : 8; // Least significant byte
			uint16_t opcode_msby : 8; // Most significant byte
		};
	};
	void (*op)(hc11_t*);
	uint8_t cycles;
} inst_t;

#endif // _HC11_INST_H
