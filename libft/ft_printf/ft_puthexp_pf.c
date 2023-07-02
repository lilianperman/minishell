/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexp_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:42:03 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:42:05 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long int n)
{
	unsigned long int	i;
	int					length;
	char				*x;

	i = 0;
	x = "0123456789abcdef";
	length = 0;
	if (n > 15)
		length += ft_puthex(n / 16);
	i = n % 16;
	length += ft_putchar_pf(x[i]);
	return (length);
}

int	ft_puthexp_pf(unsigned long int nbr)
{
	int	length;

	length = 0;
	length += write (1, "0x", 2);
	length += ft_puthex(nbr);
	return (length);
}
