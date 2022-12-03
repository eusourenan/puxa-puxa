
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	size(t_lista *l)
{
	int	qtd = 0;
	while (l)
	{
		qtd++;
		l = l->proximo;
	}
	return (qtd);
}

void	print_pilhas(t_lista *pilha_a, t_lista *pilha_b, int qtd)
{
	int	size_a = size(pilha_a);
	int	size_b = size(pilha_b);

	while (qtd > 0)
	{
		if (size_a == qtd)
		{
			printf("   %d\t\t\t", pilha_a->numero);
			pilha_a = pilha_a->proximo;
			size_a--;
		}
		else
			printf("   - \t\t\t");
		if (size_b == qtd)
		{
			printf("   %d\t\t\t", pilha_b->numero);
			pilha_b = pilha_b->proximo;
			size_b--;
		}
		else
			printf("   - \t\t\t");
		puts("");
		qtd--;
	}
	puts("Pilha A\t\t\tPilha B");
}

int	sair(char *teste)
{
	return (teste[0] == '0' || !ft_strncmp("sair", teste, 4) || !ft_strncmp("encerrar", teste, 8));
}

// Aqui é só pra ter uma coisa visual no terminal pra ver a mágica acontecendo
void	teste(t_lista *pilha_a, t_lista *pilha_b)
{
	char	teste[200];
	int		qtd = size(pilha_a);

	do
	{
		print_pilhas(pilha_a, pilha_b, qtd);
		printf("A brincadeira é simples: Digite o movimento que você quer (um por vez) e veja a mágica.\n");
		printf("Movimentos possíveis: pa sa ra rra pb sb rb rrb ss rr rrr.\n");
		printf("Digite 0 ou sair para encerrar.\n");
		printf("Sua escolha: ");
		scanf("%s", teste);
		if (!ft_strncmp("pa", teste, 2))
			ft_push_a(&pilha_a, &pilha_b);
		else if (!ft_strncmp("sa", teste, 2))
			ft_swap_a(&pilha_a);
		else if (!ft_strncmp("ra", teste, 2))
			ft_rotacionar_a(&pilha_a);
		else if (!ft_strncmp("rra", teste, 3))
			ft_rotacao_reversa_a(&pilha_a);
		else if (!ft_strncmp("pb", teste, 2))
			ft_push_b(&pilha_b, &pilha_a);
		else if (!ft_strncmp("sb", teste, 2))
			ft_swap_b(&pilha_b);
		else if (!ft_strncmp("rb", teste, 2))
			ft_rotacionar_b(&pilha_b);
		else if (!ft_strncmp("rrb", teste, 3))
			ft_rotacao_reversa_b(&pilha_b);
		else if (!ft_strncmp("ss", teste, 2))
			ft_swap_swap(&pilha_a, &pilha_b);
		else if (!ft_strncmp("rr", teste, 2))
			ft_rotacionar_rotacionar(&pilha_a, &pilha_b);
		else if (!ft_strncmp("rrr", teste, 3))
			ft_rotacao_reversa_reversa(&pilha_a, &pilha_b);
		if (!sair(teste))
			system("clear");
	} while (!sair(teste));
}