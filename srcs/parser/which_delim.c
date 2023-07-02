/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:24:18 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:24:20 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn	which_delim(char *delim)
{
	char	c;

	c = *delim;
	if (!isdelim(c))
		return (ERROR);
	if (c == '|')
		return (PIPE);
	if (c == '>')
	{
		if (*(delim + 1) == c)
			return (APPEND);
		return (OUT);
	}
	if (c == '<')
	{
		if (*(delim + 1) == c)
			return (HDOC);
		return (IN);
	}
	return (ERROR);
}
