#include "main.h"

/**
 * positive_or_negative - it checks for positive or negative value
 *@i: parameter
 * Return: Always 0 (success)
 */
void positive_or_negative(int i)
{
	if (i > 0)
		printf("%d is positive\n", i);
	else if (i == 0)
		printf("%d is zero\n", i);
	else
		printf("%d is negative\n", i);
}
