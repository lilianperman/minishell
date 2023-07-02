/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdelim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:23:35 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:23:37 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isdelim(char c)
{
	const char	*delim = "|<>";

	while (*delim)
	{
		if (c == *delim)
			return (c);
		delim++;
	}
	return (0);
}
