/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:17:14 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:17:16 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Fn		: set_envsize(t_env *env)
 * Scope	: set the size variable from t_env list
 *			: should be used only once on the list creation
 * Input	: t_env * - the list
 * Output	: void
 * Errors	: not applicable
 * Uses		: get_env
 */
void	set_envsize(t_env *env)
{
	int	nodes;

	if (env->size)
		return ;
	env->size = malloc(sizeof(*env->size));
	protect_malloc((void *)env->size);
	nodes = 1;
	while (env->next)
	{
		env->next->size = env->size;
		env = env->next;
		nodes++;
	}
	*env->size = nodes;
}

/*
 * Input			:char *key - environment variable key
 *					:char *value - environment variable value
 *					:char size - amount of environment variable
 * Scope			:adding the key and value in a new node
 * Output			:a new node with the data from env
 */
t_env	*new_env(char *key, char *value)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	protect_malloc(node);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	node->size = NULL;
	return (node);
}

/*
 * Input			:t_env *env - envp list(head)
 *					:char *key - environment variable key
 *					:char *value - environment variable kvalue
 * Scope			:creating a new node
 * Output			:add keys and values to the node
 */
t_env	*addfront_env(t_env *env, char *key, char *value)
{
	t_env	*new;

	new = new_env(key, value);
	if (env == NULL)
		env = new;
	else
	{
		new->next = env;
		env = new;
	}
	if (env->size)
		*env->size += 1;
	return (env);
}

void	envdel_one(t_env *node)
{
	free(node->key);
	free(node->value);
	if (node->size)
		free(node->size);
	node->size = NULL;
	free(node);
}

/*
 * Input			:t_env - envp list
 * Scope			:clear env list
 * Output			:none
 */
void	clear_env(t_env **env)
{
	t_env	*node;

	while (*env)
	{
		node = *env;
		*env = (*env)->next;
		if (node->size)
		{
			*node->size -= 1;
			if (!*node->size)
				free(node->size);
			node->size = NULL;
		}
		envdel_one(node);
		node = NULL;
	}
}
