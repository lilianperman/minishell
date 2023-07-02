/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:42:36 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:42:41 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	long int	nbr;
	int			length;

	length = 0;
	nbr = n;
	if (nbr < 0)
	{
		length += ft_putchar_pf('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
		length += ft_putnbr_pf(nbr / 10);
	length += ft_putchar_pf((nbr % 10) + '0');
	return (length);
}
