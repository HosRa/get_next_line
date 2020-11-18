/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:21:29 by thallard          #+#    #+#             */
/*   Updated: 2020/11/18 10:52:15 by thallard         ###   ########lyon.fr   */
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
    res[i + 1] = '\0';
    return (res);
}

int     ft_find_eof(char *buf, int size)
{
    int     i;

    if (size < BUFFER_SIZE)
        return (0);
    i = -1;
    while (buf[++i])
        if (buf[i] == '\n')
        {
            buf[i] = '\0';
            return (i);
        }
    return (-1);
}

int     ft_check_buf(int fd, char *buf, char **line)
{
    int     eof;

    if (line[0][0] == '\0')
        *line = ft_strjoin(*line, buf);
    int size = read(fd, buf, BUFFER_SIZE);
    eof = ft_find_eof(buf, size);
    if (eof >= 0)
    {
        line[0] = ft_strjoin(line[0], buf);
        return (0);
      
    }
    else if (eof == -1)
    {
      
        line[0] = ft_strjoin(line[0], buf);
        return (1);
    }
    
    return (1);
}

int     get_next_line(int fd, char **line)
{
    int             i;
    char            buf[BUFFER_SIZE];
    int             j;

    if (!(line[0] = malloc(sizeof(char) * 100)))
        return (-1);
    j = -1;
    i = -1;
    read(fd, buf, BUFFER_SIZE);
    while (++i <= BUFFER_SIZE)
    {
        printf("I : %d", i);
        if (i == BUFFER_SIZE || buf[i + 1] == '\0' || buf[i] == '\n')
        {
            if (ft_check_buf(fd, buf, line) == 1)
                i = -1;
            else
            {
                return (-4);
            }
        }
        // je read sur la longueur de buffer_size
        // ft_check_buf() : fonction qui sert à trouver si y'a un \n ou un \0, si oui alors je strjoin ce que j'ai avec ce qui sort du read juste au dessus
        // si je trouve pas un des deux, je continue à strjoin tant que je trouve un \n ou \0 dans mon prochain read
    }
    return (2);
}

int main()
{
    char *line[50];
    int file = open("test.txt", O_RDONLY);

    printf("Résultat GNL : %d\n", get_next_line(file, line));
    printf("LIne 0 : %s", line[0]);
   // printf("\nLine 1 : %s", line[1]);
}