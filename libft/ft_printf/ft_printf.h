/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:40:54 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:40:56 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int	ft_printf(const char *format, ...);
int	ft_spec_conversion(const char *fmt, int i, va_list args);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *s);
int	ft_putnbr_pf(int n);
int	ft_putnbru_pf(unsigned int n);
int	ft_puthex_pf(unsigned int n);
int	ft_puthexx_pf(unsigned int n);
int	ft_puthexp_pf(unsigned long int nbr);

#endif
