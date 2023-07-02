/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:10:17 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:10:20 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:t_env *env - envp list(head)
 *					:char *key - element to be compared
 * Scope			:compares if the key of the argument is the same
 * 					as the environment variable
 * Output			:existing key in the environment variable
 * 					:or
 * 					:NULL
 */
t_env	*compare_key(t_env *env, char *key)
{
	t_env	*node;

	node = env;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key) + 1) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
