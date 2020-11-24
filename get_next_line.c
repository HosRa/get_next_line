/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:21:29 by thallard          #+#    #+#             */
/*   Updated: 2020/11/24 18:42:27 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_nxtline(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{

		return (0);
	}
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) - i + 1))))
		return (0);
	i++;
	while (s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char		      *buf;
	static char	  *save;
	int			      rtn;

	rtn = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_isin(save) && rtn != 0)
	{
		if ((rtn = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[rtn] = '\0';
		save = ft_strjoin(save, buf);
	}
	*line = ft_setline(save);
	save = cut_nxtline(save);
	if (rtn == 0)
		return (0);
	return (1);
}

int    main()
{
    int fd;
    char *res[50];
    fd = open("test.txt", O_RDONLY);
    while (get_next_line(fd, res) >= 1)
    {
    printf("Line 0 : %s\n", res[0]);
    }
 
   
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