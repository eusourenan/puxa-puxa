

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
