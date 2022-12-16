/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizador.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:58:16 by rleite-s          #+#    #+#             */
/*   Updated: 2022/12/16 18:47:04 by msilva-p         ###   ########.fr       */
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
	else
		ft_organiza_ate_100(pilha_a, pilha_b);
}

void	ft_organiza_ate_3(t_lista *pilha_a, t_lista *pilha_b)
{
	if (pilha_a->ultimo == 1)
	{
		if (pilha_a->numeros[0] > pilha_a->numeros[1])
			ft_swap_a(pilha_a);
	}
	else if (pilha_a->numeros[0] > pilha_a->numeros[1] 
		&& pilha_a->numeros[0] > pilha_a->numeros[2])
	{
		ft_reverse_rotate_a(pilha_a);
		if (pilha_a->numeros[1] > pilha_a->numeros[2])
			ft_swap_a(pilha_a);
	}
	else if (pilha_a->numeros[1] > pilha_a->numeros[0] 
		&& pilha_a->numeros[1] > pilha_a->numeros[2])
	{
		if (pilha_a->numeros[0] < pilha_a->numeros[2])
			ft_swap_a(pilha_a);
		ft_reverse_rotate_a(pilha_a);
	}
	else if (pilha_a->numeros[2] > pilha_a->numeros[0] 
		&& pilha_a->numeros[2] > pilha_a->numeros[1])
	{
		if (pilha_a->numeros[0] > pilha_a->numeros[1])
			ft_swap_a(pilha_a);
	}
}

int ft_retorna_maior (t_lista *pilha_a)
{
	int numero;
	int renan;
	int maior_index;
	
	numero = pilha_a->numeros[pilha_a->topo];
	renan = pilha_a->topo;
	maior_index = renan;
	while(renan <= pilha_a->ultimo)
	{
		if(pilha_a->numeros[renan] > numero)
		{
			numero = pilha_a->numeros[renan];
			maior_index = renan;
		}
		renan++;
	}
	return(maior_index);
} 

void	ft_organiza_ate_5(t_lista *pilha_a, t_lista *pilha_b)
{
	int	menor_posicao;

	while (pilha_a->ultimo >= 3)
	{
		menor_posicao = ft_ret_posicao_do_menor(pilha_a);
		if (menor_posicao == 0)
			ft_push_b(pilha_a, pilha_b);
		else if (menor_posicao == 1)
			ft_swap_a(pilha_a);
		else if (menor_posicao == 2)
			ft_rotate_a(pilha_a);
		else if (menor_posicao == 3)
			ft_reverse_rotate_a(pilha_a);
		else if (menor_posicao == 4)
			ft_reverse_rotate_a(pilha_a);
	}
	ft_organiza_ate_3(pilha_a);
	while (pilha_b->ultimo > -1)
		ft_push_a(pilha_b, pilha_a);
}

int ft_ret_posicao_do_menor(t_lista *pilha_a)
{
	int i;
	int menor_num;
	int posicao_do_menor;

	i = 1;
	menor_num = pilha_a->numeros[0];
	posicao_do_menor = 0;
	while (i <= pilha_a->ultimo)
	{
		if (pilha_a->numeros[i] < menor_num)
		{
			menor_num = pilha_a->numeros[i];
			posicao_do_menor = i;
		}
		i++;
	}
	return (posicao_do_menor);
}

int ft_ret_maior_binario (t_lista *pilha_a)
{
	int i;
	int maior_num;
	int qtd_dig_binario;

	i = 1;
	maior_num = pilha_a->numeros[0];
	qtd_dig_binario = 0;
	while (i <= pilha_a->ultimo)
	{
		if (pilha_a->numeros[i] > maior_num)
		{
			maior_num = pilha_a->numeros[i];
		}
		i++;
	}
	while (maior_num > 0)
	{
		maior_num = maior_num / 2;
		qtd_dig_binario++;
	}
	return (qtd_dig_binario);
}

void	ft_organiza_ate_100(t_lista *pilha_a, t_lista *pilha_b, int qtd_num_stack)
{
	int qtd_dig_binario;
	int i;
	int j;

	qtd_dig_binario = ft_ret_maior_binario (pilha_a);
	i = 0;
	while (i < qtd_dig_binario)
	{
		j = 0;
		while (j < qtd_num_stack)
		{
			if (pilha_a->numeros[0] >> i & 1)
			{
				ft_rotate_a(pilha_a);
			}
			else
			{
				ft_push_b(pilha_a, pilha_b);
			}
			j++;
		}
		while (pilha_b->ultimo > -1)
			ft_push_a(pilha_b, pilha_a);
		i++;
	}
}

