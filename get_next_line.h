/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:30:16 by gabastos          #+#    #+#             */
/*   Updated: 2024/10/30 11:53:30 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *text, char *buff);
char		*ft_get_line(char	*text);
char		*ft_new_text_position(char	*text);
char		*get_line_fd(int fd, char *line);
char		*get_next_line(int fd);

#endif