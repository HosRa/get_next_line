/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:12:38 by thallard          #+#    #+#             */
/*   Updated: 2020/11/26 17:38:35 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

char				*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		res[++i] = *s1++;
	while (*s2)
		res[++i] = *s2++;
	res[i + 1] = '\0';
	return (res);
}
