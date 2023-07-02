/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:20:47 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:20:53 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_quotes	which_quotes(char c)
{
	if (c == '\'')
		return (SINGLE);
	if (c == '\"')
		return (DOUBLE);
	return (NONE);
}
