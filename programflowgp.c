#include "main.h"
/**
 * _prompt - writes a prompt
 *
 * Return: 0 on sucess
 */
int _prompt(void)
{
	char *prompt = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, prompt, 2);
		if (writecount == -1)
		exit(0);
	}
	return (0);
}
/**
 * readit - read stdin and save it in a buffer
 *
 * Return: a pointer to the buffer
 */
char *readit(void)
{
	ssize_t readcount = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	readcount = getline(&buffer, &n, stdin);
	if (readcount == -1)
	{
	free(buffer);
	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "\n", 1);
	exit(0);
	}
	if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
		buffer[readcount - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
	{
		buffer[i] = '\0';
		break;
	}
	}
	return (buffer);
}
/**
 * fullypathedbuffer - finds the string to call execve
 * @av: pointer to array of user of strings
 * @PATH: pointer to PATH string
 * @copy: pointer to copy of PATH string
 *
 * Return: a pointer to string to call execve on
 */
char *fullypathedbuffer(char **av, char *PATH, char *copy)
{
	char *tok, *fullypathedbuffer = NULL, *concatsstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullypathedflag = 0, /*len = 0,*/ z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strdup(PATH);
	PATHcount = _splitPATH(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatsstr = _concat(tmp, av, tok);
		if (stat(concatsstr, &h) == 0)
	{
		fullypathedbuffer = concatsstr;
		fullypathedflag = 1;
		break;
	}
		if (z < PATHcount - 2)
		{
			toklen = _strlen(tok);
			if (tok[toklen + 1] == ':')
		{
			if (stat(av[0], &h) == 0)
		{
			fullypathedbuffer = av[0];
			fullypathedflag = 1;
			break;
		}
		}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullypathedflag == 0)
		fullypathedbuffer = av[0];
	free(copy);
	return (fullypathedbuffer);
}
/**
 * _checkbuiltin - check if first users string is a built-in
 * @av: pointer to array of user of strings
 * @buffer: pointer to user string
 * @exitstatus: exit status of execve
 * Return: 1 if user string is equal to env or 0 otherwise
 */
int _checkbuiltin(char **av, char *buffer, int exitstatus)
{
	int i;

	if (_strcmp(av[0], "envin") == 0)
	{
		envin();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		return (1);
	}
	else if (_strcmp(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
/**
 * forkedprocess - create child process to execute based on user input
 * @av: pointer to array of user of strings
 * @buffer: pointer to user string
 * @fullypathedbuffer: pointer to user input
 *
 * Return: 0 on success
 */
int forkedprocess(char **av, char *buffer, char *fullypathedbuffer)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
	perror("Error");
	exit(1);
	}
	if (pid == 0)
	{
		result = execve(fullypathedbuffer, av, environ);
		if (result == -1)
		{
			perror(av[0]);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	free(buffer);
	return (exitstatus);
}
