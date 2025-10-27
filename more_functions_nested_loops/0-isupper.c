#include <stdio.h>
#include "main.h"

/**
* _isupper - checks for uppercase character.
*
* retrun 0 (success _isupper)
*/

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);

	else
		return (0);
}
