#include "main.h"

/**
 * _getenv - Gets PATH member from environ
 * @name: Pointer to PATH string
 *
 * Return: Pointer to PATH member string or NULL if not found
 */
char *_getenv(const char *name)
{
	int i, result;

	for (i = 0; environ[i]; i++)
	{
		result = _PATHstrcmp(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

/**
 * _env - Prints the environ
 *
 * Return: Always 0 on success
 */
int _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
	}
	return (0);
}

/**
 * _puts - Prints a string
 * @str: String to print
 */
void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
	{
		_putchar(str[c]);
	}
	_putchar('\n');
}

/**
 * _putchar - Prints a character
 * @c: Character to print
 *
 * Return: Return value of write syscall
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _memset - Fills memory with a constant byte
 * @s: Character array to fill
 * @b: Constant byte to fill with
 * @n: Number of bytes to fill
 *
 * Return: The pointer to the char array
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
