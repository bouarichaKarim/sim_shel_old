#include "shell.h"

/**
 * my_exit - it exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant the function prototype.
 * @exit_arg: exit argument.
 * Return: it exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int my_exit(int exit_arg, info_t *info)
{
    int echeck;

    if (exit_arg != 0) /* If there is an exit argument */
    {
        echeck = _erratoi(exit_arg);
        if (echeck == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(exit_arg);
            _eputchar('\n');
            return 1;
        }
        info->err_num = _erratoi(exit_arg);
        return -2;
    }
    info->err_num = -1;
    return -2;
}

/**
 * _mycd - it changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always return 0
 */
int _mycd(info_t *info)
{
	char *s, *d, buf[1024];
	int chd_r;

	s = getcwd(buf, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		d = get_env(info, "HOME=");
		if (!d)
			chd_r = /* TODO: what should this be? */
				chdir((d = get_env(info, "PWD=")) ? d : "/");
		else
			chd_r = chdir(d);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!get_env(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(get_env(info, "OLDPWD=")), _putchar('\n');
		chd_r = /* TODO: what should this be? */
			chdir((d = get_env(info, "OLDPWD=")) ? d : "/");
	}
	else
		chd_r = chdir(info->argv[1]);
	if (chd_r == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", get_env(info, "PWD="));
		_setenv(info, "PWD", getcwd(buf, 1024));
	}
	return (0);
}

/**
 * my_help - functon for help
 * @info: Structure containing potential arguments. Used to maintain
 * constant the function prototype.
 * Return: Always return 0
 */
int my_help(info_t *info)
{
	char **arg_ar;

	arg_ar =(const char **)info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_ar); /* temp att_unused workaround */
	return (0);
}
