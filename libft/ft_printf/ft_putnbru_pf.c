/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:43:02 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:43:04 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru_pf(unsigned int n)
{
	long int	nbr;
	int			length;

	length = 0;
	nbr = n;
	if (nbr > 9)
		length += ft_putnbru_pf(nbr / 10);
	length += ft_putchar_pf((nbr % 10) + '0');
	return (length);
}
