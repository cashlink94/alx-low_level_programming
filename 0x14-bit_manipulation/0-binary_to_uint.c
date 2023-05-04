#include "main.h"

/**
 * binary_to_uint - converts a binary number in a string to an unsigned integer
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal_value = 0;

	/* check that the input string is not NULL */
	if (!b)
		return (0);

	/* iterate through each character of the string */
	for (int i = 0; b[i]; i++)
	{
		/* if a non-binary character is found, return 0 */
		if (b[i] != '0' && b[i] != '1')
			return (0);

		/* convert the binary number to decimal using positional notation */
		decimal_value = 2 * decimal_value + (b[i] - '0');
	}

	return (decimal_value);
}

