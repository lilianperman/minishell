/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:31:39 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:31:41 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	index;
	int	signal;

	number = 0;
	index = 0;
	signal = 1;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			signal *= -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		number = number + (str[index] - '0');
		index++;
		if (ft_isdigit(str[index]))
			number = number * 10;
	}
	return (signal * number);
}
