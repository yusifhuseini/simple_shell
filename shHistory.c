#include "shell.h"

/**
 * getHistoryFile - func to get history file
 * @info: parameter struct
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: str history file
 */
char *getHistoryFile(info_t *info)
{
	char *buf, *dir;

	dir = getEnv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (strLen(dir) + strLen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	stringCpy(buf, dir);
	stringCat(buf, "/");
	stringCat(buf, HIST_FILE);
	return (buf);
}

/**
 * writeHistory - func to create a file, or append existing file
 * @info: parameter struct
 * Return: 1 on success, or -1
 */
int writeHistory(info_t *info)
{
	ssize_t fd;
	char *filename = getHistoryFile(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		putsFd(node->str, fd);
		putFd('\n', fd);
	}
	putFd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * readHistory - func to read history file
 * @info: the parameter struct
 * Return: histcount (success), or 0
 */
int readHistory(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = getHistoryFile(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			buildHistoryList(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		buildHistoryList(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		deleteNodeAtIndex(&(info->history), 0);
	renumHstory(info);
	return (info->histcount);
}

/**
 * buildHistoryList - func to add entry to history linked list
 * @info: arg struct func prototype
 * @buf: buffer
 * @linecount: history linecount
 * Return: histcount
 */
int buildHistoryList(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	addNodeEnd(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumHstory - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumHstory(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
