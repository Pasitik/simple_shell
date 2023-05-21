#include "main.h"

/**
 * cd_dash - name of the function
 *
 * @old_pwd: parameter 1
 * @cwd: parameter 2
 * Return: the function
 */

void cd_dash(char *old_pwd, char *cwd)
{
	old_pwd = get_env("OLDPWD");

	if (old_pwd == NULL)
	{
		_setenv("OLDPWD", cwd);
		return;
	}
	if (chdir(old_pwd) < 0)
	{
		return;
	}

	_puts(old_pwd);
	_puts("\n");
	_setenv("OLDPWD", cwd);

}

