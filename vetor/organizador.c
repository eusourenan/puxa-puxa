/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizador.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleite-s < rleite-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:58:16 by rleite-s          #+#    #+#             */
/*   Updated: 2022/12/09 16:00:02 by rleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_organiza_ate_3(t_lista *pilha_a);
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
		ft_organiza_ate_3(pilha_a);
	else if (numeros <= 5)
		ft_organiza_ate_5(pilha_a, pilha_b);
	else //if (numeros <= 100)
		ft_organiza_ate_100(pilha_a, pilha_b);
	/*else
		ft_organiza_acima_100(pilha_a, pilha_b);*/
}
// Lógica alternativa e mais otimizada:Joga o maior pro final da pilha (2 ifs) e dá um swap (se preciso for)
int	ft_organiza_ate_3(t_lista *pilha_a)
{
	if (pilha_a->topo == 1)
		{ft_swap_a(pilha_a); return (1);}
	else if (pilha_a->numeros[2] < pilha_a->numeros[1] && pilha_a->numeros[1] > pilha_a->numeros[0] && pilha_a->numeros[0] > pilha_a->numeros[2])
	{
		ft_reverse_rotate_a(pilha_a);
		ft_swap_a(pilha_a); return (2);
	}
	else if (pilha_a->numeros[0] > pilha_a->numeros[2] && pilha_a->numeros[1] < pilha_a->numeros[2] && pilha_a->numeros[0] > pilha_a->numeros[1])
		{ft_swap_a(pilha_a); return (1);}
	else if (pilha_a->numeros[0] < pilha_a->numeros[1] && pilha_a->numeros[1] > pilha_a->numeros[2] && pilha_a->numeros[2] > pilha_a->numeros[0])
		{ft_reverse_rotate_a(pilha_a); return (1);}
	else if (pilha_a->numeros[0] > pilha_a->numeros[1] && pilha_a->numeros[0] < pilha_a->numeros[2] && pilha_a->numeros[2] > pilha_a->numeros[1])
	{
		ft_rotate_a(pilha_a); return (1);
	}
	else if (pilha_a->numeros[0] < pilha_a->numeros[1] && pilha_a->numeros[0] < pilha_a->numeros[2] && pilha_a->numeros[2] > pilha_a->numeros[1])
	{
		ft_swap_a(pilha_a);
		ft_reverse_rotate_a(pilha_a); return (2);
	}
	return (0);
}

int		ft_encontre_maior(t_lista *pilha_a)
{
	int	index;
	int	maior_numero;
	int	index_maior_numero;

	index = pilha_a->topo;
	index_maior_numero = index;
	maior_numero = -1;
	while (index >= 0)
	{
		if (pilha_a->indexes[index] < maior_numero)
		{
			maior_numero = pilha_a->indexes[index];
			index_maior_numero = index;
		}
		index--;
	}
	return (index_maior_numero);
}

void	ft_organiza_ate_5(t_lista *pilha_a, t_lista *pilha_b)
{
	int	index_procurado = 0;
	int	topo = pilha_a->topo;
	int	meio_da_pilha = topo / 2;
	int	teste = 0;
	
	while (topo >= 3)
	{
		if (pilha_a->indexes[pilha_a->topo] == index_procurado)
		{
			ft_push_b(pilha_b, pilha_a), teste++;
			index_procurado++;
			topo--;
			//meio_da_pilha = topo / 2;
		}
		else if (ft_encontre_maior(pilha_a) > meio_da_pilha - 1)
			ft_rotate_a(pilha_a), teste++;
		else
			ft_reverse_rotate_a(pilha_a), teste++;
	}
	teste += ft_organiza_ate_3(pilha_a);
	while (pilha_b->topo >= 0)
	{
		ft_push_a(pilha_a, pilha_b);
		ft_rotate_a(pilha_a), teste += 2;
	}
	printf("Ordem estabelecida com %d movimentos.\n", teste);
}

void	ft_organiza_ate_100(t_lista *pilha_a, t_lista *pilha_b)
{
	int	index_procurado = 0;
	int	topo = pilha_a->topo;
	int	meio_da_pilha = topo / 2;
	int	teste = 0;
	
	while (topo >= 3)
	{
		if (pilha_a->indexes[pilha_a->topo] == index_procurado)
		{
			ft_push_b(pilha_b, pilha_a), teste++;
			index_procurado++;
			topo--;
			meio_da_pilha = topo / 2;
		}
		else if (ft_encontre_maior(pilha_a) < meio_da_pilha - 1)
		{
			ft_rotate_a(pilha_a), teste++;
		}
		else
		{
			ft_reverse_rotate_a(pilha_a), teste++;
		}
	}
	teste += ft_organiza_ate_3(pilha_a);
	while (pilha_b->topo >= 0)
	{
		ft_push_a(pilha_a, pilha_b);
		ft_rotate_a(pilha_a), teste += 2;
	}
	printf("Ordem estabelecida com %d movimentos.\n", teste);
}

void	ft_organiza_acima_100(t_lista *pilha_a, t_lista *pilha_b)
{
	
}
