/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:13:51 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:13:53 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_stradd_front(t_string **lst, t_string *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		new->last = (*lst)->last;
		new->next = *lst;
		*lst = new;
	}
}
