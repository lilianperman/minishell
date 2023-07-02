/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_to_sentence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:27:40 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:27:42 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: counting_args(t_token **lst_token)
 * Scope	: loops through the token list and counting every no tkn=PIPE
 *				to know the number of args to t_sentence
 *
 * Input	: t_token ** token list
 *
 * Output	: the numbers of args to t_sentence or 0 if none
 * Errors	: not applicable
 *
 * Uses		: tkn_to_sentence(t_token **lst_token)
 */
static size_t	counting_args(t_token **lst_token)
{
	size_t	count;
	t_token	*tmp;

	count = 0;
	tmp = *lst_token;
	if (!tmp)
		return (count);
	while (tmp && tmp->tkn && tmp->tkn != PIPE)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

/*
 * Fn		: tkn_to_sentence(t_token **lst_token)
 * Scope	: loop through list of tokens and create char **
 *				for list of sentences
 * Input	: t_token ** token list
 *
 * Output	: char ** for list of sentences
 * Errors	: not applicable
 *
 * Uses		: create_sentences(t_env *env, t_token **lst_token, \
 				t_sentence **lst_sentence)
 */
char	**tkn_to_sentence(t_token **lst_token)
{
	t_token	*tmp;
	size_t	size;
	char	**args;
	size_t	i;

	tmp = *lst_token;
	size = counting_args(&tmp);
	args = malloc(sizeof(char *) * (size + 1));
	if (!args)
		return (NULL);
	args[size] = NULL;
	i = 0;
	while (i < size)
	{
		args[i] = ft_strdup(tmp->word);
		i++;
		tmp = tmp->next;
	}
	return (args);
}
