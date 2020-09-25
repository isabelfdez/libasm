/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:34:52 by isfernan          #+#    #+#             */
/*   Updated: 2020/09/25 19:51:39 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

int     ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(char *str1, char *str2);
ssize_t	ft_write(int fd, const void *buff, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);


int     main()
{
	int fd;
	char dst[6] = "holap\0";
	char str[5] = "holb\0";
	char	*t;
	char *s = "carai";
	//dst = malloc(sizeof(char) * 5);
	//printf("%i\n", ft_strlen("hola"));
	//printf("%i\n", ft_strcmp(dst, str));
	//fd = open("hola.txt", O_WRONLY);
	//ft_write(fd, s, 3);
	//t = ft_strdup(s);
	//printf("%s\n", t);
	char    *buff;

    buff = malloc(sizeof(char) * 1);
    fd = open("hola.txt", O_RDONLY);
    ft_read(fd, buff, 10000);
    //buff[10] = '\0';
    printf("%s\n", buff);
}
