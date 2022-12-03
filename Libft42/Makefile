# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleite-s < rleite-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 22:44:13 by msilva-p          #+#    #+#              #
#    Updated: 2022/12/03 04:02:36 by rleite-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c \
	    ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c \
		ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c \
		ft_tolower.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c \
		ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c \
		ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
		ft_strjoin.c ft_strmapi.c ft_strtrim.c
OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

RM		= rm -f

all:	${NAME}

${NAME}:	${OBJS}
	ar rcs $@ $^ libft.h

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

%.o: %.c
	@cc -Werror -Wextra -Wall -c $< -o $@

.PHONY:  all clean fclean re