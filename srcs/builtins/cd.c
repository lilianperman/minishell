/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:09:35 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:09:37 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_oldpwd(char *old, t_shell *data)
{
	t_env	*oldpwd;

	oldpwd = compare_key(data->lst_env, "OLDPWD");
	if (!oldpwd)
	{
		data->lst_env = addfront_env(data->lst_env, ft_strdup("OLDPWD"), old);
		return ;
	}
	free(oldpwd->value);
	oldpwd->value = NULL;
	oldpwd->value = old;
}

static void	set_pwd(t_shell *data)
{
	t_env	*pwd;
	char	*path;

	pwd = compare_key(data->lst_env, "PWD");
	if (!pwd)
	{
		path = getcwd(NULL, 0);
		data->lst_env = addfront_env(data->lst_env, ft_strdup("PWD"), path);
		return ;
	}
	free(pwd->value);
	pwd->value = NULL;
	pwd->value = getcwd(NULL, 0);
}

static char	*get_home(t_shell *data)
{
	t_env	*home;

	home = compare_key(data->lst_env, "HOME");
	if (!home)
		return (NULL);
	return (home->value);
}

static int	change_dir(char *path, t_shell *data)
{
	if (!path)
	{
		path = get_home(data);
		if (!path)
		{
			ft_putendl_fd("minishell: cd: HOME not set", 2);
			return (1);
		}
		chdir(path);
		return (0);
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		g_global = 1;
		return (1);
	}
	return (0);
}

int	cd(int argc, char **argv, t_shell *data)
{
	char	*cwd;

	if (argc > 2)
	{
		ft_putendl_fd("minishell: cd: too many arguments", 2);
		g_global = 1;
		return (1);
	}
	cwd = getcwd(NULL, 0);
	if (change_dir(argv[1], data))
	{
		free(cwd);
		return (1);
	}
	set_oldpwd(cwd, data);
	set_pwd(data);
	return (0);
}
