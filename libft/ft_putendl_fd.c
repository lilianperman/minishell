/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:44:14 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:44:16 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

/* #include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main (void)
{
	int fd3 = open ("teste3", O_RDWR);
	
	ft_putendl_fd("fui para teste3 com quebra?", fd3);
} */
