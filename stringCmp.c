#include "shell.h"

/**
 * _stringCmp - compares char and str
 * @s1: str destination
 * @s2: str origin
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: char str
 */
int _stringCmp(char *s1, char *s2)
{
	int i, j, a, b;

	i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		/*printf("got into the _stringCmp cycle");*/
		i++;
	}
	a = (s1[i] - '0');
	b = (s2[i] - '0');
	j = a - b;

	return (j);
}
