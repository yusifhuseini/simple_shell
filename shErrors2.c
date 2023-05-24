#include "shell.h"

/**
 * errAtoi - func to convert a str to int
 * @s: convert string
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 0 (num str) or -1 (error)
 */
int errAtoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * printError - func to print error message
 * @info: info struct param
 * @estr: contain string error type
 * Return: 0 (str num), -1 (error)
 */
void printError(info_t *info, char *estr)
{
	ePuts(info->fname);
	ePuts(": ");
	printD(info->line_count, STDERR_FILENO);
	ePuts(": ");
	ePuts(info->argv[0]);
	ePuts(": ");
	ePuts(estr);
}

/**
 * printD - func to print decimal
 * @input: user input
 * @fd: write to file descriptor
 * Return: print num char
 */
int printD(int input, int fd)
{
	int (*_putChar)(char) = putChar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		_putChar = ePutChar;
	if (input < 0)
	{
		_abs_ = -input;
		_putChar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			_putChar('0' + current / i);
			count++;
		}
		current %= i;
	}
	_putChar('0' + current);
	count++;

	return (count);
}

/**
 * convertNum - func to convert int to “a”
 * @num: number
 * @base: base
 * @flags: arg flags
 * Return: string
 */
char *convertNum(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * removeComm - func to replace '#' with '\0'
 * @buf: string address
 * Return: always 0
 */
void removeComm(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
