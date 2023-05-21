#include "main.h"

/**
 * new_process - births a child process and handles execution
 *
 * @args: array of params
 * @str_path: path to command
 * @envp: enviromentals
 * Return: void
 */

void new_process(char **args, char *str_path, char *envp[])
{
	pid_t process_id;
	int status;
	char *cmd_path = NULL;

	if (isBuiltIn(args))
	{
		exec_builtIns(args, str_path, envp);
		return;
	}

	process_id = fork();

	if (process_id == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (process_id == 0)
	{
		cmd_path = cmd_location(args[0], str_path);
		execve(cmd_path, args, NULL);

		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(process_id, &status, 0);
	}
}
