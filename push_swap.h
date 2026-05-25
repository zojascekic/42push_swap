/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:06:12 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/26 11:04:00 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// src_stack - stack_utils
t_node	*create_node(int content);
void	add_back(t_node **stack, t_node *new_node);
void	add_front(t_node **lst, t_node *new);
int		get_stack_size(t_node *stack);
void	free_stack(t_node **stack);

// src_stack - swap
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

// src_stack - push
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

// src_stack - rotate
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

// src_stack - reverse rotate

// input - utils
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*get_mode(int argc, char **argv);
int		get_bench(int argc, char **argv);
int		get_flags_num(int argc, char **argv);

// input - input_validation
int		*validate_input(int argc, char **argv, char **mode, int *bench);