/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentos_ambos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:27:27 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/17 00:28:05 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_swap(t_stack *a, t_stack *b)
{
	if (a->last <= 0 || b->last <= 0)
	{
		// deu ruim
		return ;
	}
	ft_swap_a(a);
	ft_swap_b(b);
}

void	ft_rotate_rotate(t_stack *a, t_stack *b)
{
	if (a->last <= 0 || b->last <= 0)
	{
		// deu ruim
		return ;
	}
	ft_rotate_a(a);
	ft_rotate_b(b);
}

void	ft_reverse_rotate_rotate(t_stack *a, t_stack *b)
{
	if (a->last <= 0 || b->last <= 0)
	{
		// deu ruim
		return ;
	}
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
}
