
#include "push_swap.h"

void	ft_swap_a(t_lista *pilha_a)
{
	int	auxiliar;

	if (pilha_a->ultimo <= 0)
	{
		// deu ruim
		return ;
	}
	auxiliar = pilha_a->numeros[0];
	pilha_a->numeros[0] = pilha_a->numeros[1];
	pilha_a->numeros[1] = auxiliar;
	
	auxiliar = pilha_a->indexes[0];
	pilha_a->indexes[0] = pilha_a->indexes[1];
	pilha_a->indexes[1] = auxiliar;
}

void	ft_rotate_a(t_lista *pilha_a)
{
	int	auxiliar_numeros;
	int auxiliar_indexes;
	int	i;

	if (pilha_a->ultimo <= 0)
	{
		// deu ruim
		return ;
	}
	i = 0;
	auxiliar_numeros = pilha_a->numeros[0];
	auxiliar_indexes = pilha_a->indexes[0];
	while (i < pilha_a->ultimo)
	{
		pilha_a->numeros[i] = pilha_a->numeros[i + 1];
		pilha_a->indexes[i] = pilha_a->indexes[i + 1];
		i++;
	}
	pilha_a->numeros[i] = auxiliar_numeros;
	pilha_a->indexes[i] = auxiliar_indexes;
}

void	ft_reverse_rotate_a(t_lista *pilha_a)
{
	int	auxiliar_numeros;
	int auxiliar_indexes;
	int	i;

	if (pilha_a->ultimo <= 0) //if para verificar se é possível fazer o movimento 
	{
		// deu ruim
		return ;
	}
	i = pilha_a->ultimo;
	auxiliar_numeros = pilha_a->numeros[i];
	auxiliar_indexes = pilha_a->indexes[i];
	while (i > 0)
	{
		pilha_a->numeros[i] = pilha_a->numeros[i - 1];
		pilha_a->indexes[i] = pilha_a->indexes[i - 1];
		i--;
	}
	pilha_a->numeros[i] = auxiliar_numeros;
	pilha_a->indexes[i] = auxiliar_indexes;
}

void	ft_push_a(t_lista *pilha_a, t_lista *pilha_b)
{
	int i;
	 
	if (pilha_b->ultimo < 0) //se a pilha estiver vazia, o ultimo elemento dela vale -1 (não tem nenhum caracter)
	{
		// deu ruim
		return;
	}
	i = pilha_a->ultimo + 1;
	while (i > 0)
	{
		pilha_a->numeros[i] = pilha_a->numeros[i - 1]; //cada posição vai receber a posição(valor dela) acima
		pilha_a->indexes[i] = pilha_a->indexes[i - 1];
		i--;
	}
	pilha_a->numeros[0] = pilha_b->numeros[0];
	pilha_a->indexes[0] = pilha_b->indexes[0];
	while (i < pilha_b->ultimo)
	{
		pilha_b->numeros[i] = pilha_b->numeros[i + 1];
		pilha_b->indexes[i] = pilha_b->indexes[i + 1];
		i++;
	}
	pilha_b->ultimo = pilha_b->ultimo - 1;
	pilha_a->ultimo = pilha_a->ultimo + 1;
}
