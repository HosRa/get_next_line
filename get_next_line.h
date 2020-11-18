/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:34:49 by thallard          #+#    #+#             */
/*   Updated: 2020/11/17 20:15:11 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 11
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // a retirer
# include <fcntl.h>

int             get_next_line(int fd, char **line);

unsigned int    ft_strlen(char *str);
char	        *ft_strdup(char *src);



#endif