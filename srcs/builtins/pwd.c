/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:12:13 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:12:15 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int fd)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putendl_fd(path, fd);
	free(path);
	path = NULL;
	return (0);
}
