/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:09:48 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:09:50 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:char *str - environment variable in wrong format
 *					:char *key - string that was split (environment variable key
 * Scope			:checks that the key is in the correct format
 * Output			:-1 error
 *					: 1 sucess
 */
int	check_export(char *key, char *str)
{
	int	i;
	int	code;

	i = -1;
	code = SUCESS_BUILTINS;
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
		{
			export_error(str);
			code = ERROR_BUILTINS;
		}
	}
	return (code);
}
