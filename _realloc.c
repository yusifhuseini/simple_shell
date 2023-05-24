#include "shell.h"

/**
  * _realloc - func to reallocate memory block
  * @ptr: memory block
  * @oldSize: old memory size ptr
  * @newSize: new memory size realloc
  * Code by - Huseini Yusif & Bennet Aboagye-Asare
  * Return: new reallocated str
  */
void *_realloc(void *ptr, int oldSize, int newSize)
{
	char *s;
	int i = 0;

	if (newSize == oldSize)
		return (ptr);

	if (newSize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	s = malloc(newSize);
	if (s == NULL)
		return (NULL);
	if (ptr == NULL)
		return (s);
	while (i < newSize && i < oldSize)
	{
		s[i] = ((char *) ptr)[i];
		i++;
	}
	free(ptr);
	return (s);
}
