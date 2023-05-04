#include "main.h"

/**
 * get_endianness - checks the  endians
 * Return: 0 for big endians, 1 for little endians
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}

