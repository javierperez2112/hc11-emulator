#include "hc11.h"
#include <stdlib.h>

int init_mem(hc11_t *hc11)
{
	hc11->memory = (uint8_t *)calloc(sizeof(uint8_t), MEM_SIZE);
	if (hc11->memory == NULL)
	{
		return -1;
	}
	else
	{
		return MEM_SIZE;
	}
}

void end_mem(hc11_t *hc11)
{
	if (hc11->memory != NULL)
	{
		free(hc11->memory);
		hc11->memory = NULL;
	}
	return;
}

static uint8_t hex_to_nibble(char hex)
{
	if ('0' <= hex && '9' >= hex)
	{
		return (hex - '0');
	}
	else if ('A' <= hex && 'F' >= hex)
	{
		return (0xA + hex - 'A');
	}
	else
	{
		return 0;
	}
}

static uint8_t get_byte(FILE *fileptr)
{
	char msn = fgetc(fileptr); // Most significant nibble
	char lsn = fgetc(fileptr); // Least significant nibble
	uint8_t byte = (hex_to_nibble(msn) << 4) + hex_to_nibble(lsn);
	return byte;
}

static uint16_t get_two_bytes(FILE *fileptr)
{
	uint8_t msby = get_byte(fileptr); // Most significant byte
	uint8_t lsby = get_byte(fileptr); // Least significant byte
	uint16_t two_bytes = (msby << 8) + lsby;
	return two_bytes;
}

int load_mem(hc11_t *hc11, FILE *fileptr)
{
	if (hc11->memory == NULL || fileptr == NULL)
		return -1;
	rewind(fileptr);
	char c;
	uint8_t byte_count;
	uint16_t address;
	while ((c = fgetc(fileptr)) != EOF)
	{
		if (c != 'S')
			continue;
		if (fgetc(fileptr) != '1')
			continue;
		byte_count = get_byte(fileptr) - 3; // Subtract checksum and address!
		address = get_two_bytes(fileptr);	// Obtain address
		for (int i = 0; i < byte_count; i++)
		{
			hc11->memory[address] = get_byte(fileptr);
			address++;
		}
	}
	return 0;
}
