/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:44:01 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:44:02 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* #include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main (void)
{
	int fd = open ("teste", O_RDWR);
	
	ft_putchar_fd('c', fd);
} */
