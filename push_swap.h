/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:06:12 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/24 13:28:53 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
int		get_stack_size(t_node *stack);
void	free_stack(t_node **stack);

// src_stack - swap
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

// input - utils
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*get_mode(int argc, char **argv);
int		get_bench(int argc, char **argv);

// input - input_validation
int		*validate_input(int argc, char **argv, char **mode, int *bench);