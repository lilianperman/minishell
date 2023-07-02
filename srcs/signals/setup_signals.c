/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:28:35 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:28:37 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: setup_signals(void)
 * Scope	: setup the signals for interactive mode
 *			: SIGINT (Ctrl + C) is set to int_handler function
 *			: SIGQUIT (Ctrl + \) is set to be ignored
 * Input	: void
 * Output	: void
 * Errors	: not applicable
 * Uses		: main() [main.c]
 */
void	setup_signals(void)
{
	struct sigaction	int_action;
	struct sigaction	quit_action;

	sigemptyset(&int_action.sa_mask);
	sigemptyset(&quit_action.sa_mask);
	int_action.sa_handler = &int_handler;
	int_action.sa_flags = SA_RESTART;
	quit_action.sa_handler = SIG_IGN;
	quit_action.sa_flags = SA_RESTART;
	sigaction(SIGINT, &int_action, NULL);
	sigaction(SIGQUIT, &quit_action, NULL);
}
