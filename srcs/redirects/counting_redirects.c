/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_redirects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:25:50 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:25:52 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	counting_redirects(t_token **lst_token)
{
	t_token	*tmp;
	int		count;

	tmp = *lst_token;
	count = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->tkn > PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
