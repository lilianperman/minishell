/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:25:59 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:26:01 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isquoted(char *str)
{
	while (*str)
	{
		if (isquotes(*str))
			return (1);
		str++;
	}
	return (0);
}

static void	hdoc_routine(char *file, int expand, int fd, t_env *env)
{
	char			*line_read;
	const int		size = ft_strlen(file) + 1;

	line_read = NULL;
	g_global = 0;
	while (1)
	{
		line_read = readline("> ");
		if (g_global == 130)
		{
			if (line_read)
				free(line_read);
			return ;
		}
		if (!line_read || ft_strncmp(line_read, file, size) == 0)
		{
			free(line_read);
			break ;
		}
		if (expand)
			expand_hdoc_var(&line_read, env);
		ft_putendl_fd(line_read, fd);
		free(line_read);
	}
	return ;
}

int	heredoc(t_sentence *cmd, char *file, t_env *env)
{
	int		expand;
	int		pipe_fd[2];
	char	*cpy_file;

	cpy_file = ft_strdup(file);
	expand = !isquoted(cpy_file);
	if (!expand)
		cpy_file = ft_strdup((remove_hdoc_quotes(cpy_file)));
	if (pipe(pipe_fd) == -1)
	{
		error_redir(cpy_file);
		return (-1);
	}
	hdoc_routine(cpy_file, expand, pipe_fd[1], env);
	cmd->fd_i = pipe_fd[0];
	close (pipe_fd[1]);
	free(cpy_file);
	return (pipe_fd[0]);
}
