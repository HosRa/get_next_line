/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:21:29 by thallard          #+#    #+#             */
/*   Updated: 2020/11/26 19:49:31 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_create_and_save(char **save, char **line, int size)
{
	*line = ft_create_line(*save);
	// if (*line)
	// {
	// 	free(*line);
	// 	return (-1);
	// }
	*save = ft_get_after_eol(*save);
	if (size <= 0)
	{
		free(*save);
		return (0);
	}
	return (1);
}

int		ft_is_eol(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_create_line(char *s)
{
	int		i;
	char	*str;

	i = -1;
	while (s[++i] && s[i] != '\n')
		;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	*ft_get_after_eol(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!(save[i]) || !(str = malloc(sizeof(char) * (ft_strlen(save) - i + 1))))
		return (NULL);	
	i++;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char				buf[BUFFER_SIZE + 1];
	static char			*save[4096];
	int					size;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	size = 1;
	if (!save[fd])
		save[fd] = "";
	while (!(ft_is_eol(save[fd])))
	{
		if ((size = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		else if (size == 0)
			break ;
		buf[size] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
	}
	return (ft_create_and_save(&save[fd], line, size));
}
