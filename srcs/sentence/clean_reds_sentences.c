/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_reds_sentences.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:26:24 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:26:26 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	arr_size(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

static int	arr_size_noreds(char **array)
{
	int	size;
	int	i;

	size = arr_size(array);
	i = 0;
	while (array[i])
	{
		if (which_delim(array[i]) > PIPE)
			size -= 2;
		i++;
	}
	return (size);
}

static char	**clean_arr(char **array)
{
	int		new_size;
	char	**clean_args;
	int		i;

	new_size = arr_size_noreds(array);
	clean_args = malloc (sizeof(char *) * (new_size + 1));
	if (!clean_args)
		return (NULL);
	i = 0;
	new_size = 0;
	while (array[i])
	{
		while (array[i] && which_delim(array[i]) > PIPE)
			i += 2;
		if (array[i])
		{
			clean_args[new_size] = ft_strdup(array[i]);
			new_size++;
			i++;
		}
	}
	clean_args[new_size] = NULL;
	return (clean_args);
}

/*
 * Fn		: clean_reds_sentences(t_shell *data)
 * Scope	: loops through the list of sentences and if sentences
 *				has redirect remove it and its file name
 * Input	: t_shell *data
 * Output	: void
 * Errors	: not applicable
 * Uses		: launch_prog() [launch_prog.c]
 */
void	clean_reds_sentences(t_sentence *lst_sentence)
{
	t_sentence	*tmp_sentencelst;
	char		**tmp;

	tmp_sentencelst = lst_sentence;
	if (!lst_sentence)
		return ;
	while (lst_sentence)
	{
		if (lst_sentence->reds_inside > 0)
		{
			tmp = lst_sentence->args;
			lst_sentence->args = clean_arr(lst_sentence->args);
			free_array(tmp);
		}
		lst_sentence = lst_sentence->next;
	}
	lst_sentence = tmp_sentencelst;
}
