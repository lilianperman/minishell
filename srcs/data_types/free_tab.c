/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:13:03 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:13:05 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freetab(void **ptr)
{
	char	**tmp;
	int		i;

	if (!ptr)
		return ;
	i = 0;
	tmp = (char **)ptr;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(ptr);
}

void	free_array(char **tab)
{
	size_t	i;
	char	*s;

	i = 0;
	while (tab[i])
	{
		s = tab[i];
		free(s);
		i++;
	}
	free(tab);
	tab = NULL;
}
