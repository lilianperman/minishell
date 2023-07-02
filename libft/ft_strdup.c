/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:45:57 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:45:59 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1cpy;
	char	*s2;
	size_t	s1len;
	size_t	index;

	if (!s1)
		return (NULL);
	s1cpy = (char *)s1;
	s1len = ft_strlen(s1cpy);
	s2 = malloc((s1len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	index = 0;
	while (index < s1len)
	{
		s2[index] = s1cpy[index];
		index++;
	}
	s2[index] = '\0';
	return (s2);
}
