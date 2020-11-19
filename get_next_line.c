/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:21:29 by thallard          #+#    #+#             */
/*   Updated: 2020/11/19 11:45:00 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char *s1, char *s2)
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
    return (res);
}

int     ft_find_eof(char buf[BUFFER_SIZE + 1], int size)
{
    int     i;

    if (size < BUFFER_SIZE)
        return (0);
    i = -1;
    while (buf[++i])
        if (buf[i] == '\n')
        {
            buf[i] = '\0';
            printf("Trouvé %s\n", buf);
            return (i);
        }
    printf("ici");
    return (-1);
}

int     ft_check_buf(int fd, char buf[BUFFER_SIZE + 1], char **line)
{
    int     eof;
    int     size;

    if (line[0][0] == '\0')
    {
        if (ft_find_eof(buf, BUFFER_SIZE) >= 0)
        {
            *line = ft_strjoin(*line, buf);
            return (0);
        }
        *line = ft_strjoin(*line, buf);
        return (1);
    }    
    size = read(fd, buf, BUFFER_SIZE);
    if (ft_find_eof(buf, size) >= 0)
    {
        *line = ft_strjoin(*line, buf);
        return (0);
    }
    else
    {
        printf("Line avant join : %s\n", buf);
        *line = ft_strjoin(*line, buf);
        printf("Line après join : %s\n", *line);
        return (1);
    }
    return (1);
}

int     get_next_line(int fd, char **line)
{
    int             i;
    char            buf[BUFFER_SIZE + 1];
    int             util;
    static int      nblines = 0;

    if (!(*line = malloc(sizeof(char) * 100)))
        return (-1);
    i = -1;
    util = read(fd, buf, BUFFER_SIZE);
    buf[util] = '\0';
    printf("premier buf %s\n", buf);
    while (++i <= BUFFER_SIZE)
    {
       // printf("I : %d\n", i);
        if (i == BUFFER_SIZE || buf[i + 1] == '\0' || buf[i] == '\n')
        {
            util = ft_check_buf(fd, buf, line);
            if (util == 1)
                i = -1;
            else if (util == -1)
            {
                nblines++;
                return (0);
            }
            else
            {
                nblines++;
                return (1);
            }
        }
    }
    return (-1);
}

int main()
{
    char *line[50];
    int file = open("test.txt", O_RDONLY);

    printf("Résultat GNL : %d\n", get_next_line(file, line));
    printf("LIne 0 : %s", line[0]);
    printf("Mon fd : %d", file);
   // printf("\nLine 1 : %s", line[1]);
}