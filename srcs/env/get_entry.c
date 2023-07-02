/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:19:11 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:19:14 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_entry(char **key, char **value, char *var, int len)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	*key = ft_substr(var, 0, i);
	if (var[i])
		i++;
	*value = ft_substr(var, i, len - i);
	if (*value && !**value)
	{
		free(*value);
		*value = NULL;
	}
}
