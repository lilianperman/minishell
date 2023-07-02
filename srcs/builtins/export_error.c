/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:11:36 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:11:38 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:char *str - environment variable in wrong format
 * Output			:print the error on the screen
 */
void	export_error(char *str)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putstr_fd("'", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	g_global = 1;
}
