/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:15:30 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:15:32 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_strsetlast(t_string *lst, t_string *laststr)
{
	while (lst)
	{
		lst->last = laststr;
		lst = lst->next;
	}
}
