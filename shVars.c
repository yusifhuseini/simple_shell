#include "shell.h"

/**
 * isChain - test buffer delimiter chain
 * @info: param struct
 * @buf: char buffer
 * @p: address buf position
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 1 (chain delimiter), 0 (NULL)
 */
int isChain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * checkChain - check chain last status
 * @info: param struct
 * @buf: char buffer
 * @p: address buf position
 * @i: starting position in buf
 * @len: buf length
 * Return: (void)
 */
void checkChain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replaceAlias - replace token str aliases
 * @info: param struct
 * Return: 1 (replaced), 0 (NULL)
 */
int replaceAlias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = nodeStartsWith(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strChr(node->str, '=');
		if (!p)
			return (0);
		p = stringDup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replaceVars - replace token str vars
 * @info: param struct
 * Return: 1 (replaced), 0 otherwise
 */
int replaceVars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!stringCmp(info->argv[i], "$?"))
		{
			replaceString(&(info->argv[i]),
				stringDup(convertNum(info->status, 10, 0)));
			continue;
		}
		if (!stringCmp(info->argv[i], "$$"))
		{
			replaceString(&(info->argv[i]),
				stringDup(convertNum(getpid(), 10, 0)));
			continue;
		}
		node = nodeStartsWith(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replaceString(&(info->argv[i]),
				stringDup(_strChr(node->str, '=') + 1));
			continue;
		}
		replaceString(&info->argv[i], stringDup(""));

	}
	return (0);
}

/**
 * replaceString - func to replaces string
 * @old: old string address
 * @new: new string address
 * Return: 1 replaced, or NULL
 */
int replaceString(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
