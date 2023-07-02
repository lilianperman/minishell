/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:38:49 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:38:54 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*bcpy;

	bcpy = (unsigned char *) b;
	index = 0;
	while (index < len)
	{
		if (bcpy[index] == (unsigned char) c)
			return ((unsigned char *) &bcpy[index]);
		index++;
	}
	return (NULL);
}
