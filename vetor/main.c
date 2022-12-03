
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

}

// Função pra verificar se o usuário digitou apenas números, sem gracinhas no meio da brincadeira
int	ft_tem_somente_numeros(char **argumento) // lembre que argv é o que você digitou (os números estão numa matriz, mas eles ainda são lidos como strings e não como números mesmo)
{
	int	linha;
	int	coluna;

	linha = 0;
	while (argumento[linha] != NULL) // Vai percorrer até o fim da matriz
	{
		coluna = 0; // Fica aqui porque toda linha começa da coluna zero
		while (argumento[linha][coluna] != '\0') // Vai percorrer até o final da linha
		{
			if (ft_isdigit(argumento[linha][coluna]) == 0) // Aqui eu verifico se tem algo diferente de um número
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
	vetor(&lista); // Aqui vamos colocar todos os números na lista, um por um
	comeca_push();
	return (0);
}
