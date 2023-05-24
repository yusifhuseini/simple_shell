#include "shell.h"

/**
 * bFree - func to free pointer address
 * @ptr: address pointer
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 1 freed, or 0
 */
int bFree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
