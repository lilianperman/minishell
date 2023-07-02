/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_quote_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:26:55 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:26:57 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: no_quote_size(char *str)
 * Scope	: counts bytes that aren't quotes

 * Input	: the string that is being scanned
 * Output	: the number of bytes that aren't quotes
 * Errors	: not applicable
 *
 * Uses		: rem_str_quotes() and while_no_quotes()
 */
int	no_quote_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\'' && str[i] != '\"')
		i++;
	return (i);
}
