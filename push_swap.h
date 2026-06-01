/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:06:12 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/01 14:56:16 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_config
{
	int		bench;
	char	*mode;
	int		int_num;
	int		pa_count;
	int		pb_count;
	int		sa_count;
	int		sb_count;
	int		ss_count;
	int		ra_count;
	int		rb_count;
	int		rr_count;
	int		rra_count;
	int		rrb_count;
	int		rrr_count;
}	t_config;

// src_stack - stack_utils
t_node	*create_node(int content);
void	add_back(t_node **stack, t_node *new_node);
void	add_front(t_node **lst, t_node *new);
int		get_stack_size(t_node *stack);
void	free_stack(t_node **stack);

// src_stack - swap
void	sa(t_node **stack_a, t_config config);
void	sb(t_node **stack_b, t_config config);
void	ss(t_node **stack_a, t_node **stack_b, t_config config);

// src_stack - push
void	pa(t_node **stack_a, t_node **stack_b, t_config config);
void	pb(t_node **stack_a, t_node **stack_b, t_config config);

// src_stack - rotate
void	ra(t_node **stack_a, t_config config);
void	rb(t_node **stack_b, t_config config);
void	rr(t_node **stack_a, t_node **stack_b, t_config config);

// src_stack - reverse rotate
void	rra(t_node **stack_a, t_config config);
void	rrb(t_node **stack_b, t_config config);
void	rrr(t_node **stack_a, t_node **stack_b, t_config config);

// input - utils
char	*get_mode(int argc, char **argv);
int		get_bench(int argc, char **argv);
int		get_flags_num(int argc, char **argv);
int		count_elements_in_array(char **array);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		count_words(char const *s, char c);
char	**ft_split(const char *s, char c);
char	**split_numbers(int argc, char **argv, int flags_num);
int		*convert_to_int(char **numbers, int int_num);
int		has_duplicates(int *values, int int_num);
void	free_all(char **res, int i);

// input - input_validation
t_node	*get_stack(int argc, char **argv, t_config *config);

// algorithms
void	bubble_sort(t_node **a, t_config config);
void	assign_index(t_node *stack);
void	chunk_sort(t_node **stack_a, t_node **stack_b, t_config config);
void	radix_sort(t_node **a, t_node **b, t_config config);
void	adaptive(t_node **stack_a, t_node **stack_b, t_config config);

// disorder
double	compute_disorder(t_node *stack_a);

// benchmark
void	benchmark_summary(double disorder, t_config config);
#endif
