/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:28:56 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/17 00:58:21 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_error(void)
{
	ft_printf("Error!\n");
	return(1);
}

void	ft_define_index(t_stack *a, int args)
{
	int	first_index;
	int	second_index;

	first_index = 0;
	while (first_index < args)
	{
		a->indexes[first_index] = 0;
		second_index = 0;
		while (second_index < args)
		{
			if (a->numbers[first_index] > a->numbers[second_index])
			{
				a->indexes[first_index] += 1;
			}
			second_index++;
		}
		first_index++;
	}
}

int ft_malloc(int **vector, int args)
{
	*vector = (int *) malloc(args * sizeof(int));
	if (*vector == NULL)
		return(ft_error());
	else
		return(0);
}

int ft_alloc_stack(t_stack *a, t_stack *b, int args)
{
	if (ft_malloc(&a->numbers, args) == 1)
		return(1); // malloco o espaço pros números
	// if se deu errado
	if (ft_malloc(&a->indexes, args) == 1) // malloco os espaço pros indexes
	{
		free(a->numbers);
		return(1); 
	}
	// if se deu errado
	if (ft_malloc(&b->numbers, args) == 1)
	{
		free(a->numbers);
		free(a->indexes);
		return(1);
	} 
	if (ft_malloc(&b->indexes, args) == 1)
	{
		free(a->numbers);
		free(a->indexes);
		free(b->numbers);
		return(1);
	}
	return(0);
}
void	ft_create_vector(int argc, char **args)
{
	t_stack	a; // A vai começar com os números
	t_stack	b; // B vai começar sem números, mas tem que ser mallocado com o mesmo tamanho que a pilha A
	int		i;

	if (ft_alloc_stack(&a, &b, argc) == 1)
		return ;
	// if se deu errado*/
	a.last = argc - 1;
	b.last = -1; //se last for = -1, então pilha b está vazia / pilha a idem
	i = 0;
	while (args[i] != NULL)
	{
		a.numbers[i] = ft_atoi(args[i]);
		i++;
	}
	ft_define_index(&a, argc);
	ft_checker(&a, &b, a.last);
}

// Função pra verificar se o usuário digitou apenas números, sem gracinhas no meio da brincadeira
int	ft_is_only_numbers(char **arg) // lembre que argv é o que você digitou (os números estão numa matriz, mas eles ainda são lidos como strings e não como números mesmo)
{
	int	line;
	int	column;

	line = 0;
	while (arg[line] != NULL) // Vai percorrer até o fim da matriz
	{
		if (!*arg[line])
			return (1);
		column = 0; // Fica aqui porque toda line começa da column zero
		while (arg[line][column] != '\0') // Vai percorrer até o final da line
		{
			if (ft_isdigit(arg[line][column]) == 0 && (arg[line][column] != '-' || column != 0)) // Aqui eu verifico se tem algo diferente de um número
				return (1); // Se tiver, retorno 1 e já (o que indica que deu ruim)
			column++; // Incremento pra não ter loop infinito
		}
		line++; // Incremento pra não ter loop infinito
	}
	return (0); // Se chegar aqui, o usuário digitou apenas números (zero erros)
}

// Função onde vai ser iniciar tudo
int	main(int argc, char **argv)
{
	int		only_numbers; // Inteiro que verifica se o usuário não fez nenhuma gracinha ao invés de digitar apenas números

	if (argc < 2) // Se tiver menos de 2 args, só tem o nome do arquivo
		return(ft_error());
	if (argc < 3) // Nesse caso, ele só digitou um número //verificar quando só tem 1 arg(numero)
		return(ft_error()); // Mensagem de erro dividida em 2 comandos por conta de norma ヽ(ヅ)ノ
	// Se passou dessa line, vamos ao menos verificar os args
	only_numbers = ft_is_only_numbers(++argv); // Verifica item por item
	if (only_numbers == 1) // Se entrar nesse if, deu ruim, tem algo que não é número
		return(ft_error());
	// Passando daqui, só tem números
	ft_create_vector(--argc, argv); // Aqui vamos colocar todos os números na lista, um por um
	return (0);
}
