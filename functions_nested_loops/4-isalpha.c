#include "main.h"

/**
 * isalpha check all th alphabetic caractere
 * @c: c to check
 *
 * return 1 if c is a letter low or upp if not 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
