#include "shell.h"

/**
 **_strnCpy - func to copy string
 *@dest: string destination
 *@src: string source
 *@n: copy char
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 *Return: concatenated string
 */
char *_strnCpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strnCat - func to concatenate two strings
 *@dest: string 1
 *@src: string 2
 *@n: max bytes
 *Return: concatenated string
 */
char *_strnCat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strChr - func to locate char str
 *@s: parsed string
 *@c: look for char
 *Return: memory pointer
 */
char *_strChr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
