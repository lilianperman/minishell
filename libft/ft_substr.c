/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:49:18 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:49:19 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	indexa;
	size_t	indexb;

	if (!s)
		return (NULL);
	indexa = 0;
	indexb = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (s[indexa] && (indexb <= (len - 1)))
	{
		if (indexa == start && len > 0)
		{
			substr[indexb] = s[indexa];
			indexb++;
			start++;
		}
		indexa++;
	}
	substr[indexb] = '\0';
	return (substr);
}

/*
#include <stdio.h>

int main(void)
{
	char *str_substr = "lorem ipsum dolor sit amet";
	char *str_substr2 = ft_substr(str_substr, 400, 20);
	char *str_substr3 = ft_substr(str_substr, 0, 0);
	
	printf("%s\n", str_substr);
	printf("%s\n", str_substr2);
	write(1, str_substr2, 0);
	write(1, "\n", 1);
	free(str_substr2);
	printf("%s\n", str_substr3);
	write(1, str_substr3, 0);
	write(1, "\n", 1);
	free(str_substr3);
}
*/
