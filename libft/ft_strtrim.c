/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:49:08 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:49:09 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	size_t	start;
	size_t	end;
	size_t	length;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	end = ft_strlen(s1);
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
	{
		end--;
	}
	length = end - start;
	trimed = ft_substr(s1, start, length);
	return (trimed);
}
