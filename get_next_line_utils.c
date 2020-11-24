/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:12:38 by thallard          #+#    #+#             */
/*   Updated: 2020/11/24 18:41:45 by thallard         ###   ########lyon.fr   */
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

int		ft_isin(char *str)
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

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *res;
    int     i;

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

char	*ft_setline(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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
