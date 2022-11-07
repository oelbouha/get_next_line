/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:31:53 by oelbouha          #+#    #+#             */
/*   Updated: 2022/10/29 16:34:41 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] && s2[j] != '\n')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] == '\n')
		s1[i++] = '\n';
	s1[i] = '\0';
	return (s1);
}

char	*copy_to_rest(char *dest, char *src)
{
	int	i;
	int	j;

	dest[0] = 0;
	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
		return(dest);
	i++;
	j = 0;
	while (src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

/*

	array = [c1, c2, ..., cn-1, 0]
	n_arr = [c1, c2, ..., cn-1, cn, 0]

	// solution 1
	size = bufferSize>min?bufferSize:min
	size = BUFFER_SIZE * (BUFFER_SIZE > MIN) + MIN * (BUFFER_SIZE < MIN);

	if arr && size - len(arr[n-1]) < len(buff) 
		concat(arr[n-1], buff, min)
	else {
		*n += 1;
		n_arr = malloc(*n + 1);
		n_arr[*n] = 0;
		if (arr)
			copy arr to n_arr and free
		i = concat(narr[n - 2], buff, size)
		concat(arr[n-1], &buff[i], size)
		}
	areturn


*/

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
	line[0] = 0;
	ft_strjoin(line, rest);
	i = -1;
	if (array)
		while (array[++i] != NULL)
				ft_strjoin(line, array[i]);
	copy_to_rest(rest, rest);
	if (n)
	{
		copy_to_rest(rest, array[i - 1]);
		free_array(array);
	}
	return (line);
}