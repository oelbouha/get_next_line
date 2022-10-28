/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:32 by oelbouha          #+#    #+#             */
/*   Updated: 2022/10/28 17:21:36 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 30
# endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd);
char	**save_buff(char **array, char *buff, size_t n);
char    *make_line(char **array, char *rest, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void    *ft_memcpy(void *dst, const void *src, size_t n);

#endif
