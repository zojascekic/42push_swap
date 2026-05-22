/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:06:12 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/22 15:07:25 by zscekic          ###   ########.fr       */
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
