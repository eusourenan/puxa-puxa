

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft42/libft.h"

struct	s_lista
{
	int				numero; // Aqui é o número que você ai organizar
	int				index; // Aqui é pra dizer "ele tem que ficar em qual posição?" Primeira (index == 0), segunda (index == 1), terceira (index == 2)... 
	struct s_lista	*proximo; // Próximo elemento da lista
};

typedef struct s_lista t_lista; // Pra ficar mais prático na hora de usar

t_lista	*ft_novo_elemento(int numero);
t_lista	*ft_ultimo_da_lista(t_lista *elemento);
t_lista	*ft_penultimo_da_lista(t_lista *elemento);
void	ft_adiciona_no_final(t_lista **lista, t_lista *novo_elemento);
void	ft_deleta_lista_toda(t_lista **lista);
void	ft_adiciona_no_topo(t_lista **lista, t_lista *elemento);


// A
void	ft_swap_a(t_lista **pilha_a);
void	ft_rotacionar_a(t_lista **pilha_a);
void	ft_rotacao_reversa_a(t_lista **pilha_a);
void	ft_push_a(t_lista **pilha_a, t_lista **pilha_b);

// B
void	ft_swap_b(t_lista **pilha_b);
void	ft_rotacionar_b(t_lista **pilha_b);
void	ft_rotacao_reversa_b(t_lista **pilha_b);
void	ft_push_b(t_lista **pilha_b, t_lista **pilha_a);

// Ambos
void	ft_swap_swap(t_lista **pilha_a, t_lista **pilha_b);
void	ft_rotacionar_rotacionar(t_lista **pilha_a, t_lista **pilha_b);
void	ft_rotacao_reversa_reversa(t_lista **pilha_a, t_lista **pilha_b);


void	teste(t_lista *pilha_a, t_lista *pilha_b);

#endif