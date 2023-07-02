/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:28:13 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:28:15 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	default_signals(void)
{
	struct sigaction	dfl_int;
	struct sigaction	dfl_quit;

	sigemptyset(&dfl_int.sa_mask);
	sigemptyset(&dfl_quit.sa_mask);
	dfl_int.sa_flags = SA_RESTART;
	dfl_int.sa_handler = SIG_DFL;
	dfl_quit.sa_flags = SA_RESTART;
	dfl_quit.sa_handler = SIG_DFL;
	sigaction(SIGINT, &dfl_int, NULL);
	sigaction(SIGQUIT, &dfl_quit, NULL);
}
