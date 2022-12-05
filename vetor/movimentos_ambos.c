
#include "push_swap.h"

void	ft_swap_swap(t_lista *pilha_a, t_lista *pilha_b)
{
	if (pilha_a->topo < 1 || pilha_b->topo < 1)
	{
		// deu ruim
		return ;
	}
	ft_swap_a(pilha_a);
	ft_swap_b(pilha_b);
}

void	ft_rotate_rotate(t_lista *pilha_a, t_lista *pilha_b)
{
	if (pilha_a->topo < 1 || pilha_b->topo < 1)
	{
		// deu ruim
		return ;
	}
	ft_rotate_a(pilha_a);
	ft_rotate_b(pilha_b);
}

void	ft_reverse_rotate_rotate(t_lista *pilha_a, t_lista *pilha_b)
{
	if (pilha_a->topo < 1 || pilha_b->topo < 1)
	{
		// deu ruim
		return ;
	}
	ft_reverse_rotate_a(pilha_a);
	ft_reverse_rotate_b(pilha_b);
}
