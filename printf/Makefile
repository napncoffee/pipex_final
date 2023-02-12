# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achevala <achevala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 15:48:18 by achevala          #+#    #+#              #
#    Updated: 2022/07/11 20:41:56 by achevala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SRC = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c\
ft_putstr.c ft_putptr.c
OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
	ar rc ${NAME} $^

%.o : %.c
	gcc ${CFLAGS} -o $@ -c $<

clean :
	rm -f ${OBJ} ${OBJ_BONUS}

fclean : clean
	rm -f ${NAME}
re : fclean all

.PHONY: all clean fclean re bonus
