/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:10:01 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:10:04 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:char *str - environment variable in wrong format
 * Output			:print the error on the screen
 */
static void	unset_error(char *str)
{
	ft_putstr_fd("minishell: unset: ", STDERR_FILENO);
	ft_putstr_fd("`", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
}

/*
 * Input			:char *key - environment variable key
 * Scope			:checks that the key is in the correct format
 * Output			:-1 error
 *					: 1 sucess
 */
int	check_unset(char *key)
{
	int	i;
	int	code;

	i = -1;
	code = SUCESS_BUILTINS;
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
		{
			unset_error(key);
			code = ERROR_BUILTINS;
		}
	}
	return (code);
}
