/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:12:28 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:12:30 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input	:char *str - environment variable in wrong format
 *			:char *key - string that was split (environment variable key
 * Scope	:checks that the key is in the correct format
 *          :if the key exists in the env list delete the node
 */
static void	delete_var(t_env **env, char *key)
{
	t_env	*node;
	int		size;
	t_env	*tmp;

	size = 0;
	tmp = *env;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	if (size == 1)
		return ;
	node = compare_key(*env, key);
	if (*env == NULL || node == NULL)
		return ;
	envdel_one(env_unlink(env, node));
}

/*
 * Input	:int size - amount of arguments
 *			:char *str[] - arguments (command unset and/or enviroment variable)
 *			:Example: argv[0] = unset - argv[1] = students
 * Scope	:check key match
 */
int	unset(int size, char *str[], t_env **env)
{
	int	i;

	i = 0;
	if (size <= 1)
		return (0);
	while (++i < size)
	{
		if (check_varname(str[i]))
			delete_var(env, str[i]);
	}
	return (0);
}
