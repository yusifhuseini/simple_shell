#include "shell.h"

/**
 *funcStat - evaluates arg condition
 * @_str: str pointer
 * @_fl: flag pointer
 * @_com: shell cmd
 * @env: env var
 * @c: press counter
 * @av_0: main arg
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 1 or 0 int
 */
int funcStat(char **_str, int *_fl, char *_com, int c, char *av_0, char **env)
{
	struct stat  *bf;
	int no_path = 0;

	*_str = envFunc(_com, env, &no_path);
	if (*_str != NULL)
		*_fl += 1;
	if (*_str == NULL)
	{
		bf = malloc(sizeof(struct stat));
		if (bf == NULL)
			return (1);
		if (stat(_com, bf) == 0 && S_ISDIR(bf->st_mode))
		{
			*_fl += 1;
			_printf("%s: %d: %s: Permission denied\n", av_0, c, _com);
			free(bf);
			return (1);
		}
		else if (stat(_com, bf) == 0 && S_ISREG(bf->st_mode))
		{
			*_str = _com;
			free(bf);
		}
		else
			free(bf);
	}
	return (no_path);
}
