/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:40:29 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:40:31 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ret += ft_putchar_pf(format[i]);
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ret += ft_spec_conversion(format, i, args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}	
