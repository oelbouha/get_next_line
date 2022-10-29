/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:32 by oelbouha          #+#    #+#             */
/*   Updated: 2022/10/29 18:53:53 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 300
# endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char    *get_next_line(int fd);
char	**save_buff(char **array, char *buff, size_t n);
char    *make_line(char **array, char *rest, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char    *ft_strncpy(char *dst, char *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
