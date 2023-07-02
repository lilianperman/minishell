/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_sentence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:20:04 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:20:05 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sentence_lenght(char *sentence, t_quotes quote);
static void	split_sentence(t_string **lst, t_repl *repl, t_env *env);
static void	stash_string(t_string **lst, char *sentence, int size);
static int	expvar(t_string **lst, char *var, t_env *env);

/*
 * Fn		: scan_sentence(char *sentence, t_env *env)
 * Scope	: splits a string into blocks, applying the expansions
 * Input	: char *sentence - string to be read and expanded
 *			: t_env * - list of environment variables
 * Output	: t_string * - list of strings, with the input string split
 * 				into blocks to be assembled later
 * Errors	: NULL - input string has no expansions to be done
 * Uses		: expand_sentence()
 */
t_string	*scan_sentence(char *sentence, t_env *env, int hdoc)
{
	t_string	*output;
	t_repl		repl;
	int			i;

	output = NULL;
	i = 0;
	while (sentence[i])
	{
		repl.new = NULL;
		repl.quote = which_quotes(sentence[i]);
		if (hdoc)
			repl.quote = NONE;
		repl.old = &sentence[i];
		if (hdoc)
			repl.old_sz = ft_strlen(sentence);
		else
			repl.old_sz = sentence_lenght(repl.old, repl.quote);
		split_sentence(&output, &repl, env);
		if (!output)
			return (NULL);
		i += repl.old_sz;
	}
	return (output);
}

/*
 * Fn		: sentence_lenght(char *sentence, t_quotes quote)
 * Scope	: determines the scope to be read increments until it finds a
 * 				quote or until the end of the string if in a quote context,
 * 				increments until it finds the closing quote
 * Input	: char *sentence - string to be read and expanded
 *			: t_quotes quote - quote type
 * Output	: scope size
 * Errors	: not applicable
 * Uses		: scan_sentence()
 */
static int	sentence_lenght(char *sentence, t_quotes quote)
{
	int	len;

	len = 0;
	if (!quote)
	{
		while (sentence[len] && which_quotes(sentence[len]) == NONE)
			len++;
		return (len);
	}
	else
	{
		len = 1;
		while (which_quotes(sentence[len]) != quote)
			len++;
		return (len + 1);
	}
}

/*
 * Fn		: split_sentence(t_string **lst, t_repl *repl, t_env *env)
 * Scope	: splits string into blocks when encounters $ if in context
 * 				of <"> or <no quotes>, expands variable
 * Uses		: scan_sentence()
 */
static void	split_sentence(t_string **lst, t_repl *repl, t_env *env)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = repl->old;
	i = 0;
	j = 0;
	while (tmp[j + i] && (j + i) < repl->old_sz)
	{
		if (tmp[j + i] == '$' && (repl->quote == DOUBLE || repl->quote == NONE))
		{
			if (j > 0)
				stash_string(lst, &tmp[i], j);
			j += (expvar(lst, &tmp[j + i], env));
			i += j;
			j = -1;
		}
		j++;
	}
	if ((!*lst && !tmp[j + i]) || !tmp[i])
		return ;
	repl->new = ft_substr(&tmp[i], 0, j);
	if (repl->new && *repl->new)
		ft_stradd_back(lst, ft_strnew(repl->new, j));
}

/*
 * Fn		: stash_string(t_string **lst, char *sentence, int size)
 * Scope	: stores the string up to the character before $
 * Uses		: split_sentence()
 */
static void	stash_string(t_string **lst, char *sentence, int size)
{
	char	*to_stash;

	to_stash = ft_substr(sentence, 0, size);
	if (to_stash && *to_stash)
		ft_stradd_back(lst, ft_strnew(to_stash, size));
}

/*
 * Fn		: expvar(t_string **lst, char *var, t_env *env)
 * Scope	: expand the variable
 * Uses		: split_sentence()
 */
static int	expvar(t_string **lst, char *var, t_env *env)
{
	int		i;
	char	*value;
	int		len;

	i = 1;
	if (var[i] && iscrule(var[i], 1))
		i++;
	if (i == 1)
	{
		ft_stradd_back(lst, ft_strnew(ft_substr(var, 0, i), i));
		return (i);
	}
	while (var[i] && iscrule(var[i], 0))
		i++;
	if (var[1] == '?')
		value = get_global(&var[1], i - 2);
	else
		value = get_value(&var[1], i - 1, env);
	len = 0;
	if (value)
		len = ft_strlen(value);
	ft_stradd_back(lst, ft_strnew(value, len));
	return (i);
}
