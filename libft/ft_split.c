/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:45:10 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:45:11 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_scount(char const *s, char c)
{
	size_t	index;
	size_t	scount;

	index = 0;
	scount = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != c && s[index])
			scount++;
		while (s[index] != c && s[index])
			index++;
	}
	return (scount);
}

static size_t	ft_ssize(char const *s, char c)
{
	size_t	ssize;

	ssize = 0;
	while (s[ssize] && s[ssize] != c)
	{
		ssize++;
	}
	return (ssize);
}

static char	**ft_free(char **table, size_t size)
{
	size_t	index;

	index = 0;
	while (index <= size)
	{
		free (table[index]);
		index++;
	}
	free(table);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	size_t	lines;
	size_t	index;
	size_t	subend;

	if (!s)
		return (NULL);
	lines = ft_scount(s, c);
	table = malloc((sizeof(char *) * (lines + 1)));
	if (!table)
		return (NULL);
	index = 0;
	while (index < lines)
	{
		while (*s && *s == c)
			s++;
		subend = ft_ssize(s, c);
		table[index] = ft_substr(s, 0, subend);
		if (!(table[index]))
			ft_free(table, index);
		index++;
		s = s + subend;
	}
	table[index] = NULL;
	return (table);
}

/*
#include <stdio.h>
int main(void)
{
	char *str_ft_split = ",,,,preciso ser, separada, help me,,,,,,,,oi,
	meu Deus!, foi ca¨&@%&¨@%!!!";
	char c_split = ',';
	char **table_ft_split;
	int index;

	table_ft_split = ft_split(str_ft_split, c_split);
	
	printf("Quantidade de palavras na string: %ld\n",
	ft_scount(str_ft_split, c_split));
	printf("Tamanho da string até o sep: %ld\n",
	ft_ssize(str_ft_split, c_split));
	
	index = 0;
	while (table_ft_split[index])
	{
		printf("table_ft_split[%d]: %s\n", index, table_ft_split[index]);
		index++;
	}
	free(table_ft_split);
}
*/
