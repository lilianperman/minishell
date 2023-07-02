/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izsoares <izsoares@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:42:06 by izsoares          #+#    #+#             */
/*   Updated: 2023/05/14 20:42:09 by izsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H
# include "minishell.h"

typedef enum e_test
{
	UNDEFINED,
	TOKEN,
}	t_test;

void	print_data(void *ptr, t_test t);

#endif
