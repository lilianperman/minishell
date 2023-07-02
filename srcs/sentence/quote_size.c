/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:27:07 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:27:09 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: quote_size(char *str, char quote)
 * Scope	: counts bytes that are between quotes

 * Input	: the string that is being scanned and the quote type
 * Output	: the number of bytes that are between quotes
 * Errors	: not applicable
 *
 * Uses		: new_index()
 */
int	quote_size(char *str, char quote)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != quote)
		i++;
	return (i);
}
