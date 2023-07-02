/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:45:33 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:45:35 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (!s)
		return (NULL);
	while (s[index] != (char)c)
	{
		if (s[index] == '\0')
			return (NULL);
		index++;
	}
	return ((char *) &s[index]);
}
