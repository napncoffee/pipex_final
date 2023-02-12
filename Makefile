# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achevala <achevala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 20:42:54 by achevala          #+#    #+#              #
#    Updated: 2023/01/30 17:58:57 by achevala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = main.c\
		pipex.c\
		parsing.c\
		cmd.c\
		error.c\
		utils.c\
		
OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g

INC = -I./pipex.h

SRC_BONUS = \

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all : ${NAME}

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./printf
	$(CC) ${CFLAGS} $(OBJ) -L./libft -lft -L./printf -lprintf -o $(NAME)

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJ} ${OBJ_BONUS}
	make clean -C ./libft
	make clean -C ./printf


fclean : clean
	make fclean -C ./libft
	make fclean -C ./printf
	rm -f ${NAME}
	
re : fclean all

.PHONY: all clean fclean re bonus
