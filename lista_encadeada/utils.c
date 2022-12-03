
#include "push_swap.h"

// Função pra criar um novo elemento da lista
t_lista	*ft_novo_elemento(int numero)
{
	t_lista	*novo_elemento;

	novo_elemento = (t_lista *) malloc(1 * sizeof(t_lista)); // Malloco um espaço de memória
	novo_elemento->numero = numero; // Insiro o número na lista
	novo_elemento->index = 0; // "Padrão" (existe uns negócios pra resolver antes de definir zero como padrão, mas é você que tem que escolher)
	novo_elemento->proximo = NULL; // Padrão
	return (novo_elemento); // Retorno o elemento que foi criado agora
}

// Função que retorna qual é o último elemento da lista
t_lista	*ft_ultimo_da_lista(t_lista *elemento)
{
	if (elemento == NULL) // Se não tem nada
		return (elemento); // Só retorna
	while (elemento->proximo != NULL) // Enquanto tiver um próximo elemento
		elemento = elemento->proximo; // Vai pro próximo elemento 
	return (elemento); // Aqui ele retorna o último elemento da lista
}

// Função que retorna o penúltimo elemento da lista
t_lista	*ft_penultimo_da_lista(t_lista *elemento)
{
	if (elemento == NULL || elemento->proximo == NULL) // Se não tem nada ou só um elemento
		return (NULL); // Só retorna
	while (elemento->proximo->proximo != NULL) // Enquanto tiver dois elementos à frente
		elemento = elemento->proximo; // Vai pro próximo elemento 
	return (elemento); // Aqui ele retorna o penúltimo elemento da lista
}

// Função que adiciona um número ao final da lista
void	ft_adiciona_no_final(t_lista **lista, t_lista *novo_elemento)
{
	t_lista	*aux;

	if (lista == NULL) // Se não existe nenhuma lista só retorna, não dá pra adicionar nada
		return ;
	if (*lista == NULL) // Se a lista está vazia, colocamos novo_elemento como o primeiro da lista (E consequentemente o último)
	{
		*lista = novo_elemento;
		return ; // Retorno de segurança
	}
	aux = ft_ultimo_da_lista(*lista); // Procuro o último elemento
	aux->proximo = novo_elemento; // Adiciono o novo elemento depois do último da lista
}

void	ft_deleta_lista_toda(t_lista **lista)
{
	t_lista	*auxiliar;

	while (*lista != NULL)
	{
		auxiliar = (*lista)->proximo;
		free(*lista);
		*lista = auxiliar;
	}
	*lista = NULL;
}