/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:22:07 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:22:10 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_comm(char **comm, t_string *path_lst);
static int	ispath(char *s);
static int	test_command(char **comm, t_string *path_lst);
static int	test_access(char *pathname);

/*
 * Fn		: call_execve(char **argsm char *path)
 * Scope	: turns args[0] into absolute if it is an exexutable command
 *				and executes execve
 * Input	: char ** - sentence args
 *			: char * - env path value
 * Output	: void
 * Errors	: n.a.
 * Uses		: exec_command()
 */
int	call_execve(char **args, char *path, char **envs)
{
	t_string	*p;
	char		*aux;

	aux = ft_strdup(*args);
	p = path_to_lst(path);
	if (!get_comm(&args[0], p))
	{
		print_execve_error(aux, errno);
		ft_strclear(&p, free);
		free(aux);
		return (-1);
	}
	swap_ptr(&aux, &args[0]);
	if ((execve(aux, args, envs)) == -1)
	{
		print_executor_error(args[0]);
		free(aux);
		return (-1);
	}
	free(aux);
	return (0);
}

static int	get_comm(char **comm, t_string *path_lst)
{
	if (ispath(*comm))
	{
		if (test_access(*comm))
			return (1);
	}
	else
	{
		if (test_command(comm, path_lst))
			return (1);
	}
	return (0);
}

static int	ispath(char *s)
{
	while (*s)
	{
		if (*s == '/')
			return (1);
		s++;
	}
	return (0);
}

static int	test_command(char **comm, t_string *path_lst)
{
	char	*path;
	char	*aux;

	if (!*comm[0])
		return (0);
	aux = ft_strdup(*comm);
	prefix_slash(&aux);
	while (path_lst)
	{
		path = ft_strjoin(path_lst->content, aux);
		if (test_access(path))
		{
			free(aux);
			free(*comm);
			*comm = NULL;
			*comm = path;
			return (1);
		}
		free(path);
		path = NULL;
		path_lst = path_lst->next;
	}
	free(aux);
	return (0);
}

static int	test_access(char *pathname)
{
	if (!access(pathname, F_OK | X_OK))
		return (1);
	return (0);
}
