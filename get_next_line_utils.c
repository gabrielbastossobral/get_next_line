/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:28:12 by gabastos          #+#    #+#             */
/*   Updated: 2024/11/05 15:18:39 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	find;

	find = (unsigned char)c;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char *text, char *buff)
{
	size_t	i;
	size_t	j;
	size_t	size_str;
	char	*str;

	if (!text)
	{
		text = (char *)malloc(sizeof(char) * 1);
		text[0] = '\0';
	}
	size_str = ft_strlen(text) + ft_strlen(buff);
	if (!text || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (size_str + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (text[++i])
		str[i] = text[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[size_str] = '\0';
	free(text);
	return (str);
}

char	*ft_get_line(char	*text)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
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
	line[i] = '\0';
	return (line);
}

char	*ft_new_text_position(char	*text)
{
	size_t	i;
	size_t	j;
	size_t	size_text;
	char	*new_text;

	size_text = ft_strlen(text);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	new_text = (char *)malloc(sizeof(char) * (size_text - i + 1));
	if (!new_text)
		return (NULL);
	i++;
	j = 0;
	while (text[i])
		new_text[j++] = text[i++];
	new_text[j] = '\0';
	free(text);
	return (new_text);
}
