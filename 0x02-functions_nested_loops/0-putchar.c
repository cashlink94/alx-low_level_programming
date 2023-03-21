#include <stdio.h>
#include "main.h"
/**
 * main - print _putchar
 * is written by ralf
 * Return: 0
 */

int main(void)
{
	char i[8] = "_putchar";
	int m;

	for (m = 0; m < 8; m++)
	{
		_putchar(i[m]);
	}
	_putchar('\n');

	return (0);
}
