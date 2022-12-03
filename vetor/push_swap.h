

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft42/libft.h"

struct s_lista
{
	int	*numeros;
	int	*indexes;
	int	topo;
};

typedef struct s_lista t_lista;

void	free_matrix(char **matrix);

#endif