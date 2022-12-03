
NAME		=	push_swap

LIBFT		=	../Libft42/libft.a

ARQUIVOS	=	main.c movimentos_a.c movimentos_ambos.c movimentos_b.c teste.c
OBJETOS		=	$(ARQUIVOS:%.c=%.o)

CFLAGS		=	-Wall -Werror -Wextra

%.o: %.c
	cc -c $< -o $@

all: $(NAME)

$(NAME): $(OBJETOS) $(LIBFT)
	cc $^ -o $@

$(LIBFT):
	make -C ../Libft42

clean:
	rm -f $(OBJETOS)

fclean: clean
	make fclean -C ../Libft42
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re