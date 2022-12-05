
/******************************************************************************
ESSAS FUNÇÕES FORAM SEPARADAS EM 3 ARQUIVOS PARA FINS DIDÁTICOS, DÁ PRA FAZER
TUDO EM UM ARQUIVO SÓ. APÓS ANALIZAR OS 3, DÁ PRA VER COMO ELES SÃO MUITO PA-
RECIDOS.
******************************************************************************/

#include "push_swap.h"

/* Faz swap de A e B ao mesmo tempo
*/
void	ft_swap_swap(t_lista **pilha_a, t_lista **pilha_b)
{
	t_lista	*auxiliar_a;
	t_lista	*auxiliar_b;

	if (pilha_a == NULL || pilha_b == NULL) // Verificação de segurança
	{
		// Mensagem de erro?
		return ;
	}
	if (*pilha_a != NULL && (*pilha_a)->proximo != NULL
		&& *pilha_b != NULL && (*pilha_b)->proximo != NULL) // Verifico se tem pelo menos 2 elementos nas duas pilhas
	{
		// Explicar essa sequência de movimentos vai ter que ser com algo visual, malz
		ft_swap_a(pilha_a);
		ft_swap_b(pilha_b);
	}
	else
	{
		// Mensagem de erro?
		return ;
	}
}

/* Rotaciona A e B ao mesmo tempo
*/
void	ft_rotacionar_rotacionar(t_lista **pilha_a, t_lista **pilha_b)
{
	t_lista	*auxiliar_a;
	t_lista	*auxiliar_b;

	if (pilha_a == NULL || pilha_b == NULL) // Verificação de segurança
	{
		// Mensagem de erro?
		return ;
	}
	auxiliar_a = ft_ultimo_da_lista(*pilha_a);
	auxiliar_b = ft_ultimo_da_lista(*pilha_b);
	if (auxiliar_a == *pilha_a || auxiliar_b == *pilha_b) // Se isso for verdade, só tem um elemento em A ou em B (não dá pra fazer a troca de dois elementos se alguma lista só tem 1 elemento)
	{
		// Mensagem de erro?
		return ;
	}
	// Vai ser visual também (T.T) Só consigo explicar desenhando
	ft_rotacionar_a(pilha_a);
	ft_rotacionar_b(pilha_b);
}

/* Faz rotação reversa em A e B ao mesmo tempo
*/
void	ft_rotacao_reversa_reversa(t_lista **pilha_a, t_lista **pilha_b)
{
	t_lista	*auxiliar_a;
	t_lista	*auxiliar_b;

	if (pilha_a == NULL || pilha_b == NULL) // Verificação de segurança
	{
		// Mensagem de erro?
		return ;
	}
	auxiliar_a = ft_penultimo_da_lista(*pilha_a);
	auxiliar_b = ft_penultimo_da_lista(*pilha_b);
	if (auxiliar_a == NULL || auxiliar_b == NULL) // Se isso for verdade, não tem 2 elementos em alguma lista
	{
		// Mensagem de erro?
		return ;
	}
	// Vai ser visual também (T.T) Só consigo explicar desenhando
	ft_rotacao_reversa_a(pilha_a);
	ft_rotacao_reversa_b(pilha_b);
}
