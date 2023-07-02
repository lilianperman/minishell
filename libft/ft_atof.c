/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:30:54 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:30:56 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atol_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

double	factor_neg(const char *str)
{
	const char	*cpy;
	double		factor;

	factor = 0.1;
	cpy = str;
	while (ft_isspace(*cpy))
		cpy++;
	if (*cpy == '-')
		factor *= -1;
	return (factor);
}

double	ft_atof(const char *str)
{
	long	nb;
	double	dnb;
	double	factor;
	int		i;

	factor = factor_neg(str);
	nb = ft_atol(str);
	dnb = 0.0;
	i = ft_atol_len(str);
	if (str[i++] == '.')
	{
		while (ft_isdigit(str[i]))
		{
			dnb = dnb + ((str[i] - '0') * factor);
			i++;
			factor = factor / 10;
		}
	}
	return (nb + dnb);
}
/*
int main (void)
{
	char str1[] = "-21474836480";
	char str2[] = "21474836470";
	char str3[] = "---+--+1234ab567";
	char str4[] = "    123456";
	char str5[] = "---+--+1234ab567";
	char str6[] = "  -.123";
	char str7[] = "-21474.83647";
	//ainda falta tratar os casos que extrapola long
	char str8[] = "-9223372036854775808000";
	char str9[] = "9223372036854775807000";
	char str10[] = "123.456";
	char str20[] = "-123.456";
	char str30[] = "---+--+123.4ab567";
	char str40[] = "   +.456";
	char str50[] = "  -123.456";
	char str60[] = "    -.123";
	char str70[] = "-21474.83647";
	char str80[] = "-2147.48.3647000";
	char str90[] = "2147.4836.47000";
	char str100[] = "  -0.123";

	printf("%f\t%f\n", ft_atof(str1), atof(str1));
	printf("%f\t%f\n", ft_atof(str2), atof(str2));
	printf("%f\t%f\n", ft_atof(str3), atof(str3));
	printf("%f\t%f\n", ft_atof(str4), atof(str4));
	printf("%f\t%f\n", ft_atof(str5), atof(str5));
	printf("%f\t%f\n", ft_atof(str6), atof(str6));
	printf("%f\t%f\n", ft_atof(str7), atof(str7));
	printf("%f\t%f\n", ft_atof(str8), atof(str8));
	printf("%f\t%f\n", ft_atof(str9), atof(str9));
	printf("%f\t%f\n", ft_atof(str10), atof(str10));
	printf("%f\t%f\n", ft_atof(str20), atof(str20));
	printf("%f\t%f\n", ft_atof(str30), atof(str30));
	printf("%f\t%f\n", ft_atof(str40), atof(str40));
	printf("%f\t%f\n", ft_atof(str50), atof(str50));
	printf("%f\t%f\n", ft_atof(str60), atof(str60));
	printf("%f\t%f\n", ft_atof(str70), atof(str70));
	printf("%f\t%f\n", ft_atof(str80), atof(str80));
	printf("%f\t%f\n", ft_atof(str90), atof(str90));
	printf("%f\t%f\n", ft_atof(str100), atof(str100));
}
*/
