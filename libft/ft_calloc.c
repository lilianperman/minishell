/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:32:23 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:32:24 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	filled;

	filled = count * size;
	ptr = malloc (filled);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, filled);
	return (ptr);
}
