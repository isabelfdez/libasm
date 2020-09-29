/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:34:52 by isfernan          #+#    #+#             */
/*   Updated: 2020/09/29 17:37:36 by isfernan         ###   ########.fr       */
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
void	check_ft_write();

int     main()
{
	char    *buff;

    buff = malloc(sizeof(char) * 1);
	printf(ANSI_COLOR_GREEN "####################### FT_STRLEN ##########################\n" ANSI_COLOR_RESET);
	printf("str = \"%s\" \n", "");
	printf("%-20s: \"%lu\"\n", "strlen",  strlen(""));
	printf("%-20s: \"%d\"\n", "ft_strlen",  ft_strlen(""));
	printf("------------------------------------------------------------\n");
	printf("str = \"%s\" \n", "Hola Mundo!");
	printf("%-20s: \"%lu\"\n", "strlen",  strlen("Hola Mundo!"));
	printf("%-20s: \"%d\"\n", "ft_strlen",  ft_strlen("Hola Mundo!"));
	printf("------------------------------------------------------------\n");
	printf("str = \"%s\" \n", "0123456789");
	printf("%-20s: \"%lu\"\n", "strlen",  strlen("0123456789"));
	printf("%-20s: \"%d\"\n", "ft_strlen",  ft_strlen("0123456789"));
	printf("------------------------------------------------------------\n\n");
	printf(ANSI_COLOR_GREEN "####################### FT_STRCMP ##########################\n" ANSI_COLOR_RESET);
	printf("str1 = \"%s\"\nstr2 = \"%s\"\n", "", "");
	printf("%-20s: \"%d\"\n", "strcmp",  strcmp("",  ""));
	printf("%-20s: \"%d\"\n", "ft_strcmp",  ft_strcmp("",  ""));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s\nstr2 = %s\n", "hola", "hola");
	printf("%-20s: \"%d\"\n", "strcmp",  strcmp("hola",  "hola"));
	printf("%-20s: \"%d\"\n", "ft_strcmp",  ft_strcmp("hola",  "hola"));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s\nstr2 = %s\n", "hola mundo", "hola");
	printf("%-20s: \"%d\"\n", "strcmp",  strcmp("hola mundo",  "hola"));
	printf("%-20s: \"%d\"\n", "ft_strcmp",  ft_strcmp("hola mundo",  "hola"));
	printf("------------------------------------------------------------\n");
	printf("str1 = %s\nstr2 = %s\n", "hola", "hola buenas");
	printf("%-20s: \"%d\"\n", "strcmp",  strcmp("hola",  "hola buenas"));
	printf("%-20s: \"%d\"\n", "ft_strcmp",  ft_strcmp("hola",  "hola buenas"));
	printf("------------------------------------------------------------\n\n");
	printf(ANSI_COLOR_GREEN "####################### FT_STRDUP ##########################\n" ANSI_COLOR_RESET);
	printf("str = \"%s\" \n", "");
	printf("%-20s: \"%s\"\n", "strdup",  strdup(""));
	printf("%-20s: \"%s\"\n", "ft_strdup",  ft_strdup(""));
	printf("------------------------------------------------------------\n");
	printf("str = %s \n", "AmongUs");
	printf("%-20s: \"%s\"\n", "strdup",  strdup("AmongUs"));
	printf("%-20s: \"%s\"\n", "ft_strdup",  ft_strdup("AmongUs"));
	printf("------------------------------------------------------------\n");
	printf("str = %s \n", "coronavirus :(");
	printf("%-20s: \"%s\"\n", "strdup",  strdup("coronavirus :("));
	printf("%-20s: \"%s\"\n", "ft_strdup",  ft_strdup("coronavirus :("));
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
	printf("------------------------------------------------------------\n\n");
	check_ft_read();
	check_ft_write();
}

void	check_ft_read()
{
	int		fd;
	int		rlibc;
	int		rlibasm;
	char	buffer[900];

	printf(ANSI_COLOR_GREEN "######################## FT_READ ###########################\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_YELLOW "====================== Open field try =====================>\n" ANSI_COLOR_RESET);
	fd = open("main.c", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "read", rlibc);
	close(fd);
	fd = open("main.c", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "ft_read", rlibasm);
	close(fd);
	printf("------------------------------------------------------------\n");
	printf(ANSI_COLOR_YELLOW "========================= Text try ========================>\n" ANSI_COLOR_RESET);
	fd = open("hola.txt", O_RDONLY);
	rlibc = read(fd, buffer, 50);
	close(fd);
	printf("%-20s: \"%d\"\n", "read", rlibc);
	fd = open("hola.txt", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 50);
	printf("%-20s: \"%d\"\n", "ft_read", rlibc);
	close(fd);
	printf("------------------------------------------------------------\n");
	printf(ANSI_COLOR_YELLOW "======================== Crash try ========================>\n" ANSI_COLOR_RESET);
	printf("\n");
	fd = open("wrong", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	perror("read errno");
	printf("%-20s: \"%d\"\n", "read", rlibc);
	close(fd);
	printf("\n");	
	errno = 100;
	fd = open("wrong", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	perror("ft_read errno");
	printf("%-20s: \"%d\"\n", "ft_read", rlibasm);
	close(fd);
	printf("\n");
	printf("------------------------------------------------------------\n");
	printf(ANSI_COLOR_YELLOW "======================== Screen try =======================>\n" ANSI_COLOR_RESET);
	printf("\n");
	rlibc = read(0, buffer, 890);
	printf("%-20s: \"%d\"\n", "read", rlibc);	
	close(fd);
	printf("\n");	
	rlibasm = ft_read(0, buffer, 890);
	printf("%-20s: \"%d\"\n", "ft_read", rlibasm);
	close(fd);
	printf("------------------------------------------------------------\n\n");

}

void	check_ft_write()
{
	char	buffer[604] = "In measure theory, a branch of mathematics, the Lebesgue measure, named after French mathematician Henri Lebesgue,\nis the standard way of assigning a measure to subsets of n-dimensional Euclidean space. For n = 1, 2, or 3, it\ncoincides with the standard measure of length, area, or volume. In general, it is also called n-dimensional\nvolume, n-volume, or simply volume.[1] It is used throughout real analysis, in particular to define Lebesgue\nintegration. Sets that can be assigned a Lebesgue measure are called Lebesgue-measurable; the measure of the\nLebesgue-measurable set A is here denoted by λ(A).";
	int 	fd;
	int 	rlibc;
	int		rlibasm;

	printf(ANSI_COLOR_GREEN "######################## FT_WRITE ##########################\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_YELLOW "========================= Text try ========================>\n" ANSI_COLOR_RESET);
	fd = open("write.txt", O_WRONLY);
	rlibc = write(fd, buffer, 603);
	printf("%-20s: \"%d\"\n", "write", rlibc);		
	close(fd);
	
	fd = open("write.txt", O_WRONLY);
	rlibasm = ft_write(fd, buffer, 603);
	printf("%-20s: \"%d\"\n", "ft_write", rlibasm);	
	close(fd);
	printf("------------------------------------------------------------\n");

	printf(ANSI_COLOR_YELLOW "======================== Crash try ========================>\n" ANSI_COLOR_RESET);
	fd = open("wrong", O_WRONLY);
	rlibc = write(fd, buffer, 603);
	perror("write errno");
	printf(ANSI_COLOR_RESET "%-20s: \"%d\"\n", "write", rlibc);	
	close(fd);
	printf("\n");
	
	errno = 100;
	fd = open("wrong", O_WRONLY);
	rlibasm = ft_write(fd, buffer, 603);
	perror("ft_write errno");
	printf("%-20s: \"%d\"\n", "ft_write", rlibasm);	
	close(fd);
	printf("------------------------------------------------------------\n");
	
	printf(ANSI_COLOR_YELLOW "======================== Screen try =======================>\n" ANSI_COLOR_RESET);
	printf("\n");
	rlibc = write(1, buffer, 603);
	printf("\n%-20s: \"%d\"\n\n", "write", rlibc);
	close(fd);
	
	rlibasm = ft_write(1, buffer, 603); 
	printf("\n%-20s: \"%d\"\n", "ft_write", rlibasm);	
	close(fd);	
	printf("\n");
}
