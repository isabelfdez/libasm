/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:34:52 by isfernan          #+#    #+#             */
/*   Updated: 2020/09/28 20:40:45 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int     ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(char *str1, char *str2);
ssize_t	ft_write(int fd, const void *buff, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);


void	check_ft_read();

int     main()
{
	int		fd;
	int		rlibc;
	int		rlibasm;
	char    *buff;
	char	buffer[900];

    buff = malloc(sizeof(char) * 1);
	printf(ANSI_COLOR_GREEN "####################### FT_STRLEN ##########################\n" ANSI_COLOR_RESET);
	printf("str = %s \nstrlen: %lu  ft_strlen: %i\n", NULL, strlen(""), ft_strlen(""));
	printf("------------------------------------------------------------\n");
	printf("str = %s \nstrlen: %lu  ft_strlen: %i\n", "Hola Mundo!", strlen("Hola Mundo!"), ft_strlen("Hola Mundo!"));
	printf("------------------------------------------------------------\n");
	printf("str = %s \nstrlen: %lu  ft_strlen: %i\n", "0123456789", strlen("0123456789"), ft_strlen("0123456789"));
	printf("------------------------------------------------------------\n\n");
	printf(ANSI_COLOR_GREEN "####################### FT_STRCMP ##########################\n" ANSI_COLOR_RESET);
	printf("str1 = %s str2 = %s\n", NULL, NULL);
	printf("strcmp: %i  ft_strcmp: %i\n", strcmp("",  ""), ft_strcmp("", ""));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s str2 = %s\n", "hola", "hola");
	printf("strcmp: %i  ft_strcmp: %i\n", strcmp("hola",  "hola"), ft_strcmp("hola", "hola"));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s str2 = %s\n", "hola mundo", "hola");
	printf("strcmp: %i  ft_strcmp: %i\n", strcmp("hola mundo",  "hola"), ft_strcmp("hola mundo", "hola"));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s str2 = %s\n", "hola", "hola buenas");
	printf("strcmp: %i  ft_strcmp: %i\n", strcmp("hola",  "hola buenas"), ft_strcmp("hola", "hola buenas"));
	printf("------------------------------------------------------------\n\n");
	printf(ANSI_COLOR_GREEN "####################### FT_STRDUP ##########################\n" ANSI_COLOR_RESET);
	printf("str = %s\nstrdup = %s  ft_strdup = %s\n", NULL, strdup(""), ft_strdup(""));
	printf("------------------------------------------------------------\n");
	printf("str = %s\nstrdup = %s  ft_strdup = %s\n", "AmongUs", strdup("AmongUs"), ft_strdup("AmongUs"));
	printf("------------------------------------------------------------\n");
	printf("str = %s\nstrdup = %s  ft_strdup = %s\n", "coronavirus :(", strdup("coronavirus :("), ft_strdup("coronavirus :("));
	printf("------------------------------------------------------------\n");
	printf("str = %s\n\nstrdup =\n%s\nft_strdup =\n%s\n", "Sea f una función continua en un intervalo cerrado [a, b] y toma valores de signo contrario en los extremos, entonces existe al menos un c ∈ (a, b) tal que f(c) = 0.",
		strdup("Sea f una función continua en un intervalo cerrado [a, b] y toma valores de signo contrario en los extremos, entonces existe al menos un c ∈ (a, b) tal que f(c) = 0."),
		ft_strdup("Sea f una función continua en un intervalo cerrado [a, b] y toma valores de signo contrario en los extremos, entonces existe al menos un c ∈ (a, b) tal que f(c) = 0."));
	printf("------------------------------------------------------------\n\n");
	printf(ANSI_COLOR_GREEN "####################### FT_STRCPY ##########################\n" ANSI_COLOR_RESET);
	printf("str = %s\nstrcpy = %s  ft_strcpy = %s\n", "Hola Mundo", strcpy(buff, "Hola Mundo"), ft_strcpy(buff, "Hola Mundo"));
	printf("------------------------------------------------------------\n");
	printf("str = %s\n\nstrcpy =\n%s\nft_strcpy =\n%s\n", "Si de verdad les interesa lo que voy a contarles, lo primero que querrán saber es dónde nací, cómo fue todo ese rollo de mi infancia, qué hacían mis padres antes de tenerme a mí, y demás puñetas estilo David Copperfield, pero no tengo ganas de contarles nada de eso.",
		strcpy(buff, "Si de verdad les interesa lo que voy a contarles, lo primero que querrán saber es dónde nací, cómo fue todo ese rollo de mi infancia, qué hacían mis padres antes de tenerme a mí, y demás puñetas estilo David Copperfield, pero no tengo ganas de contarles nada de eso."),
		ft_strcpy(buff, "Si de verdad les interesa lo que voy a contarles, lo primero que querrán saber es dónde nací, cómo fue todo ese rollo de mi infancia, qué hacían mis padres antes de tenerme a mí, y demás puñetas estilo David Copperfield, pero no tengo ganas de contarles nada de eso."));
	printf("------------------------------------------------------------\n");
	printf(ANSI_COLOR_GREEN "######################## FT_READ ###########################\n" ANSI_COLOR_RESET);
	check_ft_read();
	printf(ANSI_COLOR_YELLOW "====================== Open field try =====================>\n" ANSI_COLOR_RESET);
	fd = open("hola.txt", O_RDONLY);
	rlibc = read(fd, buff, 50);
	rlibasm = ft_read(fd, buff, 50);
	printf("read: %d  ft_read: %d\n", rlibc, rlibasm);
	close(fd);
	free(buff);
	printf("------------------------------------------------------------\n");
	printf(ANSI_COLOR_YELLOW "========================= Text try ========================>\n" ANSI_COLOR_RESET);
	fd = open("hola.txt", O_RDONLY);
	rlibc = read(fd, buffer, 50);
	printf("read: %d", rlibc);
	close(fd);
	fd = open("hola.txt", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 50);
	printf("ft_read: %d", rlibasm);
	close(fd);



    /*fd = open("hola.txt", O_RDONLY);
    ft_read(fd, buff, 10000);
    //buff[10] = '\0';
    printf("%s\n", buff);*/
}

void	check_ft_read()
{
	char	buffer[900];
	int 	fd;
	int 	rlibc;
	int		rlibasm;
	printf("\n\n====================================\n");
	printf("============== FT_READ =============\n");
	printf("====================================\n\n");
	printf("====Open field try ====>\n");
	printf("\n");
	fd = open("main.c", O_RDONLY);
	rlibc = read(fd, buffer, 50);
	rlibasm = ft_read(fd, buffer, 50);
	printf("%-20s: \"%d\"\n", "libc", rlibc);	
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);
	close(fd);
	printf("\n");
	printf("====Text try ====>\n");
	printf("\n");
	fd = open("hola", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "libc", rlibc);
	close(fd);
	
	fd = open("hola", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);
	close(fd);	
	
	printf("====Crash try ====>\n");
	printf("\n");
	fd = open("wrong", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	perror("read errno");
	printf("%-20s: \"%d\"\n", "libc", rlibc);	
	close(fd);
	printf("\n");	
	errno = 100;
	fd = open("wrong", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	perror("ft_read errno");
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);
	close(fd);
	printf("\n");
	
	printf("====Screen try ====>\n");
	printf("\n");
	rlibc = read(0, buffer, 890);
	printf("%-20s: \"%d\"\n", "libc", rlibc);	
	close(fd);
	printf("\n");	
	rlibasm = ft_read(0, buffer, 890);
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);
	close(fd);
}
