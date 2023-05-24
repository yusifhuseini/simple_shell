#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/** R/W buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/** CMD chain */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/** Number conversion */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/** System getline() */
#define USEgetLine 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct infoPass - pseudo-arg pass into func pointer
 *@arg: str getline arg
 *@argv: array str arg
 *@path: str path cmd
 *@argc: arg counter
 *@line_count: error counter
 *@err_num: error exit code
 *@linecount_flag: line input counter
 *@fname: program filename
 *@env: env local linked list
 *@environ: modified env custom
 *@history: node history
 *@alias: node alias
 *@env_changed: environ changed
 *@status: return status exec cmd
 *@cmd_buf: cmd_buf address pointer
 *@cmd_buf_type: CMD_type &&, ;, and ||
 *@readfd: fd line input
 *@histcount: history counter
 */
typedef struct infoPass
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - built-in str function
 *@type: built-in cmd flag
 *@func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtinT;



/* shLoop.c */
int hsh(info_t *, char **);
int findBuiltin(info_t *);
void findCmd(info_t *);
void forkCmd(info_t *);
int loopHsh(char **);

/* shParser.c */
int isCmd(info_t *, char *);
char *dupChars(char *, int, int);
char *findPath(info_t *, char *, char *);

/* shErrors.c */
void ePuts(char *);
int ePutChar(char);
int putFd(char c, int fd);
int putsFd(char *str, int fd);

/* shString.c */
int strLen(char *);
int stringCmp(char *, char *);
char *startsWith(const char *, const char *);
char *stringCat(char *, char *);

/* shString1.c */
char *stringCpy(char *, char *);
char *stringDup(const char *);
void _puts(char *);
int putChar(char);

/* shExits.c */
char *_strnCpy(char *, char *, int);
char *_strnCat(char *, char *, int);
char *_strChr(char *, char);

/* shTokenizer.c */
char **strTow(char *, char *);
char **strTow2(char *, char);

/* shRealloc.c */
char *memSet(char *, char, unsigned int);
void fFree(char **);
void *reAlloc(void *, unsigned int, unsigned int);

/* shMemory.c */
int bFree(void **);

/* shAtoi.c */
int interact(info_t *);
int isDelim(char, char *);
int isAlpha(int);
int shAtoi(char *);

/* shErrors1.c */
int errAtoi(char *);
void printError(info_t *, char *);
int printD(int, int);
char *convertNum(long int, int, int);
void removeComm(char *);

/* shBuiltin.c */
int myExit(info_t *);
int myCd(info_t *);
int myHelp(info_t *);

/* shBuiltin1.c */
int myHistory(info_t *);
int myAlias(info_t *);

/*shGetline.c */
ssize_t getInput(info_t *);
int getLine(info_t *, char **, size_t *);
void sigintHandler(int);

/* shGetinfo.c */
void clearInfo(info_t *);
void setInfo(info_t *, char **);
void freeInfo(info_t *, int);

/* shEnviron.c */
char *getEnv(info_t *, const char *);
int myEnv(info_t *);
int mySetEnv(info_t *);
int myUnsetEnv(info_t *);
int popuEnvList(info_t *);

/* shGetenv.c */
char **getEnviron(info_t *);
int unSetEnv(info_t *, char *);
int SetEnv(info_t *, char *, char *);

/* shHistory.c */
char *getHistoryFile(info_t *info);
int writeHistory(info_t *info);
int readHistory(info_t *info);
int buildHistoryList(info_t *info, char *buf, int linecount);
int renumHstory(info_t *info);

/* shLists.c */
list_t *addNode(list_t **, const char *, int);
list_t *addNodeEnd(list_t **, const char *, int);
size_t printListStr(const list_t *);
int deleteNodeAtIndex(list_t **, unsigned int);
void freeList(list_t **);

/* shLists1.c */
size_t listLen(const list_t *);
char **listToStrings(list_t *);
size_t printList(const list_t *);
list_t *nodeStartsWith(list_t *, char *, char);
ssize_t getNodeIndex(list_t *, list_t *);

/* shVars.c */
int isChain(info_t *, char *, size_t *);
void checkChain(info_t *, char *, size_t *, size_t, size_t);
int replaceAlias(info_t *);
int replaceVars(info_t *);
int replaceString(char **, char *);

#endif
