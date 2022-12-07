
/******************************************************************************
ESSAS FUNÇÕES FORAM SEPARADAS EM 3 ARQUIVOS PARA FINS DIDÁTICOS, DÁ PRA FAZER
TUDO EM UM ARQUIVO SÓ. APÓS ANALIZAR OS 3, DÁ PRA VER COMO ELES SÃO MUITO PA-
RECIDOS.
******************************************************************************/

#include "push_swap.h"

/* Troca a ordem do topo e do elemento de baixo
Exemplo: (topo/começo da pilha) 2 1 3 4 5 6 (base/fim da pilha)
								^ ^
	Depois do swap
(topo/começo da pilha) 1 2 3 4 5 6 (base/fim da pilha)
*/
void	ft_swap_a(t_lista **pilha_a)
{
	t_lista	*auxiliar;

	if (pilha_a == NULL) // Verificação de segurança
	{
		// Mensagem de erro?
		return ;
	}
	if (*pilha_a != NULL && (*pilha_a)->proximo != NULL) // Verifico se tem pelo menos 2 elementos
	{
		// Explicar essa sequência de movimentos vai ter que ser com algo visual, malz
		auxiliar = (*pilha_a)->proximo;
		(*pilha_a)->proximo = (*pilha_a)->proximo->proximo;
		auxiliar->proximo = *pilha_a;
		*pilha_a = auxiliar;		
	}
	else
	{
		// Mensagem de erro?
		return ;
	}
}

/* Faz o elemento do topo ir pro fim da pilha
Exemplo: (topo/começo da pilha) 6 1 2 3 4 5 (base/fim da pilha)
								^ 
	Depois de rotacionar
(topo/começo da pilha) 1 2 3 4 5 6 (base/fim da pilha)
*/
void	ft_rotacionar_a(t_lista **pilha_a)
{
	t_lista	*auxiliar;

	if (pilha_a == NULL) // Verificação de segurança
	{
		// Mensagem de erro?
		return ;
	}
	auxiliar = ft_ultimo_da_lista(*pilha_a);
	if (auxiliar == *pilha_a) // Se isso for verdade, só tem um elemento em A (não dá pra fazer a troca de dois elementos se a lista só tem 1)
	{
		// Mensagem de erro?
		return ;
	}
	// Vai ser visual também (T.T) Só consigo explicar desenhando
	auxiliar->proximo = *pilha_a;
	*pilha_a = (*pilha_a)->proximo;
	auxiliar->proximo->proximo = NULL;
}

/* Faz o elemento do fim ir pro topo da pilha
Exemplo: (topo/começo da pilha) 2 3 4 5 6 1 (base/fim da pilha)
										  ^ 
	Depois da rotação reversa
(topo/começo da pilha) 1 2 3 4 5 6 (base/fim da pilha)
*/
void	ft_rotacao_reversa_a(t_lista **pilha_a)
{
	t_lista	*auxiliar;

	if (pilha_a == NULL) // Verificação de segurança
	{
		// Mensagem de erro?
		return ;
	}
	auxiliar = ft_penultimo_da_lista(*pilha_a);
	if (auxiliar == NULL) // Se isso for verdade, não tem 2 elementos na lista
	{
		// Mensagem de erro?
		return ;
	}
	// Vai ser visual também (T.T) Só consigo explicar desenhando
	auxiliar->proximo->proximo = *pilha_a;
	*pilha_a = auxiliar->proximo;
	auxiliar->proximo = NULL;
}

/* Elemento no topo da pilha A, vai pro topo da pilha B
Exemplo: 

(topo/começo da pilha B)  (base/fim da pilha B)
(topo/começo da pilha A) 1 2 3 4 5 6 (base/fim da pilha A)
						 ^ 
	Depois do push
(topo/começo da pilha B) 1 (base/fim da pilha B)
(topo/começo da pilha A) 2 3 4 5 6 (base/fim da pilha A)
*/
void	ft_push_a(t_lista **pilha_a, t_lista **pilha_b)
{
	t_lista	*auxiliar;

	if (pilha_b == NULL || *pilha_b == NULL) // Verificação de segurança
	{
		// Mensagem de erro?
		return ;
	}
	auxiliar = *pilha_b;
	*pilha_b = (*pilha_b)->proximo;
	auxiliar->proximo = NULL;
	ft_adiciona_no_topo(pilha_a, auxiliar);
}
