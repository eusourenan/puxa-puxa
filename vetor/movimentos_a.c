

void	ft_swap_a(t_lista *pilha_a)
{
	int	auxiliar;

	if (pilha_a->topo <= 0)
	{
		// deu ruim
		return ;
	}
	auxiliar = pilha_a->numeros[pilha_a->topo];
	pilha_a->numeros[pilha_a->topo] = pilha_a->numeros[pilha_a->topo - 1];
	pilha_a->numeros[pilha_a->topo - 1] = auxiliar;
	
	auxiliar = pilha_a->indexes[pilha_a->topo];
	pilha_a->indexes[pilha_a->topo] = pilha_a->indexes[pilha_a->topo - 1];
	pilha_a->indexes[pilha_a->topo - 1] = auxiliar
}

void	ft_rotate_a(t_lista *pilha_a)
{
	int	auxiliar[2];
	int	i;

	if (pilha_a->topo <= 0)
	{
		// deu ruim
		return ;
	}
	auxiliar[0] = pilha_a->numeros[pilha_a->topo];
	auxiliar[1] = pilha_a->indexes[pilha_a->topo];
	i = pilha_a->topo;
	while (i > 0)
	{
		pilha_a->numeros[i] = pilha_a->numeros[i - 1];
		pilha_a->indexes[i] = pilha_a->indexes[i - 1];
		i--;
	}
	pilha_a->numeros[i] = auxiliar[0];
	pilha_a->indexes[i] = auxiliar[1];
}

void	ft_reverse_rotate(t_lista *pilha_a)
{
	int	auxiliar[2];
	int	i;

	if (pilha_a->topo <= 0)
	{
		// deu ruim
		return ;
	}
	i = 0;
	auxiliar[0] = pilha_a->numeros[0];
	auxiliar[1] = pilha_a->indexes[0];
	while (i < pilha_a->topo)
	{
		pilha_a->numeros[i] = pilha_a->numeros[i + 1];
		pilha_a->indexes[i] = pilha_a->indexes[i + 1];
		i++;
	}
	pilha_a->numeros[i] = auxiliar[0];
	pilha_a->indexes[i] = auxiliar[1];
}
