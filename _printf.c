#include "shell.h"

/**
  * _printf - prints char and str
  * @format: format print char with str
  * Code by - Huseini Yusif & Bennet Aboagye-Asare
  * Return: -1 (error) or char count
  */
int _printf(const char *format, ...)
{
	int i = 0, res = 0, len = 0;
	int *ptr;
	va_list toPrint;

	if (format == NULL)
	{
		return (-1);
	}
	ptr = &len;
	va_start(toPrint, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			res = fmtFunc(format, i, toPrint, ptr);
			if (res == -1)
			{
				return (-1);
			}
			if (!res)
			{
				va_end(toPrint);
				return (len);
			}
			i += res;
			continue;

		}
		else
		{
			 _putchar(format[i], ptr);
		}
		i++;
	}
	va_end(toPrint);
	return (len);
}
