#include "shell.h"

/**
  * cdFunc - change directory
  * @_args: arg info location
  * Code by - Huseini Yusif & Bennet Aboagye-Asare
  * Return: always 1
  */
int cdFunc(char **_args)
{
	printf("Entered cdFunc function: %s\n", _args[0]);
	return (1);
}

/**
  * pwdFunc - prints working directory
  * @_args: arg info location
  * Return: always 1
  */
int pwdFunc(char **_args)
{
	printf("Entered pwdFunc function: %s\n", _args[0]);
	return (1);
}

/**
  * exitFunc - exit terminal
  * @_args: arg info location
  * Return: always 0 or 1
  */
int exitFunc(char **_args)
{
	char *ex = "exit";

	if (_stringCmp(_args[0], ex) == 0)
	{
		return (0);
	}
	return (1);
}

/**
  * enviFunc - prints env var
  * @env: env var
  * Return: always 1
  */
int enviFunc(char **env)
{
	int i = 0;

	while (env[i])
	{
		_printf("%s\n", env[i]);
		i++;
	}

	return (1);
}
