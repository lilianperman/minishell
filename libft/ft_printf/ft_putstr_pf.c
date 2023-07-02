/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:43:19 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:43:20 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *s)
{
	int	length;

	length = 0;
	if (!s)
	{
		length += write(1, "(null)", 6);
		return (length);
	}
	while (*s)
	{
		length += write (1, s++, 1);
	}
	return (length);
}
