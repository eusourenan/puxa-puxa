/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizador.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleite-s < rleite-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:58:16 by rleite-s          #+#    #+#             */
/*   Updated: 2022/12/08 19:55:10 by rleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_organiza_ate_3(t_lista *pilha_a, t_lista *pilha_b);
void	ft_organiza_ate_5(t_lista *pilha_a, t_lista *pilha_b);
void	ft_organiza_ate_100(t_lista *pilha_a, t_lista *pilha_b);
void	ft_organiza_acima_100(t_lista *pilha_a, t_lista *pilha_b);

/*void	ft_executa_movimento(int movimento, t_lista *pilha_a, t_lista *pilha_b)
{
	int retorno;

	if (movimento == PA)
		retorno = ft_push_a(pilha_a, pilha_b);
	else if (movimento == PB)
		retorno = ft_push_b(pilha_b, pilha_a);
	else if (movimento == SA)
		retorno = ft_swap_a(pilha_a);
	else if (movimento == SB)
		retorno = ft_swap_b(pilha_b);
	else if (movimento == RA)
		retorno = ft_rotate_a(pilha_a);
	else if (movimento == RB)
		retorno = ft_rotate_b(pilha_b);
	else if (movimento == RRA)
		retorno = ft_reverse_rotate_a(pilha_a);
	else if (movimento == RRB)
		retorno = ft_reverse_rotate_b(pilha_b);
	else if (movimento == SS)
		retorno = ft_swap_swap(pilha_a, pilha_b);
	else if (movimento == RR)
		retorno = ft_rotate_rotate(pilha_a, pilha_b);
	else if (movimento == RRR)
		retorno = ft_reverse_rotate_rotate(pilha_a, pilha_b);
	return (retorno);	
}*/

void	ft_checar_caso(t_lista *pilha_a, t_lista *pilha_b, int numeros)
{
	if (numeros <= 3)
		ft_organiza_ate_3(pilha_a, pilha_b);
	else if (numeros <= 5)
		ft_organiza_ate_5(pilha_a, pilha_b);
	else if (numeros <= 100)
		ft_organiza_ate_100(pilha_a, pilha_b);
	else
		ft_organiza_acima_100(pilha_a, pilha_b);
}
// Lógica alternativa e mais otimizada:Joga o maior pro final da pilha (2 ifs) e dá um swap (se preciso for)
void	ft_organiza_ate_3(t_lista *pilha_a, t_lista *pilha_b)
{
	if (pilha_a->topo == 1)
		ft_swap_a(pilha_a);
	else if (pilha_a->indexes[0] == 1 && pilha_a->indexes[1] == 2 && pilha_a->indexes[2] == 0)
	{
		ft_reverse_rotate_a(pilha_a);
		ft_swap_a(pilha_a);
	}
	else if (pilha_a->indexes[0] == 2 && pilha_a->indexes[1] == 0 && pilha_a->indexes[2] == 1)
		ft_swap_a(pilha_a);
	else if (pilha_a->indexes[0] == 0 && pilha_a->indexes[1] == 2 && pilha_a->indexes[2] == 1)
		ft_reverse_rotate_a(pilha_a);
	else if (pilha_a->indexes[0] == 1 && pilha_a->indexes[1] == 0 && pilha_a->indexes[2] == 2)
	{
		ft_rotate_a(pilha_a);
	}
	else if (pilha_a->indexes[0] == 0 && pilha_a->indexes[1] == 1 && pilha_a->indexes[2] == 2)
	{
		ft_swap_a(pilha_a);
		ft_reverse_rotate_a(pilha_a);
	}
}

void	ft_organiza_ate_5(t_lista *pilha_a, t_lista *pilha_b)
{
	
}

void	ft_organiza_ate_100(t_lista *pilha_a, t_lista *pilha_b)
{
	
}

void	ft_organiza_acima_100(t_lista *pilha_a, t_lista *pilha_b)
{
	
}
