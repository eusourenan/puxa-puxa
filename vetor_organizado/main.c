
#include "push_swap.h"

// Função pra saber quanto de espaço tem que ser mallocado pro vetor
int	ft_conta_argumentos(char **argumentos)
{
	int	quantidade_argumentos;
	int	index;

	quantidade_argumentos = 0;
	if (argumentos != NULL)
	{
		index = 0;
		while (argumentos[index] != NULL)
		{
			quantidade_argumentos++;
			index++;
		}
	}
	return (quantidade_argumentos);
}

void	ft_organizar_indexes(t_lista *pilha_a, int quantidade_argumentos)
{
	int	primeiro_index;
	int	segundo_index;

	primeiro_index = 0;
	while (primeiro_index < quantidade_argumentos)
	{
		pilha_a->indexes[primeiro_index] = 0;
		segundo_index = 0;
		while (segundo_index < quantidade_argumentos)
		{
			if (pilha_a->numeros[primeiro_index] > pilha_a->numeros[segundo_index])
			{
				pilha_a->indexes[primeiro_index] += 1;
			}
			segundo_index++;
		}
		primeiro_index++;
	}
	/*primeiro_index = 0;
	ft_putstr_fd("\n\n\t\t  Topo da pilha\n", 1);
	while (primeiro_index < quantidade_argumentos)
	{
		ft_putstr_fd("pilha_a->numeros[ ", 1);
		ft_putnbr_fd(primeiro_index, 1);
		ft_putstr_fd(" ]", 1);
		ft_putstr_fd(" == Número: ", 1);
		ft_putnbr_fd(pilha_a->numeros[primeiro_index], 1);
		ft_putstr_fd("\tIndex(quando ordenado): ", 1);
		ft_putnbr_fd(pilha_a->indexes[primeiro_index], 1);
		ft_putstr_fd("\n", 1);
		primeiro_index++;
	}
	ft_putstr_fd("\t\t ^Fim da pilha\n", 1);*/
}

void	ft_cria_vetor(char **argumentos)
{
	t_lista	pilha_a; // A vai começar com os números
	t_lista	pilha_b; // B vai começar sem números, mas tem que ser mallocado com o mesmo tamanho que a pilha A
	int		quantidade_argumentos;

	quantidade_argumentos = ft_conta_argumentos(argumentos); // Conto a quantidade certa pra mallocar
	pilha_a.numeros = (int *) malloc(quantidade_argumentos * sizeof(int)); // malloco o espaço pros números
	// if se deu errado
	pilha_a.indexes = (int *) malloc(quantidade_argumentos * sizeof(int)); // malloco os espaço pros indexes
	// if se deu errado
	pilha_b.numeros = (int *) malloc(quantidade_argumentos * sizeof(int)); //malloco espaço dos números em B
	// if se deu errado
	pilha_b.indexes = (int *) malloc(quantidade_argumentos * sizeof(int)); // e o espaço pros indexes
	// if se deu errado
	pilha_a.ultimo = --quantidade_argumentos;
	pilha_a.topo = 0;
	pilha_b.ultimo = pilha_a.ultimo;
	pilha_b.topo = -(pilha_b.ultimo + 1);

	while (*argumentos != NULL)
	{
		pilha_a.numeros[pilha_a.topo] = ft_atoi(argumentos[0]);
		pilha_a.topo++;
		argumentos++;
	}
	pilha_a.topo = 0;
	ft_organizar_indexes(&pilha_a, pilha_a.ultimo + 1);
	ft_checar_caso(&pilha_a, &pilha_b, pilha_a.ultimo);
	print_pilhas(&pilha_a, &pilha_b, pilha_a.ultimo);
	//teste(&pilha_a, &pilha_b);
}

// Função pra verificar se o usuário digitou apenas números, sem gracinhas no meio da brincadeira
int	ft_tem_somente_numeros(char **argumento) // lembre que argv é o que você digitou (os números estão numa matriz, mas eles ainda são lidos como strings e não como números mesmo)
{
	int	linha;
	int	coluna;

	linha = 0;
	while (argumento[linha] != NULL) // Vai percorrer até o fim da matriz
	{
		if (!*argumento[linha])
			return (1);
		coluna = 0; // Fica aqui porque toda linha começa da coluna zero
		while (argumento[linha][coluna] != '\0') // Vai percorrer até o final da linha
		{
			if (ft_isdigit(argumento[linha][coluna]) == 0 && (argumento[linha][coluna] != '-' || coluna != 0)) // Aqui eu verifico se tem algo diferente de um número
				return (1); // Se tiver, retorno 1 e já (o que indica que deu ruim)
			coluna++; // Incremento pra não ter loop infinito
		}
		linha++; // Incremento pra não ter loop infinito
	}
	return (0); // Se chegar aqui, o usuário digitou apenas números (zero erros)
}

// Função onde vai ser iniciar tudo
int	main(int argc, char **argv)
{
	int		somente_numeros; // Inteiro que verifica se o usuário não fez nenhuma gracinha ao invés de digitar apenas números
	t_lista	lista; // Linha auto-explicativa

	if (argc < 2) // Se tiver menos de 2 argumentos, só tem o nome do arquivo
	{
		ft_putstr_fd("Sem números fica difícel de organizar... (T.T)\n", 1); // mensagem de erro.
		return (1);
	}
	if (argc < 3) // Nesse caso, ele só digitou um número
	{
		// Mensagem de erro dividida em 2 comandos por conta de norma ヽ(ヅ)ノ
		ft_putstr_fd("Nem vou verificar esse argumento, preciso de mais ", 1);
		ft_putstr_fd("argumentos pra poder organizar alguma coisa. (@_@)\n", 1);
		return (1);
	}// Se passou dessa linha, vamos ao menos verificar os argumentos
	somente_numeros = ft_tem_somente_numeros(++argv); // Verifica item por item
	if (somente_numeros == 1) // Se entrar nesse if, deu ruim, tem algo que não é número
	{
		ft_putstr_fd("Por gentileza, digite apenas números!\n", 1); // Mensagem de erro padrão
		ft_putstr_fd("Programa finalizado.\n", 1);
		return (1);
	}// Passando daqui, só tem números
	ft_cria_vetor(argv); // Aqui vamos colocar todos os números na lista, um por um
	return (0);
}
