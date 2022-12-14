/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:22:27 by oelbouha          #+#    #+#             */
/*   Updated: 2022/10/31 15:52:43 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*fresh;
	int		i;
	int		j;

	i = ft_strlen(s1) + 1;
	fresh = malloc(sizeof(char) * i);
	if (!fresh)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
	{
		fresh[j] = s1[i];
		i++;
		j++;
	}
	fresh[j] = '\0';
	return (fresh);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

char	*check_rest(char *rest)
{
	char	*line;
	int		i;

	i = 0;
	while (rest[i] != '\n')
		i++;
	i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, rest, i);
	ft_strncpy(rest, &rest[i], ft_strlen(rest) - i + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	rest[10000][BUFFER_SIZE];
	char		**str;
	int			r;
	int			n;

	if (fd < 0)
		return (0);
	if (ft_strchr(rest[fd], '\n'))
		return (check_rest(rest[fd]));
	n = 0;
	str = NULL;
	while (++n)
	{
		r = read (fd, buff, BUFFER_SIZE);
	//	if (r == 0 && *rest[fd])
	//		break ;
		if (r < 0 || (r == 0 && str == NULL))
			return (0);
		buff[r] = 0;
		str = save_buff(str, buff, n);
		if (ft_strchr(buff, '\n') || r < BUFFER_SIZE)
			break ;
	}
	return (make_line(str, rest[fd], n));
}/*
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main ()
{
	int fd = open("file", O_CREAT | O_RDWR);
	printf("line ==> %s", get_next_line(fd));
	close (fd);
	int fd1 = open("file", O_CREAT | O_RDWR);	
	printf("line ==> %s", get_next_line(fd1));
	return 0;
}*/
