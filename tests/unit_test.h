/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:52:54 by bda-silv          #+#    #+#             */
/*   Updated: 2023/05/19 09:53:00 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include "minishell.h"
# include <unistd.h>
# include <stdio.h>

void	prt(int i, char *s);

void	prt(int i, char *s)
{
	while (*s)
		write(i, &*s++, 1);
	write(i, "\n", 1);
}

#endif
