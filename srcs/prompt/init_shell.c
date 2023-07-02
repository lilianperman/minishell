/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:57:33 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 18:57:38 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *data)
{
	data->line = NULL;
	data->lst_token = NULL;
	data->lst_sentence = NULL;
	data->sentence_count = 0;
	data->pipe_count = 0;
	data->redirect_count = 0;
	data->pipes = NULL;
	data->reds = NULL;
}
