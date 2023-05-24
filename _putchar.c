#include <unistd.h>

/**
* _putchar - output char c to STDOUT
* @c: print char
* @p: length pointer
* Code by - Huseini Yusif & Bennet Aboagye-Asare
* Return: 1 (success) or -1 (error)
*/
int _putchar(char c, int *p)
{
	*p += 1;

	return (write(1, &c, 1));
}
