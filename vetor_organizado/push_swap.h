/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:09:11 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/17 19:50:08 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft42/libft.h"
# include "defines.h"

struct s_stack
{
	int	*numbers;
	int	*indexes;
	int	last;
};
typedef struct s_stack t_stack;

void	free_matrix(char **matrix);

void	ft_swap_a(t_stack *a);
void	ft_rotate_a(t_stack *a);
void	ft_reverse_rotate_a(t_stack *a);
void	ft_push_a(t_stack *a, t_stack *b);

void	ft_swap_b(t_stack *b);
void	ft_rotate_b(t_stack *b);
void	ft_reverse_rotate_b(t_stack *b);
void	ft_push_b(t_stack *b, t_stack *a);

void	ft_swap_swap(t_stack *a, t_stack *b);
void	ft_rotate_rotate(t_stack *a, t_stack *b);
void	ft_reverse_rotate_rotate(t_stack *a, t_stack *b);

void	ft_checker(t_stack *a, t_stack *b, int numbers);
void	ft_sort_for_3(t_stack *a);
void	ft_sort_for_5(t_stack *a, t_stack *b);
void	ft_sort_more_5(t_stack *a, t_stack *b, int nums_stack);
int		ft_ret_bigger(t_stack *a);
int		ft_ret_bigger_binary(t_stack *a);
int		ft_ret_pos_smaller(t_stack *a);

int		ft_error(void);
void	ft_define_index(t_stack *a, int args);
int		ft_malloc(int **vector, int args);
int		ft_alloc_stack(t_stack *a, t_stack *b, int args);
void	ft_create_vector(int argc, char **args);
int		ft_is_only_numbers(char **arg);
int		ft_check_repeat_num(t_stack *a);
void	ft_free(t_stack *a, t_stack *b);
int		ft_is_only_numbers(char **arg);
long	ft_atoi_plus(const char *nptr);

#endif