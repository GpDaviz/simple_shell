#ifndef GODSPOWER_H
#define GODSPOWER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/* PATH Shell Functions */

/* Program Flow Gp */

int _prompt(void);
char *readit(void);
char *fullypathedbuffer(char **av, char *PATH, char *copy);
int _checkbuiltin(char **av, char *buffer, int exitstatus);
int forkedprocess(char **av, char *buffer, char *fullypathedbuffer);

/* String Helper Functions */

char *_strdup(char *str);
int _splitstring(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

/*Tokenize & PATH Helper Functions*/

char **tokenize(char *buffer);
int _splitPATH(char *str);
int _PATHstrcmp(const char *s1, const char *s2);
char *_concat(char *tmp, char **av, char *tok);

/* Program gp Functions */

char *getenvin(const char *name);
int envin(void);
void _puts(char *str);
int _putchar(char t);
char *memsetin(char *r, char b, unsigned int n);

#endif /* GODSPOWER_H */
