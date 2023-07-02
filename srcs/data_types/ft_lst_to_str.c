/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:13:18 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:13:21 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_lst_to_str(t_string *lst)
{
	char	*str;
	size_t	length;
	int		i;

	length = ft_strtotallen(lst);
	if (!length)
		return (NULL);
	str = malloc((length + 1) * sizeof(*str));
	str[length] = '\0';
	i = 0;
	while (lst)
	{
		if (lst->content)
			ft_memcpy(&str[i], lst->content, lst->length);
		i += lst->length;
		lst = lst->next;
	}
	return (str);
}
