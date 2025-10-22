#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
* main - point d'entr  e du programme
*
* Return: toujours 0 (succ  s)
*/

int main(void)
{
int n, last_digit;

srand(time(0));
n = rand() - RAND_MAX / 2;
last_digit = n % 10;

if (n % 10 > 5)
{
printf("%d and is greater than 5\n", n%10);
}
else if (n % 10 == 0)
{
printf("%d and is 0\n", n%10);
}
else if (n % 10 < 6 && n != 0)
{
printf("%d and is less than 6 and not 0\n", n%10);
}
return (0);
}
