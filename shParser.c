#include "shell.h"

/**
 * isCmd - func to determine executable cmd file
 * @info: struct info
 * @path: file path
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 1 true, 0 false
 */
int isCmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dupChars - func to duplicate characters
 * @pathstr: PATH string
 * @start: index start
 * @stop: index stop
 * Return: new buffer pointer
 */
char *dupChars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * findPath - func to find this PATH string cmd
 * @info: struct info
 * @pathstr: string PATH
 * @cmd: find cmd
 * Return: cmd path or NULL
 */
char *findPath(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((strLen(cmd) > 2) && startsWith(cmd, "./"))
	{
		if (isCmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dupChars(pathstr, curr_pos, i);
			if (!*path)
				stringCat(path, cmd);
			else
			{
				stringCat(path, "/");
				stringCat(path, cmd);
			}
			if (isCmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
