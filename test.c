/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 19:35:31 by isfernan          #+#    #+#             */
/*   Updated: 2020/09/25 19:45:53 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char    *buff;
    int     fd;

    buff = malloc(sizeof(char) * 1);
    fd = open("hola.txt", O_RDONLY);
    read(fd, buff, 10000);
    //buff[10] = '\0';
    printf("%s\n", buff);
}

