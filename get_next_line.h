/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:34:49 by thallard          #+#    #+#             */
/*   Updated: 2020/11/27 01:46:32 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int				ft_create_and_save(char **save, char **line, int size);
int				ft_is_eol(char *str);
char			*ft_create_line(char *s);
char			*ft_get_after_eol(char *save);
int				get_next_line(int fd, char **line);

unsigned int	ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2, int f);

#endif
