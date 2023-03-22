#include "main.h"

/**
 * _isalpha - checks for alphabets
 * @c: character to be check
 *
 * Return: 1 if character is a letter,0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'z') || (c >= 'A' && c <= 'z'))
		return (1);
	else
		return (0);
}
