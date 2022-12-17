
NAME		=	push_swap

LIBFT		=	../Libft42/libft.a

ARQUIVOS	=	main.c utils.c movimentos_a.c movimentos_ambos.c movimentos_b.c\
				teste.c organizador.c
OBJETOS		=	$(ARQUIVOS:%.c=%.o)

CFLAGS		=	-Wall -Werror -Wextra

%.o: %.c
	cc -c $< -o $@

all: $(NAME)

$(NAME): libft $(OBJETOS)
	cc $(OBJETOS) $(LIBFT) -o $@

libft:
	make -C ../Libft42

clean:
	rm -f $(OBJETOS)
	make clean -C ../Libft42

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft