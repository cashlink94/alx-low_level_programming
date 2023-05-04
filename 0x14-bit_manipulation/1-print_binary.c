#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: the number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i;
	unsigned long int current;
	int has_printed_one = 0;

	/* loop through each bit of the number */
	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		/* if the current bit is set, print a '1' */
		if (current & 1)
		{
			_putchar('1');
			has_printed_one = 1; /* indicate that at least one '1' has been printed */
		}
		/* if printed at least one '1', print a '0' for any subsequent unset bits */
		else if (has_printed_one)
			_putchar('0');
	}

	/* if the number is 0, print a single '0' */
	if (!has_printed_one)
		_putchar('0');
}

