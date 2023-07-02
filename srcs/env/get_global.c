/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:19:41 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:19:43 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_global(char *var, int size)
{
	char	*value;
	char	*rest;

	value = ft_itoa(g_global);
	if (size == 0)
		return (value);
	else
	{
		rest = ft_substr(var, 1, size);
		value = ft_strjoin_free(value, rest);
		free(rest);
		return (value);
	}
}
