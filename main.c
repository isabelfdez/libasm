/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:34:52 by isfernan          #+#    #+#             */
/*   Updated: 2020/09/23 19:47:53 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

//int     ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(char *str1, char *str2);

int     main()
{
	int fd;
	char dst[6] = "holap\0";
	char str[5] = "holb\0";
	char *s = "hola";
	//dst = malloc(sizeof(char) * 5);
	//printf("%i\n", ft_strlen("hola"));
	//printf("%i\n", ft_strcmp(dst, str));
	fd = open("test.txt", O_WRONLY);
	write(fd, s, 3);
}
