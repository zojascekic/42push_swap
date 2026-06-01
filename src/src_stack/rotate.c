/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:25:13 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/01 15:29:17 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	add_back(stack, first);
}

void	ra(t_node **stack_a, t_config *config)
{
	rotate(stack_a);
	if (config->bench != 1)
		write(1, "ra\n", 3);
	config->ra_count += 1;
}

void	rb(t_node **stack_b, t_config *config)
{
	rotate(stack_b);
	if (config->bench != 1)
		write(1, "rb\n", 3);
	config->rb_count += 1;
}

void	rr(t_node **stack_a, t_node **stack_b, t_config *config)
{
	rotate(stack_a);
	rotate(stack_b);
	if (config->bench != 1)
		write(1, "rr\n", 3);
	config->rr_count += 1;
}
