/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_execve_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:23:00 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:23:02 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_execve_error(char *str, int error)
{
	if (error == EACCES)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		g_global = 126;
	}
	else
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": command not found", 2);
		g_global = 127;
	}
}
