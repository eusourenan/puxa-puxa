
#include "push_swap.h"

int ft_error(void)
{
	ft_printf("Error!\n");
	return(1);
}
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

int ft_malloc(int *vetor, int args)
{
	vetor = (int *) malloc(args * sizeof(int));
	if (vetor == NULL)
		return(ft_error());
	else
		return(0);
}

int ft_mallocado(t_lista *pilha_a, t_lista *pilha_b, int quantidade_argumentos)
{
	if (ft_malloc(pilha_a->numeros, quantidade_argumentos) == 1)
		return(1); // malloco o espaço pros números
	// if se deu errado
	if (ft_malloc(pilha_a->indexes, quantidade_argumentos) == 1) // malloco os espaço pros indexes
	{
		free(pilha_a->numeros);
		return(1); 
	}
	// if se deu errado
	if (ft_malloc(pilha_b->numeros, quantidade_argumentos) == 1)
	{
		free(pilha_a->numeros);
		free(pilha_a->indexes);
		return(1);
	} 
	if (ft_malloc(pilha_b->indexes, quantidade_argumentos) == 1)
	{
		free(pilha_a->numeros);
		free(pilha_a->indexes);
		free(pilha_b->numeros);
		return(1);
	}
	return(0);
}
void	ft_cria_vetor(char **argumentos)
{
	t_lista	pilha_a; // A vai começar com os números
	t_lista	pilha_b; // B vai começar sem números, mas tem que ser mallocado com o mesmo tamanho que a pilha A
	int		quantidade_argumentos;
	int		posicao_atual;

	quantidade_argumentos = ft_conta_argumentos(argumentos); // Conto a quantidade certa pra mallocar
	if (ft_mallocado(&pilha_a, &pilha_b, quantidade_argumentos) == 1)
		return ;
	// if se deu errado
	pilha_a.ultimo = quantidade_argumentos - 1;
	pilha_b.ultimo = -1; //se ultimo for = -1, então pilha b está vazia / pilha a idem

	posicao_atual = 0;
	while (argumentos[posicao_atual] != NULL)
	{
		pilha_a.numeros[posicao_atual] = ft_atoi(argumentos[posicao_atual]);
		posicao_atual++;
	}
	ft_organizar_indexes(&pilha_a, quantidade_argumentos);
	//ft_checar_caso(&pilha_a, &pilha_b, pilha_a.ultimo);
	//print_pilhas(&pilha_a, &pilha_b, pilha_a.ultimo);
 	teste(&pilha_a, &pilha_b);
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
		return(ft_error());
	
	if (argc < 3) // Nesse caso, ele só digitou um número //verificar quando só tem 1 arg(numero)
		return(ft_error()); // Mensagem de erro dividida em 2 comandos por conta de norma ヽ(ヅ)ノ
	// Se passou dessa linha, vamos ao menos verificar os argumentos
	somente_numeros = ft_tem_somente_numeros(++argv); // Verifica item por item
	if (somente_numeros == 1) // Se entrar nesse if, deu ruim, tem algo que não é número
		return(ft_error());
	// Passando daqui, só tem números
	ft_cria_vetor(argv); // Aqui vamos colocar todos os números na lista, um por um
	return (0);
}
