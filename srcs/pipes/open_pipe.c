/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:25:14 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:25:16 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_pipe(void)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	g_global = errno;
}

/*
 * Fn		: open_pipe(t_sentence *actual, t_sentence *next)
 * Scope	: call function pipe(), and update sentence fd_i and fd_o
 *				when its necessary
 * Input	: currenty node sentence and the next one
 * Output	: the array of fds
 * Errors	: -1 if the fds weren't created
 * Uses		: open_pipe_reds()
 */
int	*open_pipe(t_sentence *actual, t_sentence *next)
{
	int	*pipe_fd;

	pipe_fd = malloc (sizeof(int) * 2);
	if (!pipe_fd)
		return (NULL);
	if (pipe(pipe_fd) == -1)
	{
		free(pipe_fd);
		error_pipe();
		return (NULL);
	}
	if (next && next->fd_i == 0)
		next->fd_i = pipe_fd[0];
	if (actual->fd_o == 1 && next != NULL)
		actual->fd_o = pipe_fd[1];
	return (pipe_fd);
}
