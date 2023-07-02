/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:22:46 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:22:48 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: prefix_slash(char **str)
 * Scope	: add '/' to string
 * Input	: char ** - adrres of string
 * Output	: char * - the string
 * Errors	: NULL - string is NULL, or malloc error
 * Uses		: test_command (call_execve.c)
 */
char	*prefix_slash(char **str)
{
	char			*output;
	const size_t	len = ft_strlen(*str);

	if (!*str)
		return (NULL);
	output = malloc((len + 2) * sizeof(*output));
	if (!output)
		return (NULL);
	*output = '/';
	ft_memcpy(&output[1], *str, len + 1);
	free(*str);
	*str = NULL;
	*str = output;
	return (output);
}
