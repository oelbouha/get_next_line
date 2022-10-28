/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:22:27 by oelbouha          #+#    #+#             */
/*   Updated: 2022/10/28 17:22:39 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*check_rest(char *rest)
{
	char 	*line;
	int		i;

		i = 0;
		while (rest[i] != '\n')
			i++;
		i++;
		line = malloc(i + 1);
		ft_memcpy(line, rest, i);
		line[i] = 0;
		ft_memcpy(rest, &rest[i], ft_strlen(rest) - i + 1);
		return (line);
}

char *get_next_line(int fd)
{	
	char 			buff[BUFFER_SIZE + 1];
	static char		rest[BUFFER_SIZE];
	char			**str;
	int				r;
	int				n;

	if (ft_strchr(rest, '\n'))
		return (check_rest(rest));
	n = 0;
	str = NULL;
	while (++n)
	{
		r = read (fd, buff, BUFFER_SIZE);
		if (r == 0 && rest[0])
			break;
		if (r < 0 || (r == 0 && str == NULL))
			return (0);
		buff[r] = 0;
		str = save_buff(str, buff, n); 
		if (!str)
			return (0);
		if (ft_strchr(buff, '\n') || r < BUFFER_SIZE )
			break;
	}
	return (make_line(str, rest, n));
}

// int main ()
// {
// 	int fd1 = open("file1.txt", O_RDWR);
// 	int fd2 = open("file2.txt", O_CREAT | O_RDWR);
// 	int fd3 = open("file3.txt", O_CREAT |O_RDWR);
// // // 	// char *s = get_next_line(fd);
// // // 	// while (s)
// // // 	// {
// // // 	// 	printf("line :====> %s", s);
// // // 	// 	free (s);
// // // 	// 	s = get_next_line(fd);
// // // 	// }
// // // 	// s = get_next_line(fd);
// // // 	// printf("%s", s);
// // // 	// free(s);
// 	printf("line : ====> %s\n", get_next_line_bonus(fd1));
// 	printf("line : ====> %s\n", get_next_line_bonus(fd2));
// 	printf("line : ====> %s\n", get_next_line_bonus(fd3));
// 	printf("line : ====> %s\n", get_next_line_bonus(fd1));
// 	// printf("line : ====> %s\n", get_next_line(fd));
// 	// printf("line : ====> %s\n", get_next_line(fd));
// 	// printf("line : ====> %s\n", get_next_line(fd));
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// }



