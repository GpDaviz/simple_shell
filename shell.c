#include "main.h"
/**
 * main - runs the shell program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *fullypathedbuffer = NULL, *copy = NULL, *buffer = NULL;
	char *PATH = NULL;
	char **av;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		av = NULL;
		prompt();
		buffer = _read();
		if (*buffer != '\0')
	{
		av = tokenizer(buffer);
		if (av == NULL)
		{
			free(buffer);
			continue;
		}
		fullypathedbuffer = _fullypathedbuffer(av, PATH, copy);
		if (checkbuiltin(av, buffer, exitstatus) == 1)
			continue;
		exitstatus = _forkedprocess(av, buffer, fullypathedbuffer);
	}
		else
			free(buffer);
	}
	return (0);
}
