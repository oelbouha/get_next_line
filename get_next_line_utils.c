/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:31:53 by oelbouha          #+#    #+#             */
/*   Updated: 2022/10/28 17:27:47 by oelbouha         ###   ########.fr       */
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

char    *ft_strjoin(char  *s1, char  *s2)
{
    int        i;
    int        j;

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

char *copy_to_rest(char *dest, char *src)
{
    int i;
    int j;

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

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    char    *dest;
    char    *source;

    if (dst == 0 && src == 0)
        return (0);
    dest = (char *)dst;
    source = (char *)src;
    while (n > 0)
    {
        *dest = *source;
        dest++;
        source++;
        n--;
    }
    return (dst);
}


char	**save_buff(char **array, char *buff, size_t n)
{
    char    **new_arr;
    int     i;

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
char    *make_line(char **array, char *rest, size_t n)
{
    char    *line;
    int        i;

    line = malloc(n * BUFFER_SIZE + 1);
    if (!line)
        return (NULL);
    i = ft_strlen(rest);
    ft_memcpy(line, rest, i);
    rest[0] = 0;
    line[i] = 0;
    i = 0;
    if (array)
    {
        while (array[i] != NULL)
        {
            if (!ft_strchr(array[i], '\n'))
                ft_strjoin(line, array[i]);
            else if (ft_strchr(array[i], '\n'))
            {
                ft_strjoin(line, array[i]);
                copy_to_rest(rest, array[i]);
            }
         free(array[i]);
        i++;
        }
    free(array);
    }
    return (line);
}

