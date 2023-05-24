#include "shell.h"

/**
  * handleBuiltin - choose correct fun based on input
  * @_args: inputs array
  * @env: env var
  * Code by - Huseini Yusif & Bennet Aboagye-Asare
  * Return: struct or NULL
  */
int handleBuiltin(char **_args, char **env)
{
	int i = 0;
	perfBu arrBu[] = {
		{"cd", cdFunc		},
		{"pwd", pwdFunc		},
		{"exit", exitFunc	},
		{"env", enviFunc	}
	};
	for (; i < 4; i++)
		if (_stringCmp(arrBu[i].s, _args[0]) == 0)
		{
			if (_stringCmp(arrBu[i].s, "env") == 0)
				return (arrBu[i].fun(env));
			else
				return (arrBu[i].fun(_args));
		}
	return (1);

}
