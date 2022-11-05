/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:22:27 by oelbouha          #+#    #+#             */
/*   Updated: 2022/10/29 18:49:03 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	rest[BUFFER_SIZE];
	char		**str;
	int			r;
	int			n;

	if (ft_strchr(rest, '\n'))
		return (check_rest(rest));
	n = 0;
	str = NULL;
	while (++n)
	{
		r = read (fd, buff, BUFFER_SIZE);
		if (r == 0 && rest[0])
			break ;
		if (r < 0 || (r == 0 && str == NULL))
			return (0);
		buff[r] = 0;
		str = save_buff(str, buff, n);
		if (!str)
			return (0);
		if (ft_strchr(buff, '\n') || r < BUFFER_SIZE)
			break ;
	}
	return (make_line(str, rest, n));
}
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// int main()
// {
// 	char *str ;
// 	// int fd = open("open", O_CREAT | O_RDWR);
// 	// str = get_next_line(fd);
// 	// printf("line ==> %s", str);
// 	// close(fd);
// 	// int fd1 = open("open", O_CREAT | O_RDWR);
// 	str = get_next_line(5);
// 	printf("line ==> %s", str);
// }
