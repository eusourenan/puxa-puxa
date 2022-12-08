

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft42/libft.h"
# include "defines.h"
	#include <stdio.h>

struct s_lista
{
	int	*numeros;
	int	*indexes;
	int	topo;
	int	ultimo;
};

typedef struct s_lista t_lista;

void	free_matrix(char **matrix);

void	ft_swap_a(t_lista *pilha_a);
void	ft_rotate_a(t_lista *pilha_a);
void	ft_reverse_rotate_a(t_lista *pilha_a);
void	ft_push_a(t_lista *pilha_a, t_lista *pilha_b);

void	ft_swap_b(t_lista *pilha_b);
void	ft_rotate_b(t_lista *pilha_b);
void	ft_reverse_rotate_b(t_lista *pilha_b);
void	ft_push_b(t_lista *pilha_b, t_lista *pilha_a);

void	ft_swap_swap(t_lista *pilha_a, t_lista *pilha_b);
void	ft_rotate_rotate(t_lista *pilha_a, t_lista *pilha_b);
void	ft_reverse_rotate_rotate(t_lista *pilha_a, t_lista *pilha_b);

void	teste(t_lista *pilha_a, t_lista *pilha_b);

void	ft_checar_caso(t_lista *pilha_a, t_lista *pilha_b, int numeros);

void	print_pilhas(t_lista *pilha_a, t_lista *pilha_b, int qtd);

#endif