/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentos_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:22:58 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/17 00:26:59 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_stack *b)
{
	int	aux;

	if (b->last <= 0)
	{
		// deu ruim
		return ;
	}
	aux = b->numbers[0];
	b->numbers[0] = b->numbers[1];
	b->numbers[1] = aux;
	
	aux = b->indexes[0];
	b->indexes[0] = b->indexes[1];
	b->indexes[1] = aux;
	ft_printf("sb\n");
}

void	ft_rotate_b(t_stack *b)
{
	int	aux_indexes;
	int aux_numbers;
	int	i;

	if (b->last <= 0)
	{
		// deu ruim
		return ;
	}
	i = 0;
	aux_numbers = b->numbers[0];
	aux_indexes = b->indexes[0];
	while (i < b->last)
	{
		b->numbers[i] = b->numbers[i + 1];
		b->indexes[i] = b->indexes[i + 1];
		i++;
	}
	b->numbers[i] = aux_numbers;
	b->indexes[i] = aux_indexes;
	ft_printf("rb\n");
}

void	ft_reverse_rotate_b(t_stack *b)
{
	int	aux_numbers;
	int aux_indexes;
	int	i;

	if (b->last <= 0)
	{
		// deu ruim
		return ;
	}
	i = b->last;
	aux_numbers = b->numbers[i];
	aux_indexes = b->indexes[i];
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		b->indexes[i] = b->indexes[i - 1];
		i--;
	}
	b->numbers[i] = aux_numbers;
	b->indexes[i] = aux_indexes;
	ft_printf("rrb\n");
}

void	ft_push_b(t_stack *a, t_stack *b)
{
	int i;
	 
	if (a->last < 0) //se a pilha estiver vazia, o last elemento dela vale -1 (não tem nenhum caracter) (então é menor que zero)
	{
		// deu ruim
		return;
	}
	i = b->last + 1; //quantidade de caracteres da pilha b + 1
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1]; //cada posição vai receber a posição (valor que está nela) acima (4 recebe 3/ 3 recebe 2 / 2 recebe 1 / 1 recebe 0)
		b->indexes[i] = b->indexes[i - 1];
		i--;
	}
	b->numbers[0] = a->numbers[0]; //o topo de b recebe o topo de a
	b->indexes[0] = a->indexes[0]; //mesma coisa nos dois vetores
	while (i < a->last) // se i(está valendo zero se chegou aqui) for menor que o último da pilha a = topo de a tem que estar vazio pra ser atualizado com o novo valor
	{
		a->numbers[i] = a->numbers[i + 1]; //cada posição vai receber a posição (valor que está nela) abaixo (0 recebe 1/ 1 recebe 2 / 2 recebe 3 / 3 recebe 4)
		a->indexes[i] = a->indexes[i + 1];
		i++;
	}
	a->last = a->last - 1;
	b->last = b->last + 1;
	ft_printf("pb\n");
}
