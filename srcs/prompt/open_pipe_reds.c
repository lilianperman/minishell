/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipe_reds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:58:51 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 18:58:53 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: set_reds_array(t_sentence *s, int **reds, int *index)
 * Scope	: if sentence has redirect calls open_reds() and set the reds array
 * Input	: a sentence node, a pointer to reds array and the array index;
 * Output	: void
 * Errors	: not applicable
 * Uses		: open_pipes_reds()
 */
static void	set_reds_array(t_sentence *s, int *reds, int *index, t_env *env)
{
	t_tkn	t;
	int		i;

	i = 0;
	while (s->args[i])
	{
		t = which_delim(s->args[i]);
		if (t > PIPE)
		{
			i++;
			reds[*index] = open_reds(t, s, s->args[i], env);
			(*index)++;
		}
		i++;
	}
}

/*
 * Fn		: open_pipe_reds(t_shell *data)
 * Scope	: traverse the sentences and call the functions open_reds and
 *				open_pipes filling their respective arrays in the t_shell
 * Input	: t_shell * - pointer to the global struct
 * Output	: int to show error
 * Errors	: -1 if there aren't any sentence
 * Uses		: launch_prog()
 */
int	open_pipe_reds(t_shell *data)
{
	t_sentence	*tmp_sentence;
	int			i_reds;
	int			i_pipes;

	tmp_sentence = data->lst_sentence;
	i_reds = 0;
	i_pipes = 0;
	if (!tmp_sentence)
		return (-1);
	while (tmp_sentence && data->redirect_count > 0)
	{
		if (tmp_sentence->reds_inside > 0)
			set_reds_array(tmp_sentence, data->reds, &i_reds, data->lst_env);
		tmp_sentence = tmp_sentence->next;
	}
	tmp_sentence = data->lst_sentence;
	while (tmp_sentence && tmp_sentence->next && data->pipe_count > 0)
	{
		data->pipes[i_pipes++] = open_pipe(tmp_sentence, tmp_sentence->next);
		tmp_sentence = tmp_sentence->next;
	}
	return (0);
}
