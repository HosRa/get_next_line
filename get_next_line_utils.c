/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:12:38 by thallard          #+#    #+#             */
/*   Updated: 2020/11/19 10:39:54 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int     ft_strlen(char *str)
{
    int     i;
    
    if (str[0] == '\0')
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	        *ft_strdup(char *src)
{
	char	*str;
	long	i;

	str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}