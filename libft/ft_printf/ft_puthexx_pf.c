/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexx_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:42:16 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:42:18 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexx_pf(unsigned int n)
{
	unsigned int	i;
	int				length;
	char			*x;

	i = 0;
	x = "0123456789ABCDEF";
	length = 0;
	if (n > 15)
		length += ft_puthexx_pf(n / 16);
	i = n % 16;
	length += ft_putchar_pf(x[i]);
	return (length);
}
