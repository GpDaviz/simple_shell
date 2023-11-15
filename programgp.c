#include "main.h"
/**
 * getenvin - gets PATH member from environ
 * @name: pointer to PATH string
 *
 * Return: pointer to PATH member string or NULL if not found
 */
char *getenvin(const char *name)
{
	int t, result;

	for (t = 0; environ[t]; t++)
	{
		result = _PATHstrcmp(name, environ[t]);
		if (result == 0)
	{
		return (environ[t]);
	}
	}
	return (NULL);
}
/**
 * envin - prints the environ
 *
 * Return: 0 on success
 */
int envin(void)
{
	int t;

	for (t = 0; environ[t]; t++)
		puts(environ[t]);
	return (0);
}
/**
 * puts - prints a string
 * @str: string to print
 */
void puts(char *str)
{
	int t;

	for (t = 0; str[t] != '\0'; t++)
		putchar(str[t]);
	putchar('\n');
}
/**
 * putchar - prints a character
 * @t: character to print
 *
 * Return: return value of write syscall
 */
int putchar(char t)
{
	return (write(1, &t, 1));
}
/**
 * memsetin - fills memory with a constant byte
 * @r: character array to fill
 * @b: constant byte to fill with
 * @n: how many bytes to fill
 * Return: the pointer to the char array
 */
char *memsetin(char *r, char b, unsigned int n)
{
	unsigned int t;

	for (t = 0; t < n; t++)
	r[t] = b;
	return (r);
}
