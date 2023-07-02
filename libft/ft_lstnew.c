/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:38:09 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:38:10 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* 
#include <stdio.h>
int main(void)
{
	t_list *person;
	char *content;
	
	content = "izsoares";
	person = ft_lstnew(content);
	printf("%s\n", (char *) person->content);
	printf("%p\n", person->next);
}
 */
