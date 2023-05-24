#include "shell.h"

/**
 * listLen - func to determine linked list lengh
 * @h: first node pointer
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: list size
 */
size_t listLen(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * listToStrings - func to return str array (list->str)
 * @head: first node pointer
 * Return: strings array
 */
char **listToStrings(list_t *head)
{
	list_t *node = head;
	size_t i = listLen(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(strLen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = stringCpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * printList - func to print all list_t linked list element
 * @h: first node pointer
 * Return: list size
 */
size_t printList(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convertNum(h->num, 10, 0));
		putChar(':');
		putChar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * nodeStartsWith - func to return str node with prefix
 * @node: list head pointer
 * @prefix: match string
 * @c: match character prefix
 * Return: node or null
 */
list_t *nodeStartsWith(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = startsWith(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * getNodeIndex - func to get node index
 * @head: list head pointer
 * @node: node pointer
 * Return: node index or -1
 */
ssize_t getNodeIndex(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
