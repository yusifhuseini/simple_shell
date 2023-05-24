#include "shell.h"

/**
 * interact - return shell interactive mode
 * @info: struct address
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 1 interactive mode, 0 otherwise
 */
int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * isDelim - check delimiter character
 * @c: char checker
 * @delim: delimiter string
 * Return: 1 (true), 0 (false)
 */
int isDelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * isAlpha - check alphabetic character
 * @c: input character
 * Return: 1 (c alphabetic), or NULL
 */

int isAlpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * shAtoi - convert “a” str to int
 * @s: convert string
 * Return: 0 str num, or converted num
 */

int shAtoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
