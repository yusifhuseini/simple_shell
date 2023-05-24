#include "shell.h"

/**
 * execFunc - func exec arg
 * @_args: arg var
 * @av: print name of the shell
 * @env: env var
 * @pressed: new cmd pressed n times
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 1 or 0 int
 */
int execFunc(int *pressed, char  **_args, char **av, char **env)
{
	int i;
	char *_build_arr[] = {"cd", "pwd", "exit", "env"};

	for (i = 0; i < 4; i++)
	{
		if (_stringCmp(_args[0], _build_arr[i]) == 0)
		{

			return (handleBuiltin(_args, env));
		}
	}

	return (handleExec(pressed, _args, av, env));
}
