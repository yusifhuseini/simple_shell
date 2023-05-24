#include "shell.h"

/**
 *handleExec - creates child process and handle exec
 * @_args: program exec arg
 * @av: shell name parameter
 * @env: env var
 * @pressed: num of param passed
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 1 or 0 int
 */
int handleExec(int *pressed, char **_args, char **av, char **env)
{
	int status, childPID, _flag = 0, no_path;
	char *_str_ev = NULL;

	no_path = funcStat(&_str_ev, &_flag, _args[0], *pressed, av[0], env);
	if (_str_ev != NULL)
	{
		_flag++;
		childPID = fork();
		if (childPID == 0)
			execve(_str_ev, _args, NULL);
		else if (childPID < 0)
			perror("command not ok");
		else if (childPID > 0)
		{
			do {
				waitpid(childPID, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	if (_flag == 0)
	{
		if (no_path != 1)
			_printf("%s: %d: %s: not found\n", av[0], *pressed, _args[0]);
	}
	if (_flag == 2)
		free(_str_ev);
	return (1);
}
