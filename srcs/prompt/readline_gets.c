/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_gets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:59:27 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 18:59:30 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: readline_gets(char *line)
 * Scope	: get the output from readline() into buffer *line
 *			: if *line is not NULL, free it
 * Input	: char * - buffer
 * Output	: char * - return from readline
 * Errors	: not applicable
 * Uses		: main() [main.c]
 */
char	*readline_gets(char *line)
{
	if (line)
		free(line);
	line = NULL;
	line = readline("minishell > ");
	return (line);
}
