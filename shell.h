#ifndef SHELL_H
#define SHELL_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/signal.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * struct perFmt - percentage formats structure
 * @t: percentage format
 * @f: func
 */
typedef struct perFmt
{
	char t;
	void (*f)(va_list, int *);
} perF;

/**
 *struct bullIn - built-in function structure
 *@s: string to be evaluated
 *@fun: function correspond to the string
 */
typedef struct bullIn
{
	char *s;
	int (*fun)(char **);
} perfBu;

typedef void (*sighandler_t)(int);
char *getString(int *i);
char **tokenArg(char *_str);
int execFunc(int *pressed, char **_args, char **av, char **env);
int handleBuiltin(char **_args, char **env);
int handleExec(int *pressed, char **_args, char **av, char **env);
void *_realloc(void *ptr, int oldSize, int newSize);
int cdFunc(char **);
int pwdFunc(char **);
int exitFunc(char **);
int enviFunc(char **);
char *envFunc(char *_com, char **env, int *no_path);
char *_stringDup(char *str);
char *stringConcat(char *s1, char *s2);
int *_putchar(char c, int *p);
int _printf(const char *format, ...);
void printCharacter(va_list va, int *p);
void printString(va_list va, int *p);
void printInteger(va_list va, int *p);
int countFunc(char *s);
void printDecimal(va_list va, int *p);
int fmtFunc(const char *format, int i, va_list toPrint, int *pun);
int printNum(int n, int *p);
int _stringCmp(char *s1, char *s2);
int funcStat(char **_str, int *_fl, char *_com, int c, char *av_0, char **env);

#endif
