/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:12:38 by thallard          #+#    #+#             */
/*   Updated: 2020/11/27 01:44:55 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int		ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
		++str;
	return (str - tmp);
}

char				*ft_strdup(char *src)
{
	char	*str;
	long	i;

	if (!(str = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

char				*ft_strjoin(char *s1, char *s2, int f)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++j])
		res[++i] = s1[j];
	j = -1;
	while (s2[++j])
		res[++i] = s2[j];
	res[i + 1] = '\0';
	if (f)
		free(s1);
	return (res);
}
