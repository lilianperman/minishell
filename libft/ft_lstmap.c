/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:37:54 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:37:56 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	newnode = NULL;
	newlst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		newnode = ft_lstnew((*f)(lst->content));
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
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

void *make_upper_2(void *sqnc)
{
    char *str;
 
    str = (char *) sqnc;
    make_upper(str);
    return (str);
}

void    del_content(void *pointer)
{
    printf("deleted %p\n", pointer);
}

int main(void)
{
	t_list *people;
	t_list *people2;

	char content1[] = "izsoares";
	char content2[] = "antes de izsoares";
	char content3[] = "antes de antes";
	char content4[] = "serei o ultimo?";
	people = ft_lstnew(content1);
	ft_lstadd_front(&people, ft_lstnew(content2));
	ft_lstadd_front(&people, ft_lstnew(content3));
	ft_lstadd_back(&people, ft_lstnew(content4));
	printlst(people);
	people2 = ft_lstmap(people, make_upper_2, del_content);
	printlst(people2);
	return (0);
} 
 */
