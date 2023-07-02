/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtotallen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:16:42 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:16:46 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

size_t	ft_strtotallen(t_string *lst)
{
	size_t	total_len;

	total_len = 0;
	while (lst)
	{
		total_len += lst->length;
		lst = lst->next;
	}
	return (total_len);
}
