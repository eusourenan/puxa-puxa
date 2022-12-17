/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentos_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:10:58 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/17 19:53:24 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *a)
{
	int	aux;

	if (a->last <= 0)
	{
		return ;
	}
	aux = a->numbers[0];
	a->numbers[0] = a->numbers[1];
	a->numbers[1] = aux;
	aux = a->indexes[0];
	a->indexes[0] = a->indexes[1];
	a->indexes[1] = aux;
	ft_printf("sa\n");
}

void	ft_rotate_a(t_stack *a)
{
	int	aux_numbers;
	int	aux_indexes;
	int	i;

	if (a->last <= 0)
	{
		return ;
	}
	i = 0;
	aux_numbers = a->numbers[0];
	aux_indexes = a->indexes[0];
	while (i < a->last)
	{
		a->numbers[i] = a->numbers[i + 1];
		a->indexes[i] = a->indexes[i + 1];
		i++;
	}
	a->numbers[i] = aux_numbers;
	a->indexes[i] = aux_indexes;
	ft_printf("ra\n");
}

void	ft_reverse_rotate_a(t_stack *a)
{
	int	aux_numbers;
	int	aux_indexes;
	int	i;

	if (a->last <= 0) //if para verificar se é possível fazer o movimento 
	{
		return ;
	}
	i = a->last;
	aux_numbers = a->numbers[i];
	aux_indexes = a->indexes[i];
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		a->indexes[i] = a->indexes[i - 1];
		i--;
	}
	a->numbers[i] = aux_numbers;
	a->indexes[i] = aux_indexes;
	ft_printf("rra\n");
}

void	ft_push_a(t_stack *b, t_stack *a)
{
	int	i;

	if (b->last < 0) //se a pilha estiver vazia, o last elemento dela vale -1 (não tem nenhum caracter)
	{
		return ;
	}
	i = a->last + 1;
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1]; //cada posição vai receber a posição(valor dela) acima
		a->indexes[i] = a->indexes[i - 1];
		i--;
	}
	a->numbers[0] = b->numbers[0];
	a->indexes[0] = b->indexes[0];
	while (i < b->last)
	{
		b->numbers[i] = b->numbers[i + 1];
		b->indexes[i] = b->indexes[i + 1];
		i++;
	}
	b->last = b->last - 1;
	a->last = a->last + 1;
	ft_printf("pa\n");
}
