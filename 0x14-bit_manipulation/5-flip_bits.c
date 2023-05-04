#include "main.h"

/**
 * flip_bits - calculate the number of bits you would
 * need to ajustp to get from one number to another
 * @n: number one.
 * @m: second number.
 *
 * Return: number of bits to modify
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits;

	for (nbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			nbits++;
	}

	return (nbits);
}

