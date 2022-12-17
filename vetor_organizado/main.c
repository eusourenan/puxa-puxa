/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleite-s < rleite-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:28:56 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/17 23:31:10 by rleite-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_printf ("Error\n");
	return (1);
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

int	ft_malloc(int **vector, int args)
{
	*vector = (int *) malloc(args * sizeof(int));
	if (*vector == NULL)
		return (ft_error());
	else
		return (0);
}

int	ft_alloc_stack(t_stack *a, t_stack *b, int args)
{
	if (ft_malloc(&a->numbers, args) == 1)
		return (1); // malloco o espaço pros números
	// if se deu errado
	if (ft_malloc(&a->indexes, args) == 1) // malloco os espaço pros indexes
	{
		free(a->numbers);
		return (1);
	}
	// if se deu errado
	if (ft_malloc(&b->numbers, args) == 1)
	{
		free(a->numbers);
		free(a->indexes);
		return (1);
	}
	if (ft_malloc(&b->indexes, args) == 1)
	{
		free(a->numbers);
		free(a->indexes);
		free(b->numbers);
		return (1);
	}
	return (0);
}

void	ft_create_vector(int argc, char **args)
{
	t_stack	a; // A vai começar com os números
	t_stack	b; // B vai começar sem números, mas tem que ser mallocado com o mesmo tamanho que a pilha A
	int		i;
	long	atoi_plus;

	if (ft_alloc_stack(&a, &b, argc) == 1)
		return ;
	// if se deu errado*/
	a.last = argc - 1;
	b.last = -1; //se last for = -1, então pilha b está vazia / pilha a idem
	i = 0;
	while (args[i] != NULL)
	{
		atoi_plus = ft_atoi_plus(args[i]); //retorno da atoi_plus= 1)ou número correto enviado/2) ou 42000000000 que é um número inválido
		if (atoi_plus == 42000000000)
		{
			ft_free(&a, &b);
			return ;
		}
		a.numbers[i] = atoi_plus;
		//b.numbers[i] = 0;
		i++;
	}
	ft_define_index(&a, argc);
	if (ft_check_repeat_num(&a) == 1)
	{
		ft_free(&a, &b);
		return ;
	}
	ft_checker(&a, &b, a.last);
}

int	ft_check_repeat_num(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->last)
	{
		j = i + 1;
		while (j <= a->last)
		{
			if (a->indexes[j] == a->indexes[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free(t_stack *a, t_stack *b)
{
	free (a->numbers);
	free (a->indexes);
	free (b->numbers);
	free (b->indexes);
	ft_error();
}

// Função pra verificar se o usuário digitou apenas números, sem gracinhas no meio da brincadeira
int	ft_is_only_numbers(char **arg) // lembre que argv é o que você digitou (os números estão numa matriz, mas eles ainda são lidos como strings e não como números mesmo)
{
	int		line;
	int		column;
	char	*trim;

	line = 0;
	while (arg[line] != NULL) // Vai percorrer até o fim da matriz
	{
		trim = ft_strtrim(arg[line], " \t\r\v\n"); //no caso de números com espaços consecutivos antes e depois a ft_trim tira esses espaços
		if (!*trim)
		{
			free(trim);
			return (1);
		}
		column = 0; // Fica aqui porque toda line começa da column zero
		while (trim[column] != '\0') // Vai percorrer até o final da line
		{
			if (ft_isdigit(trim[column]) == 0 && (trim[column] != '-' || column != 0)) // Aqui eu verifico se tem algo diferente de um número
				return (1); // Se tiver, retorno 1 e já (o que indica que deu ruim)
			column++; // Incremento pra não ter loop infinito
		}
		free(trim);
		line++; // Incremento pra não ter loop infinito
	}
	return (0); // Se chegar aqui, o usuário digitou apenas números (zero erros)
}

long	ft_atoi_plus(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		if (result < INT_MIN || result > INT_MAX) //se um número "muito grande" for analisado (é analisado dig por dig) (é inválido) e vai retornar 42bilhões
		{
			return (42000000000);
		}
		nptr++;
	}
	return (result * sign);
}

// Função onde vai ser iniciar tudo
int	main(int argc, char **argv)
{
	int	only_numbers; // Inteiro que verifica se o usuário não fez nenhuma gracinha ao invés de digitar apenas números

	if (argc < 2) // Se tiver menos de 2 args, só tem o nome do arquivo
		return (ft_error());
	if (argc < 3) // Nesse caso, ele só digitou um número //verificar quando só tem 1 arg(numero)
		return (ft_error()); // Mensagem de erro dividida em 2 comandos por conta de norma ヽ(ヅ)ノ
	// Se passou dessa line, vamos ao menos verificar os args
	only_numbers = ft_is_only_numbers(++argv); // Verifica item por item
	if (only_numbers == 1) // Se entrar nesse if, deu ruim, tem algo que não é número
		return (ft_error());
	// Passando daqui, só tem números
	ft_create_vector(--argc, argv); // Aqui vamos colocar todos os números na stack, um por um
	return (0);
}
