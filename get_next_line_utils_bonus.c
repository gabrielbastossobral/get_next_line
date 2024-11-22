/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:46:23 by gabrielsobr       #+#    #+#             */
/*   Updated: 2024/11/22 15:50:00 by gabrielsobr      ###   ########.fr       */
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

void	*ft_calloc(size_t num, size_t size)
{
	size_t	i;
	void	*memory;
	char	*ptr;

	if (num != 0 && size > (size_t) - 1 / num)
		return (NULL);
	memory = malloc(num * size);
	if (!memory)
		return (NULL);
	ptr = (char *)memory;
	i = 0;
	while (i < num * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (memory);
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
		text = ft_calloc(1, 1);
	if (!text || !buff)
		return (NULL);
	size_str = ft_strlen(text) + ft_strlen(buff);
	str = ft_calloc(sizeof(char), (size_str + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (text[++i])
		str[i] = text[i];
	while (buff[j])
		str[i++] = buff[j++];
	free(text);
	return (str);
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
	new_text = ft_calloc(sizeof(char), (size_text - i + 1));
	if (!new_text)
		return (NULL);
	i++;
	j = 0;
	while (text[i])
		new_text[j++] = text[i++];
	free(text);
	return (new_text);
}
