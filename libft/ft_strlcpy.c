/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:47:19 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:47:20 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	index;

	srclen = ft_strlen(src);
	index = 0;
	if (srclen + 1 < size)
	{
		while (index < srclen +1)
		{
			dst[index] = src[index];
			index++;
		}
	}
	else if (size != 0)
	{
		index = 0;
		while (index < size - 1)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (srclen);
}
