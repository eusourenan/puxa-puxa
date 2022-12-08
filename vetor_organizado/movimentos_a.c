
#include "push_swap.h"

void	ft_swap_a(t_lista *pilha_a)
{
	int	auxiliar;

	if (pilha_a->topo < 0)
	{
		// deu ruim
		return ;
	}
	auxiliar = pilha_a->numeros[pilha_a->topo];
	pilha_a->numeros[pilha_a->topo] = pilha_a->numeros[pilha_a->topo + 1];
	pilha_a->numeros[pilha_a->topo + 1] = auxiliar;
	
	auxiliar = pilha_a->indexes[pilha_a->topo];
	pilha_a->indexes[pilha_a->topo] = pilha_a->indexes[pilha_a->topo + 1];
	pilha_a->indexes[pilha_a->topo + 1] = auxiliar;
}

void	ft_rotate_a(t_lista *pilha_a)
{
	int	auxiliar[2];
	int	i;

	if (pilha_a->topo < 0)
	{
		// deu ruim
		return ;
	}
	i = pilha_a->topo;
	auxiliar[0] = pilha_a->numeros[pilha_a->topo];
	auxiliar[1] = pilha_a->indexes[pilha_a->topo];
	while (i < pilha_a->ultimo)
	{
		pilha_a->numeros[i] = pilha_a->numeros[i + 1];
		pilha_a->indexes[i] = pilha_a->indexes[i + 1];
		i++;
	}
	pilha_a->numeros[i] = auxiliar[0];
	pilha_a->indexes[i] = auxiliar[1];
}

void	ft_reverse_rotate_a(t_lista *pilha_a)
{
	int	auxiliar[2];
	int	i;

	if (pilha_a->topo < 0)
	{
		// deu ruim
		return ;
	}
	i = pilha_a->ultimo;
	auxiliar[0] = pilha_a->numeros[pilha_a->ultimo];
	auxiliar[1] = pilha_a->indexes[pilha_a->ultimo];
	while (i > pilha_a->topo)
	{
		pilha_a->numeros[i] = pilha_a->numeros[i - 1];
		pilha_a->indexes[i] = pilha_a->indexes[i - 1];
		i--;
	}
	pilha_a->numeros[i] = auxiliar[0];
	pilha_a->indexes[i] = auxiliar[1];
}

void	ft_push_a(t_lista *pilha_a, t_lista *pilha_b)
{
	if (pilha_b->topo < 0)
	{
		// deu ruim
		return;
	}
	if (pilha_a->topo < 0)
		pilha_a->topo = pilha_a->topo * -1;
	pilha_a->numeros[--pilha_a->topo] = pilha_b->numeros[pilha_b->topo++];
	pilha_a->indexes[pilha_a->topo] = pilha_b->indexes[pilha_b->topo - 1];
	if (pilha_b->topo > pilha_b->ultimo)
		pilha_b->topo = pilha_b->topo * -1;
}
