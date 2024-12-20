/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:29:48 by gabastos          #+#    #+#             */
/*   Updated: 2024/11/05 14:09:15 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
	return (NULL);
}

static char	*ft_get_line(char	*text)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		line[i] = text[i];
		i++;
	}
	return (line);
}

static char	*get_line_fd(int fd, char *line)
{
	char	*buff;
	int		rd_bytes;

	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(buff, NULL));
	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			ft_free(buff, line);
			return (NULL);
		}
		buff[rd_bytes] = 0;
		line = ft_strjoin(line, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if ((line[0] == '\0' || !line) && rd_bytes == 0)
		return (ft_free(line, buff));
	ft_free(buff, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_free(line, text);
		return (NULL);
	}
	text = get_line_fd(fd, text);
	if (!text)
		return (NULL);
	line = ft_get_line(text);
	if (!line)
	{
		ft_free(line, text);
		return (NULL);
	}
	text = ft_new_text_position(text);
	return (line);
}
