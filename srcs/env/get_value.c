/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:19:54 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:19:56 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*set_format(char *var_name, int size);
static char	*search_value(char *key, int size, t_env *env);

/*
 * Fn		: get_value(char *var, int size, t_env *env)
 * Scope	: retrieves the value of an environment variable in a string
 * Input	: char * - the variable name, without $
 *			: int size - the number of characters of variable name
 *			: t_env * - list of environment variables
 * Output	: char * - string with the value of the variable
 *				NULL - variable not found or without value
 * Errors	: not applicable
 * Uses		: expvar() [by scan_sentence]
 */
char	*get_value(char *var, int size, t_env *env)
{
	char	*value;
	char	*key;

	key = set_format(var, size);
	value = search_value(key, size + 1, env);
	free(key);
	key = NULL;
	return (value);
}

static char	*set_format(char *var_name, int size)
{
	char	*output;

	output = malloc((size + 1) * sizeof(*output));
	if (!output)
	{
		ft_putstr_fd("Malloc error on set_format()\n", 2);
		return (NULL);
	}
	output[size] = '\0';
	ft_memcpy(output, var_name, size);
	return (output);
}

static char	*search_value(char *key, int size, t_env *env)
{
	while (env)
	{
		if (!ft_strncmp(key, env->key, size))
		{
			if (!env->value)
				return (NULL);
			return (ft_strdup(env->value));
		}
		env = env->next;
	}
	return (NULL);
}
