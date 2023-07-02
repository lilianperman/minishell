/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:24:48 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:24:50 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_pipe(t_shell *data)
{
	int	i;

	i = 0;
	while (i < data->pipe_count)
	{
		free(data->pipes[i]);
		i++;
	}
	free(data->pipes);
}
