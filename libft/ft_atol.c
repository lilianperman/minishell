/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:31:52 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:31:53 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	return (ft_strtol(str, (char **) NULL, 10));
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
	char str8[] = "-9223372036854775808000";
	char str9[] = "9223372036854775807000";

	printf("%d\t%d\n", ft_atoi(str1), atoi(str1));
	printf("%d\t%d\n", ft_atoi(str2), atoi(str2));
	printf("%ld\t%ld\n", ft_atol(str3), atol(str3));
	printf("%ld\t%ld\n", ft_atol(str4), atol(str4));
	printf("%ld\t%ld\n", ft_atol(str5), atol(str5));
	printf("%ld\t%ld\n", ft_atol(str6), atol(str6));
	printf("%ld\t%ld\n", ft_atol(str7), atol(str7));
	printf("%ld\t%ld\n", ft_atol(str8), atol(str8));
	printf("%ld\t%ld\n", ft_atol(str9), atol(str9));
}
*/
