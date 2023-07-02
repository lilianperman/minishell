/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:41:41 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:41:44 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int n)

{
	unsigned int	i;
	int				length;
	char			*x;

	i = 0;
	x = "0123456789abcdef";
	length = 0;
	if (n > 15)
		length += ft_puthex_pf(n / 16);
	i = n % 16;
	length += ft_putchar_pf(x[i]);
	return (length);
}
