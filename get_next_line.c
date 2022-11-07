/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:22:27 by oelbouha          #+#    #+#             */
/*   Updated: 2022/11/07 12:58:22 by oelbouha         ###   ########.fr       */
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

char	**save_buff(char **array, char *buff, size_t n)
{
	char	**new_arr;
	int		i;

	new_arr = malloc((n + 1) * sizeof(char *));
	if (!new_arr)
		return (0);
	if (array)
	{
		i = -1;
		while (array[++i])
			new_arr[i] = array[i];
		free(array);
	}
	new_arr[n - 1] = ft_strdup(buff);
	new_arr[n] = NULL;
	return (new_arr);
}

char	*make_line(char **array, char *rest, size_t n)
{
	char	*line;
	int		i;

	line = malloc(n * BUFFER_SIZE + ft_strlen(rest) + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, rest, ft_strlen(rest));
	rest[0] = 0;
	i = -1;
	if (array)
	{
		while (array[++i] != NULL)
		{
			if (!ft_strchr(array[i], '\n'))
				ft_strjoin(line, array[i]);
			else if (ft_strchr(array[i], '\n'))
			{
				ft_strjoin(line, array[i]);
				copy_to_rest(rest, array[i]);
			}
			free(array[i]);
		}
		free(array);
	}
	return (line);
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
