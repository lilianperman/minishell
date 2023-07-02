/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_builtin_cd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatavel <dmatavel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:21:41 by dmatavel          #+#    #+#             */
/*   Updated: 2023/06/18 13:06:08 by daolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_global = 0;

static char **check(int argc, char **argv, t_shell *data)
{
	t_env	*oldpwd;
	t_env	*pwd;

	oldpwd = compare_key(data->lst_env, "OLDPWD");
	pwd = compare_key(data->lst_env, "PWD");
	printf("cd args: ");
	for (int i = 0; i < argc; i++)
		printf("%s ", argv[i]);
	printf("\n");
	printf("OLDPWD: %s\nPWD: %s\n\n", oldpwd->value, pwd->value);
	freetab((void **)argv);
	return (NULL);
}

static char	**create_argv(int n)
{
	switch (n)
	{
		case 1:
			return (ft_split("cd 42", ' '));
		case 2:
			return (ft_split("cd exclude_test logs", ' '));
		case 3:
			return (ft_split("cd exclude_test", ' '));
		default:
			return (ft_split("cd", ' '));
	}
}

static int	test_cd(t_shell *data)
{
	char	**argv;
	int		ret;

	argv = create_argv(1);
	ret = cd(2, argv, data);
	argv = check(2, argv, data);
	if (ret != 1)
		return (1);
	argv = create_argv(2);
	ret = cd(3, argv, data);
	argv = check(3, argv, data);
	if (ret != 1)
		return (1);
	argv = create_argv(3);
	ret = cd(2, argv, data);
	argv = check(2, argv, data);
	if (ret != 0)
		return (1);
	argv = create_argv(4);
	ret = cd(1, argv, data);
	argv = check(1, argv, data);
	if (ret != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	data;
	(void)(av);
	(void)(ac);

	init_shell(&data);
	data.lst_env = get_env(envp);
	if (test_cd(&data) == 1)
		return (1);
	clear_env(&data.lst_env);
	return (0);
}
