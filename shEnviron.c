#include "shell.h"

/**
 * myEnv - func to print current env
 * @info: arg struct func prototype
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: always 0
 */
int myEnv(info_t *info)
{
	printListStr(info->env);
	return (0);
}

/**
 * getEnv - get environ var value
 * @info: arg struct func prototype
 * @name: env var
 * Return: value
 */
char *getEnv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = startsWith(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * mySetEnv - func to initialize a new env var
 * @info: arg struct func prototype
 *  Return: always 0
 */
int mySetEnv(info_t *info)
{
	if (info->argc != 3)
	{
		ePuts("Incorrect number of arguements\n");
		return (1);
	}
	if (SetEnv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * myUnsetEnv - func to remove env var
 * @info: arg struct func prototype
 *  Return: always 0
 */
int myUnsetEnv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		ePuts("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		unSetEnv(info, info->argv[i]);

	return (0);
}

/**
 * popuEnvList - func to populate env linked list
 * @info: arg struct func prototype
 * Return: always 0
 */
int popuEnvList(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		addNodeEnd(&node, environ[i], 0);
	info->env = node;
	return (0);
}
