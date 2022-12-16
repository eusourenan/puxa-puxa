
#include "push_swap.h"

void	ft_swap_b(t_lista *pilha_b)
{
	int	auxiliar;

	if (pilha_b->ultimo <= 0)
	{
		// deu ruim
		return ;
	}
	auxiliar = pilha_b->numeros[0];
	pilha_b->numeros[0] = pilha_b->numeros[1];
	pilha_b->numeros[1] = auxiliar;
	
	auxiliar = pilha_b->indexes[0];
	pilha_b->indexes[0] = pilha_b->indexes[1];
	pilha_b->indexes[1] = auxiliar;
}

void	ft_rotate_b(t_lista *pilha_b)
{
	int	auxiliar_indexes;
	int auxiliar_numeros;
	int	i;

	if (pilha_b->topo <= 0)
	{
		// deu ruim
		return ;
	}
	i = 0;
	auxiliar_numeros = pilha_b->numeros[0];
	auxiliar_indexes = pilha_b->indexes[0];
	while (i < pilha_b->ultimo)
	{
		pilha_b->numeros[i] = pilha_b->numeros[i + 1];
		pilha_b->indexes[i] = pilha_b->indexes[i + 1];
		i++;
	}
	pilha_b->numeros[i] = auxiliar_numeros;
	pilha_b->indexes[i] = auxiliar_indexes;
}

void	ft_reverse_rotate_b(t_lista *pilha_b)
{
	int	auxiliar_numeros;
	int auxiliar_indexes;
	int	i;

	if (pilha_b->topo <= 0)
	{
		// deu ruim
		return ;
	}
	i = pilha_b->ultimo;
	auxiliar_numeros = pilha_b->numeros[i];
	auxiliar_indexes = pilha_b->indexes[i];
	while (i > 0)
	{
		pilha_b->numeros[i] = pilha_b->numeros[i - 1];
		pilha_b->indexes[i] = pilha_b->indexes[i - 1];
		i--;
	}
	pilha_b->numeros[i] = auxiliar_numeros;
	pilha_b->indexes[i] = auxiliar_indexes;
}

void	ft_push_b(t_lista *pilha_b, t_lista *pilha_a)
{
	int i;
	 
	if (pilha_a->ultimo < 0) //se a pilha estiver vazia, o ultimo elemento dela vale -1 (não tem nenhum caracter) (então é menor que zero)
	{
		// deu ruim
		return;
	}
	i = pilha_b->ultimo + 1; //quantidade de caracteres da pilha b + 1
	while (i > 0)
	{
		pilha_b->numeros[i] = pilha_b->numeros[i - 1]; //cada posição vai receber a posição (valor que está nela) acima (4 recebe 3/ 3 recebe 2 / 2 recebe 1 / 1 recebe 0)
		pilha_b->indexes[i] = pilha_b->indexes[i - 1];
		i--;
	}
	pilha_b->numeros[0] = pilha_a->numeros[0]; //o topo de b recebe o topo de a
	pilha_b->indexes[0] = pilha_a->indexes[0]; //mesma coisa nos dois vetores
	while (i < pilha_a->ultimo) // se i(está valendo zero se chegou aqui) for menor que o último da pilha a = topo de a tem que estar vazio pra ser atualizado com o novo valor
	{
		pilha_a->numeros[i] = pilha_a>numeros[i + 1]; //cada posição vai receber a posição (valor que está nela) abaixo (0 recebe 1/ 1 recebe 2 / 2 recebe 3 / 3 recebe 4)
		pilha_a->indexes[i] = pilha_a->indexes[i + 1];
		i++;
	}
	pilha_a->ultimo = pilha_a->ultimo - 1;
	pilha_b->ultimo = pilha_b->ultimo + 1;
}
