/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:24:43 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/03 14:54:05 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_back(t_node **stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
}

void	add_front(t_node **stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

int	get_stack_size(t_node *stack)
{
	int		res;
	t_node	*temp;

	res = 0;
	temp = stack;
	while (temp != NULL)
	{
		res ++;
		temp = temp->next;
	}
	return (res);
}

void	free_stack(t_node **stack)
{
	t_node	*current_n;
	t_node	*next_n;

	if (!stack)
		return ;
	current_n = *stack;
	while (current_n)
	{
		next_n = current_n->next;
		free(current_n);
		current_n = next_n;
	}
	*stack = NULL;
}
