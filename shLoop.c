#include "shell.h"

/**
 * hsh - main func shell loop
 * @info: info struct param
 * @av: main() arg vector
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 0 success, or 1 error
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clearInfo(info);
		if (interact(info))
			_puts("$ ");
		ePutChar(BUF_FLUSH);
		r = getInput(info);
		if (r != -1)
		{
			setInfo(info, av);
			builtin_ret = findBuiltin(info);
			if (builtin_ret == -1)
				findCmd(info);
		}
		else if (interact(info))
			putChar('\n');
		freeInfo(info, 0);
	}
	writeHistory(info);
	freeInfo(info, 1);
	if (!interact(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * findBuiltin - func to find a built-in cmd
 * @info: info struct param
 * Return: -1 (built-in), or 0 (executed) or -1 (not successful)
*/
int findBuiltin(info_t *info)
{
	int i, built_in_ret = -1;
	builtinT builtintbl[] = {
		{"exit", myExit},
		{"env", myEnv},
		{"help", myHelp},
		{"history", myHistory},
		{"setenv", mySetEnv},
		{"unsetenv", myUnsetEnv},
		{"cd", myCd},
		{"alias", myAlias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (stringCmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * findCmd - func to find PATH cmd
 * @info: info struct param
 * Return: void
 */
void findCmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!isDelim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = findPath(info, getEnv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		forkCmd(info);
	}
	else
	{
		if ((interact(info) || getEnv(info, "PATH=")
			|| info->argv[0][0] == '/') && isCmd(info, info->argv[0]))
			forkCmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			printError(info, "not found\n");
		}
	}
}

/**
 * forkCmd - func to fork exec thread cmd
 * @info: info struct param
 * Return: void
 */
void forkCmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, getEnviron(info)) == -1)
		{
			freeInfo(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				printError(info, "Permission denied\n");
		}
	}
}
