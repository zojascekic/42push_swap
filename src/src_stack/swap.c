/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:24:45 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/01 15:30:02 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_node **stack_a, t_config *config)
{
	swap(stack_a);
	if (config->bench != 1)
		write(1, "sa\n", 3);
	config->sa_count += 1;
}

void	sb(t_node **stack_b, t_config *config)
{
	swap(stack_b);
	if (config->bench != 1)
		write(1, "sb\n", 3);
	config->sb_count += 1;
}

void	ss(t_node **stack_a, t_node **stack_b, t_config *config)
{
	swap(stack_a);
	swap(stack_b);
	if (config->bench != 1)
		write(1, "ss\n", 3);
	config->ss_count += 1;
}
