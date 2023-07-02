/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:15:14 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:15:16 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_string	*ft_strnew(char *str, size_t length)
{
	t_string	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = str;
	new->length = length;
	new->last = new;
	new->next = NULL;
	return (new);
}
