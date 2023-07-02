/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:37:21 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:37:23 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		(f)(lst->content);
		lst = lst->next;
	}	
}

/* 
#include <stdio.h>
void printlst(t_list *node)
{
	while(node)
	{
		printf("%s\n", node ->content);
		node = node -> next;
	}
}

char get_upper(unsigned int i, char c)
{
    i = 0;
    if (ft_isalpha(c))
    {
        return (ft_toupper(c));
    }
    return (c);
}

void make_upper(void *sqnc)
{
    char *str;
 
    str = (char *) sqnc;
    while(*str != '\0')
    {
        *str = get_upper(0, *str);
        str++;
    }
}

int main(void)
{
	t_list *people;

	char content1[] = "izsoares";
	char content2[] = "antes de izsoares";
	char content3[] = "antes de antes";
	char content4[] = "serei o ultimo?";
	people = ft_lstnew(content1);
	ft_lstadd_front(&people, ft_lstnew(content2));
	ft_lstadd_front(&people, ft_lstnew(content3));
	ft_lstadd_back(&people, ft_lstnew(content4));
	printlst(people);
	ft_lstiter(people, make_upper);
	printlst(people);
	return (0);
} 
 */
