# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achevala <achevala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 16:44:56 by achevala          #+#    #+#              #
#    Updated: 2023/02/08 13:45:38 by achevala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c 
OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	ar rc ${NAME} $^

%.o : %.c
	gcc ${CFLAGS} -o $@ -c $<

bonus : ${OBJ} ${OBJ_BONUS}
	ar rc ${NAME} $^
clean :
	rm -f ${OBJ} ${OBJ_BONUS}

fclean : clean
	rm -f ${NAME}
re : fclean all

.PHONY: all clean fclean re bonus
