#include "main.h"

/**
 * read_error - error reading
 *
 * @dirp: ...
 * @fd: ...
 * @str: ...
 * Return: void
 */
void read_error(int fd, DIR *dirp, char *str)
{
	perror(str);
	close(fd);
	closedir(dirp);
	exit(EXIT_FAILURE);
}

/**
 * cd_process - this is used in the _cd() function
 *
 * @absolute_path: ...
 * @cwd: ...
 * @dirp: ...
 * @dir_name: ...
 * @filestat: ...
 * Return: void
 */

void cd_process(char *absolute_path, char *cwd,
DIR *dirp, char *dir_name, struct stat filestat)
{
	int fd;

	_strcpy(absolute_path, cwd);
	_strcat(absolute_path, "/");
	_strcat(absolute_path, dir_name);
	fd = open(absolute_path, O_DIRECTORY);
	if (fd < 0)
	{
		perror("Error opening directory");
		exit(EXIT_FAILURE);
	}
	if (fstat(fd, &filestat) < 0)
	{
		read_error(fd, dirp, "Error getting file status");
	}
	if ((filestat.st_mode & S_IFMT) == S_IFDIR)
	{
		if (chdir(absolute_path) < 0)
		{
			read_error(fd, dirp, "Error changing directory");
		}
		_setenv("OLDPWD", cwd);
		_setenv("PWD", absolute_path);
		close(fd);
		closedir(dirp);
		return;
	}
	else
	{
		perror("Not a directory");
		exit(EXIT_FAILURE);
	}
}


