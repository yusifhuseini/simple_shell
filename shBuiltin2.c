#include "shell.h"

/**
 * myHistory - display history list by cmd line
 * @info: arg struct func prototype
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 *  Return: always 0
 */
int myHistory(info_t *info)
{
	printList(info->history);
	return (0);
}

/**
 * unsetAlias - sets alias to str
 * @info: parameter struct
 * @str: string alias
 * Return: 0 (success), 1 (error)
 */
int unsetAlias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strChr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = deleteNodeAtIndex(&(info->alias),
		getNodeIndex(info->alias, nodeStartsWith(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * setAlias - sets alias to str
 * @info: parameter struct
 * @str: string alias
 * Return: 0 (success), 1 (error)
 */
int setAlias(info_t *info, char *str)
{
	char *p;

	p = _strChr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unsetAlias(info, str));

	unsetAlias(info, str);
	return (addNodeEnd(&(info->alias), str, 0) == NULL);
}

/**
 * printAlias - prints an alias string
 * @node: the alias node
 * Return: 0 (success), 1 (error)
 */
int printAlias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strChr(node->str, '=');
		for (a = node->str; a <= p; a++)
			putChar(*a);
		putChar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * myAlias - mimic alias built-in
 * @info: arg struct func prototype
 *  Return: always 0
 */
int myAlias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printAlias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strChr(info->argv[i], '=');
		if (p)
			setAlias(info, info->argv[i]);
		else
			printAlias(nodeStartsWith(info->alias, info->argv[i], '='));
	}

	return (0);
}
