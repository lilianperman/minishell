/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sentences.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:26:34 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:26:35 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: count_sentence_reds(t_token **lst_token)
 * Scope	: loops through the list of tokens and returns the number os
				redirects until the next pipe or end of lst_token
 *
 * Input	: t_token **lst_token
 *
 * Output	: number of redirects of a sentence
 * Errors	: not applicable
 *
 * Uses		: create_sentences()
 */
static size_t	count_sentence_reds(t_token **lst_token)
{
	size_t	count;
	t_token	*tmp;

	count = 0;
	tmp = *lst_token;
	if (!tmp)
		return (count);
	while (tmp && tmp->tkn >= WORD)
	{
		if (tmp->tkn == PIPE)
			break ;
		if (tmp->tkn > PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

/*
 * Fn		: get_next_sentence(t_token **lst_token)
 * Scope	: loops through the list of tokens and returns the node for
				create next sentence node or null
 *
 * Input	: t_token **lst_token
 *
 * Output	: node of lst_token to create next sentence or null
 * Errors	: not applicable
 *
 * Uses		: create_sentences()
 */
static t_token	*get_next_sentence(t_token **lst_token)
{
	if (!(*lst_token))
		return (NULL);
	while ((*lst_token) && (*lst_token)->tkn >= WORD)
	{
		if ((*lst_token)->tkn == PIPE)
		{
			*lst_token = (*lst_token)->next;
			break ;
		}
		*lst_token = (*lst_token)->next;
	}
	return (*lst_token);
}

/*
 * Fn		: create_sentences(t_env *env, t_token **lst_token,
 *				 t_sentence **lst_sentence)
 * Scope	: loops through the list of tokens to create the list
 *				of sentences with the variables already expanded
 *				and without quotes
 *
 * Input	: t_env *env, t_token **lst_token, t_sentence **lst_sentence
 *
 * Output	: void
 * Errors	: not applicable
 *
 * Uses		: launch_prog();
 */
void	create_sentences(t_env *env, t_token **lst_token, \
			t_sentence **lst_sentence)
{
	char		**args;
	t_token		*tmp_tkn;
	t_sentence	*tmp_sen;

	tmp_tkn = *lst_token;
	while (tmp_tkn)
	{
		args = NULL;
		args = tkn_to_sentence(&tmp_tkn);
		expandvars(args, env);
		remove_quotes(args);
		tmp_sen = NULL;
		tmp_sen = new_sentence(args);
		tmp_sen->reds_inside = count_sentence_reds(&tmp_tkn);
		addback_sentence(&(*lst_sentence), tmp_sen);
		tmp_tkn = get_next_sentence(&tmp_tkn);
	}
}
