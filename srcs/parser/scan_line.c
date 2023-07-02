/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:24:07 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:24:10 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	token_length(char *token);
static int	token_length_quotes(char *token, char quote);

static int	add_token(t_token **lst, char *str, int length)
{
	char	*value;
	t_tkn	token;

	if (length < 0)
		return (length);
	if (!length)
		return (-1);
	value = malloc((length + 1) * sizeof(*value));
	if (!value)
		return (-1);
	ft_memcpy(value, str, length);
	value[length] = '\0';
	token = WORD;
	if (isdelim(*value))
		token = which_delim(value);
	addback_token(lst, new_token(value, token));
	return (length);
}

// Return length of pipe or redirects (2 for << or >>, else 1)
static int	delim_length(char *delim, char d)
{
	if (d == '|')
		return (1);
	if (*(delim + 1) == d)
		return (2);
	return (1);
}

// Return length of section within quotes
static int	token_length_quotes(char *token, char quote)
{
	int	len;
	int	error;

	len = 1;
	while (token[len] && token[len] != quote)
		len++;
	if (!token[len])
		return (-2);
	if (!ft_isspace(token[len + 1]) || !isdelim(token[len + 1]))
	{
		error = token_length(&token[len + 1]);
		if (error < 0)
			return (error);
		len += error;
	}
	return (len + 1);
}

// Return length of section outside quotes
static int	token_length(char *token)
{
	int	len;
	int	error;

	if (isdelim(*token))
		return (delim_length(token, *token));
	len = 0;
	while (token[len] && !ft_isspace(token[len]))
	{
		if (isquotes(token[len]))
		{
			error = token_length_quotes(&token[len], token[len]);
			if (error < 0)
				return (error);
			len += error;
		}
		else
			len++;
		if (isdelim(token[len]))
			break ;
	}
	return (len);
}

/*
 * Fn		: scan_line(t_token **lst, char * line)
 * Scope	: scan command line and apply tokens in t_tkn;
 * Input	: t_token **lst - address for token list
 *			: char * - command line (return of readline function)
 * Output	: int (0) - no error found
 * Errors	: int (-1) - fail to alloc space for t_token *
 *			: int (-2) - syntax error (no closing quotes found)
 * Uses		: launch_prog()
 */
int	scan_line(t_token **lst, char *line)
{
	char	*start;
	int		i;

	start = line;
	while (*start)
	{
		while (*start && ft_isspace(*start))
			start++;
		if (isquotes(*start))
			i = token_length_quotes(start, *start);
		else
			i = token_length(start);
		i = add_token(lst, start, i);
		if (i >= 0 && !*lst)
			i = -1;
		if (i < 0)
			return (i);
		start += i;
	}
	return (0);
}
