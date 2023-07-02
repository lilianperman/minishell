/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:17:00 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:17:03 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:void *arg - argument can be of any type
 * Scope			:checks whether dynamic memory allocation has occurred
 * Output			:none
 * 					:or
 * 					:error and exit
 */
void	protect_malloc(void *arg)
{
	if (arg == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(errno);
	}
}
