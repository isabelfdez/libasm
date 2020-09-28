# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 16:59:01 by isfernan          #+#    #+#              #
#    Updated: 2020/09/28 20:59:10 by isfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_strcmp.s		ft_strcpy.s		ft_strdup.s \
		ft_strlen.s		ft_write.s		ft_read.s

OBJS = ${SRCS:.s=.o}

NAME = libasm.a

FLAGS = -Wall -Werror -Wextra

%.o:		%.s
				-@nasm -g -f macho64 $<

$(NAME): 	$(OBJS)
				-@ar rc $(NAME) $(OBJS)
				-@ranlib $(NAME)

all: 		$(NAME)

clean:
				-@rm -f $(OBJS)

fclean: 	clean
				-@rm -f $(NAME) libasm

re:			fclean all

test:		clean $(OBJS)
				-@gcc -g $(FLAGS) main.c $(OBJS) -o libasm && ./libasm

.PHONY: all clea fclean re
