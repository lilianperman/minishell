/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:14:08 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:14:10 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_strclear(t_string **lst, void (*del)(void *))
{
	t_string	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_strdelone(tmp, del);
	}
	*lst = NULL;
}
