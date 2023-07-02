/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:36:49 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:36:51 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lstaux;

	if (!lst)
		return ;
	lstaux = *lst;
	while (*lst)
	{
		lstaux = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = lstaux;
	}
	*lst = NULL;
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

void ft_del(void *content)
{
	content = 0;
}


int main(void)
{
	t_list *people;
	char *content1;
	char *content2;
	char *content3;
	char *content4;
	
	content1 = "izsoares";
	content2 = "antes de izsoares";
	content3 = "antes de antes";
	content4 = "serei o ultimo?";
	people = ft_lstnew(content1);
	ft_lstadd_front(&people, ft_lstnew(content2));
	ft_lstadd_front(&people, ft_lstnew(content3));
	ft_lstadd_back(&people, ft_lstnew(content4));
	printlst(people);
	ft_lstclear(&people, ft_del);
	printlst(people);
	return (0);
} 
 */
