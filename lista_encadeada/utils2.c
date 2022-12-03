
#include "push_swap.h"

void	ft_adiciona_no_topo(t_lista **lista, t_lista *elemento)
{
	elemento->proximo = *lista;
	*lista = elemento;
}