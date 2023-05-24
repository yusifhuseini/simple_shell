#include "shell.h"

/**
 **memSet - func to fill memory constant byte
 *@s: memory area pointer
 *@b: fill *s byte
 *@n: filled bytes
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 *Return: memory area pointer
 */
char *memSet(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * fFree - func to free string
 * @pp: str strings
 */
void fFree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * reAlloc - func to reallocate memory block
 * @ptr: malloc'ated block pointer
 * @old_size: old byte block size
 * @new_size: new byte block size
 * Return: memory block pointer
 */
void *reAlloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
