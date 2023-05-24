#include "shell.h"

/**
 * fmtFunc - print format function
 * @format: format to print
 * @i: integer
 * @toPrint: print list
 * @pun: printf pointer
 * Return: 1 or 2 or 0 int
 */
int fmtFunc(const char *format, int i, va_list toPrint, int *pun)
{
	int c = 0;

	perF relFuncFmt[] = {
		{'c', printCharacter		},
		{'s', printString	},
		{'i', printInteger		},
		{'d', printDecimal		}
	};

	if (format[i + 1] == '\0')
		return (-1);
	if (format[i + 1] == 'K' || format[i + 1] == '!')
	{
		_putchar(format[i], pun);
		return (1);
	}
	if (format[i + 1] == '%')
	{
		_putchar('%', pun);
		return (2);
	}
	while (c < 4)
	{
		if (relFuncFmt[c].t == format[i + 1])
		{
			relFuncFmt[c].f(toPrint, pun);
			return (2);
		}
		c++;
	}
	if (format[i + 1] == ' ')
		return (1 + fmtFunc(format, i + 1, toPrint, pun));
	else if (format[i + 1] != '\0')
	{
		_putchar(format[i + 1], pun);
		return (2);
	}
	else
		return (0);
}
