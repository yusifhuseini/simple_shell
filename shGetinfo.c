#include "shell.h"

/**
 * clearInfo - func to initialize info_t struct
 * @info: struct address
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: void
 */
void clearInfo(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * setInfo - func to initialize info_t struct
 * @info: struct address
 * @av: arg vector
 */
void setInfo(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strTow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = stringDup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replaceAlias(info);
		replaceVars(info);
	}
}

/**
 * freeInfo - func to free info_t struct fields
 * @info: struct address
 * @all: free all fields
 * Return: true
 */
void freeInfo(info_t *info, int all)
{
	fFree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			freeList(&(info->env));
		if (info->history)
			freeList(&(info->history));
		if (info->alias)
			freeList(&(info->alias));
		fFree(info->environ);
			info->environ = NULL;
		bFree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		putChar(BUF_FLUSH);
	}
}
