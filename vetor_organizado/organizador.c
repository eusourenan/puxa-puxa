/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizador.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:58:16 by rleite-s          #+#    #+#             */
/*   Updated: 2022/12/17 18:04:25 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_executa_movimento(int movimento, t_lista *a, t_lista *b)
{
	int retorno;

	if (movimento == PA)
		retorno = ft_push_a(a, b);
	else if (movimento == PB)
		retorno = ft_push_b(b, a);
	else if (movimento == SA)
		retorno = ft_swap_a(a);
	else if (movimento == SB)
		retorno = ft_swap_b(b);
	else if (movimento == RA)
		retorno = ft_rotate_a(a);
	else if (movimento == RB)
		retorno = ft_rotate_b(b);
	else if (movimento == RRA)
		retorno = ft_reverse_rotate_a(a);
	else if (movimento == RRB)
		retorno = ft_reverse_rotate_b(b);
	else if (movimento == SS)
		retorno = ft_swap_swap(a, b);
	else if (movimento == RR)
		retorno = ft_rotate_rotate(a, b);
	else if (movimento == RRR)
		retorno = ft_reverse_rotate_rotate(a, b);
	return (retorno);	
}*/

void	ft_checker(t_stack *a, t_stack *b, int numbers)
{
	if (numbers < 3)
		ft_sort_for_3(a);
	else if (numbers < 5)
		ft_sort_for_5(a, b);
	else
		ft_sort_more_5(a, b, a->last);
}

void	ft_sort_for_3(t_stack *a)
{
	if (a->last == 1)
	{
		if (a->numbers[0] > a->numbers[1])
			ft_swap_a(a);
	}
	else if (a->numbers[0] > a->numbers[1] && a->numbers[0] > a->numbers[2])
	{
		ft_rotate_a(a);
		if (a->numbers[0] > a->numbers[1])
			ft_swap_a(a);
	}
	else if (a->numbers[1] > a->numbers[0] && a->numbers[1] > a->numbers[2])
	{
		ft_reverse_rotate_a(a);
		if (a->numbers[0] > a->numbers[1])
			ft_swap_a(a);
	}
	else if (a->numbers[2] > a->numbers[0] && a->numbers[2] > a->numbers[1])
	{
		if (a->numbers[0] > a->numbers[1])
			ft_swap_a(a);
	}
}

int	ft_ret_bigger(t_stack *a)
{
	int	number;
	int	bigger;
	int	bigger_index;

	number = a->numbers[0];
	bigger = 0;
	bigger_index = bigger;
	while (bigger <= a->last)
	{
		if (a->numbers[bigger] > number)
		{
			number = a->numbers[bigger];
			bigger_index = bigger;
		}
		bigger++;
	}
	return (bigger_index);
}

int	ft_ret_pos_smaller(t_stack *a)
{
	int	i;
	int	small_num;
	int	pos_small;

	i = 0;
	small_num = a->numbers[0];
	pos_small = 0;
	while (i <= a->last)
	{
		if (a->numbers[i] < small_num)
		{
			small_num = a->numbers[i];
			pos_small = i;
		}
		i++;
	}
	return (pos_small);
}

void	ft_sort_for_5(t_stack *a, t_stack *b)
{
	int	small_pos;

	while (a->last >= 3)
	{
		small_pos = ft_ret_pos_smaller(a);
		if (small_pos == 0)
			ft_push_b(a, b);
		else if (small_pos == 1)
			ft_swap_a(a);
		else if (small_pos == 2)
			ft_rotate_a(a);
		else if (small_pos == 3)
			ft_reverse_rotate_a(a);
		else if (small_pos == 4)
			ft_reverse_rotate_a(a);
	}
	ft_sort_for_3(a);
	while (b->last > -1)
		ft_push_a(b, a);
}

int	ft_ret_bigger_binary(t_stack *a)
{
	int	i;
	int	bigger_num;
	int	qtd_dig_binary;

	i = 1;
	bigger_num = a->numbers[0];
	qtd_dig_binary = 0;
	while (i <= a->last)
	{
		if (a->numbers[i] > bigger_num)
		{
			bigger_num = a->numbers[i];
		}
		i++;
	}
	while (bigger_num > 0)
	{
		bigger_num = bigger_num / 2;
		qtd_dig_binary++;
	}
	return (qtd_dig_binary);
}

void	ft_sort_more_5(t_stack *a, t_stack *b, int nums_stack)
{
	int	qtd_dig_binary;
	int	i;
	int	j;

	qtd_dig_binary = ft_ret_bigger_binary(a);
	i = 0;
	while (i < qtd_dig_binary)
	{
		j = 0;
		while (j < nums_stack)
		{
			if (a->numbers[0] >> i & 1)
			{
				ft_rotate_a(a);
			}
			else
			{
				ft_push_b(a, b);
			}
			j++;
		}
		while (b->last > -1)
			ft_push_a(b, a);
		i++;
	}
}
