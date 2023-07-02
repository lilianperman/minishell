/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:48:55 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:48:59 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(char c)
{
	c = ft_tolower(c);
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else
		return (37);
}

static int	get_base(const char *nptr, int base)
{
	if (base == 0)
	{
		if (*nptr == '0')
		{
			base = 8;
			nptr++;
			if (*nptr == 'x' || *nptr == 'X')
				base = 16;
		}
		else
			base = 10;
	}
	return (base);
}

static const char	*get_nptr(const char *nptr, int base)
{
	const char	*ptr;

	ptr = nptr;
	if (base == 16 && *ptr == '0')
	{
		ptr++;
		if (*ptr == 'x' || *ptr == 'X')
			ptr++;
	}
	return (ptr);
}

static long	get_result(const char *nptr, char **endptr, int base, int negative)
{
	int		digit;
	long	result;

	result = 0;
	digit = 0;
	while (*nptr && get_digit(*nptr) <= base)
	{
		digit = get_digit(*nptr);
		result = result * base;
		result = result + digit;
		if (result < 0)
		{
			if (endptr)
				*endptr = (char *) nptr;
			return (FT_LONG_MAX + negative);
		}
		nptr++;
	}
	if (endptr)
		*endptr = (char *) nptr;
	return (result + (result * -2 * negative));
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int		negative;
	long	result;

	if (base < 0 || base > 36)
		return (0);
	negative = 0;
	result = 0;
	if (base == 0 || (base >= 2 && base <= 36))
	{
		while (ft_isspace(*nptr))
			nptr++;
		if (*nptr == '-' || *nptr == '+')
		{
			if (*nptr == '-')
				negative = 1;
			nptr++;
		}
		base = get_base(nptr, base);
		nptr = get_nptr(nptr, base);
		result = get_result (nptr, endptr, base, negative);
	}
	return (result);
}

/*
int main (void)
{
	printf("ft_strtol 0XFF: %ld\n", ft_strtol("0XFF", (char **) NULL, 0));
	printf("strtol 0XFF: %ld\n", strtol("0XFF", (char **) NULL, 0));
	printf("ft_strtol 060: %ld\n", ft_strtol("060", (char **) NULL, 0));
	printf("strtol 060: %ld\n", strtol("060", (char **) NULL, 0));
	printf("ft_strtol 0060: %ld\n", ft_strtol("0060", (char **) NULL, 0));
	printf("strtol 0060: %ld\n", strtol("0060", (char **) NULL, 0));
	printf("ft_strtol FF: %ld\n", ft_strtol("FF", (char **) NULL, 16));
	printf("strtol FF: %ld\n", strtol("FF", (char **) NULL, 16));
	printf("ft_strtol 060: %ld\n", ft_strtol("060", (char **) NULL, 16));
	printf("strtol 060: %ld\n", strtol("060", (char **) NULL, 16));
	printf("ft_strtol 060: %ld\n", ft_strtol("060", (char **) NULL, 10));
	printf("strtol 060: %ld\n", strtol("060", (char **) NULL, 10));
	printf("ft_strtol 60: %ld\n", ft_strtol("60", (char **) NULL, 0));
	printf("strtol 60: %ld\n", strtol("60", (char **) NULL, 0));
	printf("ft_strtol 60: %ld\n", ft_strtol("60", (char **) NULL, 1));
	printf("strtol 60: %ld\n", strtol("60", (char **) NULL, 1));
}
*/
