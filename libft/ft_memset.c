/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:39:43 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:39:45 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*dest;

	index = 0;
	dest = s;
	while (index < n)
	{
		dest[index] = (unsigned char)c;
		index++;
	}
	return (dest);
}
