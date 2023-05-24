#include "shell.h"

/**
  * envFunc - function search for PATH
  * @_com: search for PATH
  * @env: an array path
  * @no_path: num of elements PATH variable
  * Code by - Huseini Yusif & Bennet Aboagye-Asare
  * Return: str path or NULL
  */
char *envFunc(char *_com, char **env, int *no_path)
{
	int i = 0;
	char *_delim = "=:";
	char *_slash = "/";
	char *key = "PATH";
	char *concat_dir = NULL;
	char *concat_param = NULL;
	char *_temp = NULL;
	char *_token = NULL;

	while (env[i])
	{
		_temp = _stringDup(env[i]);
		_token = strtok(_temp, _delim);
		if (_stringCmp(_token, key) == 0)
		{
			while (_token)
			{
				*no_path = *no_path + 1;
				concat_dir = stringConcat(_token, _slash);
				concat_param = stringConcat(concat_dir, _com);
				if (access(concat_param, F_OK) == 0)
				{
					free(_temp);
					_temp = NULL;
					free(concat_dir);
					return (concat_param);
				}
				free(concat_dir);
				free(concat_param);
				_token = strtok(NULL, _delim);
				concat_param = NULL;
				concat_dir = NULL;
			}
		_token = NULL;
		}
		free(_temp);
		_temp = NULL;
		i++;
	}
	return (NULL);
}

/**
 * _stringDup - creates array copy
 * @str: copy array
 * Return: array pointer
 */
char *_stringDup(char *str)
{
	int i;
	int j;
	char *t;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		i++;
	}
	i++;
	t = (char *) malloc(i * sizeof(char));
	if (t == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		t[j] = str[j];
	}
	return (t);
}

/**
 * stringConcat - Concatenate strings
 * @s1: str 1
 * @s2: str 2
 * Return: array pointer
 */
char *stringConcat(char *s1, char *s2)
{
	int i = 0, j = 0, k = 0, l = 0;
	char *t;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i])
	{
		i++;
	}
	while (s2[j])
	{
		j++;
	}
	j++;
	t = (char *) malloc((i + j) * sizeof(char));
	if (t == NULL)
		return (NULL);
	for (k = 0; k < i; k++)
	{
		t[k] = s1[k];
	}
	for (l = 0; l < j; l++)
	{
		t[i + l] = s2[l];
	}
	return (t);
}
