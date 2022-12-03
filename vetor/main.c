
#include "push_swap.h"

// Função pra dar free em matriz
void	free_matrix(char **matrix)
{
	int	index;

	index = 0;
	if (matrix != NULL) // Verificação de segurança
	{
		while (matrix[index] != NULL) // Percorre até a última linha
		{
			free(matrix[index]); // Free de linha por linha
			index++;
		}
		free(matrix); // free final
	}
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
	somente_numeros = tem_somente_numeros(++argv); // Verifica item por item
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
