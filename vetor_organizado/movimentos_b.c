
#include "push_swap.h"

void	ft_swap_b(t_lista *pilha_b)
{
	int	auxiliar;

	if (pilha_b->topo < 0)
	{
		// deu ruim
		return ;
	}
	auxiliar = pilha_b->numeros[pilha_b->topo];
	pilha_b->numeros[pilha_b->topo] = pilha_b->numeros[pilha_b->topo + 1];
	pilha_b->numeros[pilha_b->topo + 1] = auxiliar;
	
	auxiliar = pilha_b->indexes[pilha_b->topo];
	pilha_b->indexes[pilha_b->topo] = pilha_b->indexes[pilha_b->topo + 1];
	pilha_b->indexes[pilha_b->topo + 1] = auxiliar;
}

void	ft_rotate_b(t_lista *pilha_b)
{
	int	auxiliar[2];
	int	i;

	if (pilha_b->topo < 0)
	{
		// deu ruim
		return ;
	}
	i = pilha_b->topo;
	auxiliar[0] = pilha_b->numeros[pilha_b->topo];
	auxiliar[1] = pilha_b->indexes[pilha_b->topo];
	while (i < pilha_b->ultimo)
	{
		pilha_b->numeros[i] = pilha_b->numeros[i + 1];
		pilha_b->indexes[i] = pilha_b->indexes[i + 1];
		i++;
	}
	pilha_b->numeros[i] = auxiliar[0];
	pilha_b->indexes[i] = auxiliar[1];
}

void	ft_reverse_rotate_b(t_lista *pilha_b)
{
	int	auxiliar[2];
	int	i;

	if (pilha_b->topo < 0)
	{
		// deu ruim
		return ;
	}
	i = pilha_b->ultimo;
	auxiliar[0] = pilha_b->numeros[pilha_b->ultimo];
	auxiliar[1] = pilha_b->indexes[pilha_b->ultimo];
	while (i > pilha_b->topo)
	{
		pilha_b->numeros[i] = pilha_b->numeros[i - 1];
		pilha_b->indexes[i] = pilha_b->indexes[i - 1];
		i--;
	}
	pilha_b->numeros[i] = auxiliar[0];
	pilha_b->indexes[i] = auxiliar[1];
}

void	ft_push_b(t_lista *pilha_b, t_lista *pilha_a)
{
	if (pilha_a->topo < 0)
	{
		// deu ruim
		return;
	}
	if (pilha_b->topo < 0)
		pilha_b->topo = pilha_b->topo * -1;
	pilha_b->numeros[--pilha_b->topo] = pilha_a->numeros[pilha_a->topo++];
	pilha_b->indexes[pilha_b->topo] = pilha_a->indexes[pilha_a->topo + 1];
	if (pilha_a->topo > pilha_a->ultimo)
		pilha_a->topo = pilha_a->topo * -1;
}
