#include <unistd.h>
/**
 * main - writes the character c to stdout
 * %c: the character to print
 *
 * Return: on success 1.
 * On error, -1 is returned, and enno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
