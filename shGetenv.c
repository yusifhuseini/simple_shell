#include "shell.h"

/**
 * getEnviron - func to return array string copy
 * @info: arg struct func prototype
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: always 0
 */
char **getEnviron(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = listToStrings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * unSetEnv - func to remove env var
 * @info: arg struct func prototype
 *  Return: 1 (delete), or 0 otherwise
 * @var: var str env
 */
int unSetEnv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = startsWith(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = deleteNodeAtIndex(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * SetEnv - func to initialize new env variable
 * @info: arg struct func prototype
 * @var: string env var
 * @value: value string env var
 *  Return: always 0
 */
int SetEnv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(strLen(var) + strLen(value) + 2);
	if (!buf)
		return (1);
	stringCpy(buf, var);
	stringCat(buf, "=");
	stringCat(buf, value);
	node = info->env;
	while (node)
	{
		p = startsWith(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	addNodeEnd(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
