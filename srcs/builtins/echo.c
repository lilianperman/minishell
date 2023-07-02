/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:10:31 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:10:33 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_n(char *str)
{
	int	i;

	i = 2;
	while (str[i] == 'n' && str[i])
		i++;
	if (str[i] != 'n' && str[i])
		return (0);
	return (1);
}

int	echo(char **arg, int fd)
{
	int	control;
	int	i;

	i = 1;
	control = 0;
	if (arg[i] && (ft_strncmp(arg[i], "-n", 2) == 0))
		control = check_n(arg[i]);
	if (control)
		i++;
	while (arg[i])
	{
		ft_putstr_fd(arg[i], fd);
		if (arg[i] && arg[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (arg[i - 1] == NULL || control == 0)
		ft_putstr_fd("\n", fd);
	return (0);
}
