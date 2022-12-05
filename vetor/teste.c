

#include "push_swap.h"
#include <stdio.h>

void	print_pilhas(t_lista *pilha_a, t_lista *pilha_b, int qtd)
{
	int	size_a = pilha_a->topo;
	int	size_b = pilha_b->topo;

	while (qtd >= 0)
	{
		if (size_a == qtd)
			printf("   %d\t\t\t", pilha_a->numeros[size_a--]);
		else
			printf("   - \t\t\t");
		if (size_b == qtd)
			printf("   %d\t\t\t", pilha_b->numeros[size_b--]);
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

void	teste(t_lista *pilha_a, t_lista *pilha_b)
{
	char	teste[200];
	int	qtd = pilha_a->topo;
	unsigned int	moves = 0;

	do
	{
		print_pilhas(pilha_a, pilha_b, qtd);
		printf("A brincadeira é simples: Digite o movimento que você quer (um por vez) e veja a mágica.\n");
		printf("Movimentos possíveis: pa sa ra rra pb sb rb rrb ss rr rrr.\n");
		printf("Digite 0 ou sair para encerrar.\n");
		printf("\nMovimentos: %d\n\n", moves++);
		printf("Sua escolha: ");
		scanf("%s", teste);
		if (!ft_strncmp("pa", teste, 3))
			ft_push_a(pilha_a, pilha_b);
		else if (!ft_strncmp("sa", teste, 3))
			ft_swap_a(pilha_a);
		else if (!ft_strncmp("ra", teste, 3))
			ft_rotate_a(pilha_a);
		else if (!ft_strncmp("rra", teste, 4))
			ft_reverse_rotate_a(pilha_a);
		else if (!ft_strncmp("pb", teste, 3))
			ft_push_b(pilha_b, pilha_a);
		else if (!ft_strncmp("sb", teste, 3))
			ft_swap_b(pilha_b);
		else if (!ft_strncmp("rb", teste, 3))
			ft_rotate_b(pilha_b);
		else if (!ft_strncmp("rrb", teste, 4))
			ft_reverse_rotate_b(pilha_b);
		else if (!ft_strncmp("ss", teste, 3))
			ft_swap_swap(pilha_a, pilha_b);
		else if (!ft_strncmp("rrr", teste, 4))
			ft_reverse_rotate_rotate(pilha_a, pilha_b);
		else if (!ft_strncmp("rr", teste, 3))
			ft_rotate_rotate(pilha_a, pilha_b);
		else
			moves--;
		if (!sair(teste))
			system("clear");
	} while (!sair(teste));
}