
#include "push_swap.h"

// Aqui a lista vai ser iniciada com os valores sendo inseridos como números de verdade (lembre que eles eram strings)
void	cria_elementos(t_lista **lista, char **argumentos)
{
	int		numero; // Vai receber a string convertida em número antes de colocar na lista
	int		linha; // Pra percorrer as linhas da matriz de argumentos
	t_lista	*auxiliar; // Apenas pra ajudar a compreeender melhor o passo a passo (mas dá pra remover ela depois)

	numero = ft_atoi(argumentos[linha]);
	*lista = ft_novo_elemento(numero); // Insiro o primeiro número na lista
	/*lista = ft_novo_elemento(linha);
	while (linha > 30)
	{
		ft_adiciona_no_final(lista, ft_novo_elemento(--linha));
	}*/
	linha = 0;
	if (*lista == NULL) // Se houver um Vinícius
		return ; // Depois arrumar pra ficar melhor do que esse simples return
	linha++; // Se na primeira linha deu certo, vamos pra próxima
	while (argumentos[linha] != NULL) // Percorrer todas as linhas
	{
		numero = ft_atoi(argumentos[linha]); // Pego o novo número
		auxiliar = ft_novo_elemento(numero); // Crio um elemento da lista e insiro o novo número lá
		if (auxiliar == NULL) // Mesma coisa do if da linha 14
			return ;
		ft_adiciona_no_final(lista, auxiliar); // Adiciona o auxiliar no final da lista
		linha++; // Pra não dar loop infinito
	}
}

// Função separada da main pra economizar linhas pense em pilha de pratos
void	inicia_pilhas(char **argumentos)
{
	t_lista	*pilha_a; // Pilha a tem todos os números no começo
	t_lista	*pilha_b; // Pilha b começa nula

	pilha_b = NULL;
	cria_elementos(&pilha_a, argumentos); // Aqui vamos colocar todos os números na lista, um por um
	teste(pilha_a, pilha_b);
	ft_deleta_lista_toda(&pilha_a);
}

// Função pra verificar se o usuário digitou apenas números, sem gracinhas no meio da brincadeira
int	tem_somente_numeros(char **argumento) // lembre que argv é o que você digitou (os números estão numa matriz, mas eles ainda são lidos como strings e não como números mesmo)
{
	int	linha;
	int	coluna;

	linha = 0;
	while (argumento[linha] != NULL) // Vai percorrer até o fim da matriz
	{
		coluna = 0; // Fica aqui porque toda linha começa da coluna zero
		if (!*argumento[linha])
			return (1);
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
	somente_numeros = tem_somente_numeros(++argv); // Verifica item por item (ignorando o nome do arquivo, que é o primeiro argumento de padrão)
	if (somente_numeros == 1) // Se entrar nesse if, deu ruim, tem algo que não é número
	{
		ft_putstr_fd("Por gentileza, digite apenas números!\n", 1); // Mensagem de erro padrão
		ft_putstr_fd("Programa finalizado.\n", 1);
		return (1);
	}// Passando daqui, só tem números
	inicia_pilhas(argv);
	return (0);
}
