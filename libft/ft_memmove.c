/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:39:31 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:39:33 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*memory_dest;
	const char	*memory_src;
	size_t		index;

	memory_dest = dest;
	memory_src = src;
	index = n;
	if (memory_src < memory_dest)
	{
		while (index)
		{
			index--;
			memory_dest[index] = memory_src[index];
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
