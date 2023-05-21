#include "main.h"

/**
 * _cd - name of the function
 *
 *  @args: parameter 1
 *   Return: the function
 */

void _cd(char *args[])
{
	char *dir_name = args[1], cwd[1024], absolute_path[1024], *old_pwd = NULL;
	DIR *dirp = opendir(".");
	struct dirent *dp;
	struct stat filestat;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		exit(EXIT_FAILURE);
	}
	if (dir_name && (*dir_name == '-'))
	{
		if((*(dir_name + 1) == '-' && *(dir_name + 2) == '\0')
		|| *(dir_name + 1) == '\0') 
			cd_dash(old_pwd, cwd);
		else
		{
			free(old_pwd);
			perror("Not a valid directory");
		}
		return;
	}
	if (dir_name == NULL)
	{
		dir_name = get_env("HOME") ? get_env("HOME") : "/tmp";
		if (chdir(dir_name) >= 0)
		{
			_setenv("OLDPWD", cwd);
			_setenv("PWD", dir_name);
			return;
		}
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		if (_strcmp(dp->d_name, dir_name) == 0)
		{
			cd_process(absolute_path, cwd, dirp, dir_name, filestat);
			return;
		}
	}
	perror("Directory not found");
	closedir(dirp);
	exit(EXIT_FAILURE);
}

