/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:31:53 by oelbouha          #+#    #+#             */
/*   Updated: 2022/10/29 18:52:45 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\n' && s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] == '\n')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

char	*copy_to_rest(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (src[i] != '\n')
		i++;
	i++;
	j = 0;
	while (src[i])
	{
		dest[j] = src[i];
		j++;
	i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t		i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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

	line = malloc(n * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, rest, ft_strlen(rest));
	*rest = 0;
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
