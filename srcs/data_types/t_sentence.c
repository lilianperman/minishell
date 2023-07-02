/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sentence.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:17:26 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:17:28 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sentence	*new_sentence(char **args)
{
	t_sentence	*new_node;

	new_node = malloc(sizeof(t_sentence));
	if (!new_node)
		return (NULL);
	new_node->args = args;
	new_node->fd_i = 0;
	new_node->fd_o = 1;
	new_node->reds_inside = 0;
	new_node->pid = -1;
	new_node->previous = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_sentence	*find_last_sentence(t_sentence *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	addback_sentence(t_sentence **lst, t_sentence *new)
{
	t_sentence	*last;

	if (!(*lst))
		*lst = new;
	else
	{
		last = find_last_sentence(*lst);
		last->next = new;
		new->previous = last;
	}
}

void	clear_sentence(t_sentence **lst)
{
	t_sentence	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		freetab((void **)tmp->args);
		free(tmp);
		tmp = NULL;
	}
}

int	size_sentence(t_sentence **lst_sentence)
{
	int			size;
	t_sentence	*tmp;

	size = 0;
	tmp = *lst_sentence;
	if (!tmp)
		return (size);
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
