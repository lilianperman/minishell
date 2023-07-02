/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:56:26 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 18:56:36 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_executor_error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	g_global = 127;
}

void	exec_sentence(t_sentence *sentence, t_shell *data)
{
	default_signals();
	if (sentence->fd_i != 0)
		dup2(sentence->fd_i, 0);
	if (sentence->fd_o != 1)
		dup2(sentence->fd_o, 1);
	close_fds(data);
	exec_command(sentence->args[0], sentence->args, data);
}

void	wait_sentences(t_shell *data)
{
	t_sentence	*tmp;
	int			status;

	tmp = data->lst_sentence;
	status = 0;
	while (tmp)
	{
		if (tmp->args[0])
		{
			g_global = 0;
			waitpid(tmp->pid, &status, 0);
			if (WIFSIGNALED(status))
			{
				g_global = 128 + WTERMSIG(status);
				if (g_global == 131)
					ft_putendl_fd("Quit (core dumped)", 2);
			}
			else if (WIFEXITED(status))
				g_global = WEXITSTATUS(status);
		}
		tmp = tmp->next;
	}
}

void	exec_one(t_sentence *tmp, t_shell *data, t_builtin builtin)
{
	if (tmp->fd_i == -1 || tmp->fd_o == -1)
		return ;
	if (builtin)
		call_builtin(tmp->args, data, builtin);
	close_fds(data);
}

void	executor(t_shell *data)
{
	t_sentence	*tmp;
	t_builtin	builtin;

	tmp = data->lst_sentence;
	builtin = isbuiltin(tmp->args[0]);
	if (data->sentence_count == 1 && builtin > ENV)
		exec_one(tmp, data, builtin);
	else
	{
		while (tmp)
		{
			if (tmp->fd_i != -1 && tmp->fd_o != -1 && tmp->args[0])
			{
				tmp->pid = fork();
				if (tmp->pid == -1)
					print_executor_error(strerror(errno));
				if (tmp->pid == 0)
					exec_sentence(tmp, data);
			}
			tmp = tmp->next;
		}
		close_fds(data);
		wait_sentences(data);
	}
	setup_signals();
}
