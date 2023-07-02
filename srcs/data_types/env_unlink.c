/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:12:52 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:12:54 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_first(t_env **lst, t_env *to_remove);
static void	remove_later(t_env **lst, t_env *to_remove);

/*
 * Fn		: env_unlink(t_env **lst, t_env *to_remove)
 * Scope	: remove node from list and relink remaining nodes
 * Input	: t_env ** - address of list
 *			: t_env * - node to be unlinked
 * Output	: t_env * - the unlinked node that can be freed
 * Errors	: not applicable
 * Uses		: unset
 */
t_env	*env_unlink(t_env **lst, t_env *to_remove)
{
	t_env	*tmp;

	tmp = *lst;
	while (tmp && tmp != to_remove)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	if (tmp == *lst)
		remove_first(lst, to_remove);
	else
		remove_later(lst, to_remove);
	*(*lst)->size -= 1;
	return (to_remove);
}

static void	remove_first(t_env **lst, t_env *to_remove)
{
	*lst = (*lst)->next;
	to_remove->next = NULL;
	to_remove->size = NULL;
}

static void	remove_later(t_env **lst, t_env *to_remove)
{
	t_env	*previous;

	previous = *lst;
	while (previous->next != to_remove)
		previous = previous->next;
	previous->next = to_remove->next;
	to_remove->next = NULL;
	to_remove->size = NULL;
}
