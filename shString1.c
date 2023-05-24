#include "shell.h"

/**
 * strLen - string length
 * @s: check string length
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: int str length
 */
int strLen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * stringCmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: neg (s1 < s2), pos (s1 > s2), zero (s1 == s2)
 */
int stringCmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * startsWith - haystack checker
 * @haystack: search string
 * @needle: find substring
 * Return: haystack address or NULL
 */
char *startsWith(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * stringCat - concatenates two strings
 * @dest: buffer destination
 * @src: buffer source
 * Return: buffer dest pointer
 */
char *stringCat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
