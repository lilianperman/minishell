/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:50:15 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:50:18 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_file(int fd, char *strbuf)
{
	char	*buf;
	ssize_t	b_read;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	b_read = 1;
	while (fd >= 0 && b_read != 0 && !ft_strchr(strbuf, '\n'))
	{
		b_read = read (fd, buf, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[b_read] = '\0';
		strbuf = ft_strjoin_free(strbuf, buf);
	}
	free(buf);
	return (strbuf);
}

char	*get_line(char *strbuf)
{
	char	*line;
	size_t	i;

	if (!strbuf)
		return (NULL);
	i = 0;
	if (strbuf[0] == '\0')
	{
		return (NULL);
	}
	while (strbuf[i] && strbuf[i] != '\n')
		i++;
	if (strbuf[i] == '\n')
		i++;
	line = ft_substr(strbuf, 0, i);
	return (line);
}

char	*rest_line(char *strbuf)
{
	char	*r_line;
	size_t	i;

	if (!strbuf)
		return (NULL);
	i = 0;
	while (strbuf[i] && strbuf[i] != '\n')
		i++;
	if (strbuf[i] == '\0')
	{
		free(strbuf);
		return (NULL);
	}
	if (strbuf[i] == '\n')
		i++;
	r_line = ft_substr(strbuf, i, (ft_strlen(strbuf) - i));
	free(strbuf);
	return (r_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strbuf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	strbuf = get_file(fd, strbuf);
	if (!strbuf)
		return (NULL);
	line = get_line(strbuf);
	strbuf = rest_line(strbuf);
	return (line);
}
