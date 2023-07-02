/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:37:41 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:37:43 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while (aux->next)
	{
		aux = aux -> next;
	}
	return (aux);
}

/* 
#include <stdio.h>
void printlst(t_list *node)
{
	while(node)
	{
		printf("%s\n",(char *) node ->content);
		node = node -> next;
	}
}


int main(void)
{
	t_list *people;
	char *content1;
	char *content2;
	char *content3;
	char *lastcontent;
	
	content1 = "izsoares";
	content2 = "antes de izsoares";
	content3 = "antes de antes";
	people = ft_lstnew(content1);
	ft_lstadd_front(&people, ft_lstnew(content2));
	ft_lstadd_front(&people, ft_lstnew(content3));
	printlst(people);
	printf("lstlast:%s\n", *ft_lstlast(people));
	return (0);
}
 */
