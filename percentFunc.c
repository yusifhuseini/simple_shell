#include "shell.h"

/**
  * printCharacter - prints a char
  * @p: _printf pointer
  * @va: varg arg
  * Code by - Huseini Yusif & Bennet Aboagye-Asare
  * Return: Void
  */
void printCharacter(va_list va, int *p)
{
	char c = (char) va_arg(va, int);

	_putchar(c, p);
}

/**
  * printString - prints a string
  * @p: _printf pointer
  * @va: varg argu
  * Return: void
  */
void printString(va_list va, int *p)
{
	char *st = va_arg(va, char*);
	char nu[] = "(null)";
	int i = 0, k = 0;

	if (st == NULL)
	{
		while (nu[k])
		{
			_putchar(nu[k], p);
			k++;
		}
	}
	else
	{
		while (st[i])
		{
			_putchar(st[i], p);
			i++;
		}
	}
}

/**
 * printInteger - prints an integer
 * @p: _printf pointer
 * @va: varg arg
 * Return: void
 */
void printInteger(va_list va, int *p)
{
	int r;
	int c = va_arg(va, int);

	r = printNum(c, p);
	p += r;
}

/**
 * printDecimal - prints a decimal num
 * @p: _printf pointer
 * @va: varg arg
 * Return: void
 */
void printDecimal(va_list va, int *p)
{
	int r;
	int c = va_arg(va, int);

	r = printNum(c, p);
	p += r;
}
