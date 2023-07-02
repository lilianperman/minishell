/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:12:00 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:12:02 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Input			:t_env *env - envp list(head)
 *					:t_env *next_env - next node in env list
 * Scope			:swapping the position of the next node with the previous node
 * Output			:none
 */
static void	swap_node(t_env *env, t_env *next_env)
{
	char	*key;
	char	*value;

	key = env->key;
	value = env->value;
	env->key = next_env->key;
	env->value = next_env->value;
	next_env->key = key;
	next_env->value = value;
}

/*
 * Input			:t_env *env - envp list(head)
 * Output			:the sorted envp list
 */
static t_env	*sort_env(t_env *env)
{
	t_env	*new_node;

	new_node = env;
	while (new_node->next)
	{
		if (ft_strcmp(new_node->key, new_node->next->key) > 0)
		{
			swap_node(new_node, new_node->next);
			new_node = env;
		}
		else
			new_node = new_node->next;
	}
	return (env);
}

/*
 * Input			:t_env *env - envp list(head)
 * Output			:the copy of the env list
 */
static t_env	*copy_env_list(t_env *env)
{
	t_env	*new_node;
	t_env	*tmp_node;

	new_node = new_env(env->key, env->value);
	tmp_node = new_node;
	env = env->next;
	while (env)
	{
		tmp_node->next = new_env(env->key, env->value);
		tmp_node = tmp_node->next;
		env = env->next;
	}
	return (new_node);
}

/*
 * Input			:t_env *env - envp list(head)
 * Scope			:calling function to duplicate the envp list to be able to sort
 * Output			:print environment variables in order with 'declare -x'
 */
void	print_export(t_env *env)
{
	t_env	*node;
	t_env	*tmp;
	t_env	*env_sorted;

	tmp = copy_env_list(env);
	env_sorted = sort_env(tmp);
	node = env_sorted;
	while (node)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(node->key, STDOUT_FILENO);
		ft_putstr_fd("=\"", STDOUT_FILENO);
		if (node->value)
			ft_putstr_fd(node->value, STDOUT_FILENO);
		ft_putstr_fd("\"\n", STDOUT_FILENO);
		node = node->next;
	}
	clear_env(&env_sorted);
}
