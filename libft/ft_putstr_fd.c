/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:52:47 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:52:48 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

/* #include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main (void)
{
	int fd2 = open ("teste2", O_RDWR);
	
	ft_putstr_fd("fui para teste2?", fd2);
}
 */
