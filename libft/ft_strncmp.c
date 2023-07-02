/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:48:08 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:48:10 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n > 0)
	{
		while (index < n - 1 && s1[index] == s2[index]
			&& (s1[index] || s2[index]))
		{
			index++;
		}
		return ((unsigned char) s1[index] - (unsigned char) s2[index]);
	}
	return (0);
}
