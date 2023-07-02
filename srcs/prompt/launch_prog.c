/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:57:49 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 18:57:52 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	trim_line(t_shell *data);

/*
 * Fn		: launch_prog(t_shell *data)
 * Scope	: Run the REPL loop
 * Input	: t_shell * - pointer to the global struct
 * Output	: void
 * Errors	: not applicable
 * Uses		: main() [main.c]
 */
void	launch_prog(t_shell *data)
{
	trim_line(data);
	if (scan_line(&data->lst_token, data->line) == 0
		&& lexer(data->lst_token) == 0)
	{
		create_sentences(data->lst_env, &data->lst_token, &data->lst_sentence);
		fill_shell (data);
		if (data->pipe_count > 0 || data->redirect_count > 0)
		{
			open_pipe_reds(data);
			clean_reds_sentences(data->lst_sentence);
		}
		executor(data);
	}
	free_shell(data);
}

static void	trim_line(t_shell *data)
{
	char	*tmp;

	tmp = data->line;
	if (!tmp)
		return ;
	data->line = ft_strtrim(tmp, " ");
	free(tmp);
}
