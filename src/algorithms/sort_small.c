/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:03:32 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/02 16:13:03 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_min_index(t_node *stack_a)
{
	int	min_index;

	min_index = stack_a->index;
	while (stack_a != NULL)
	{
		if (stack_a->index < min_index)
			min_index = stack_a->index;
		stack_a = stack_a->next;
	}
	return (min_index);
}

static void	push_min_to_b(t_node **stack_a, t_node **stack_b,
	t_config *config, int size)
{
	int		min_index;
	int		min_pos;
	t_node	*temp;

	temp = *stack_a;
	min_index = get_min_index(*stack_a);
	min_pos = 0;
	while (temp != NULL && temp->index != min_index)
	{
		min_pos++;
		temp = temp->next;
	}
	while ((*stack_a)->index != min_index)
	{
		if (min_pos <= size / 2)
			ra(stack_a, config);
		else
			rra(stack_a, config);
	}
	pb(stack_a, stack_b, config);
}

static void	sort_three(t_node **stack_a, t_config *config)
{
	int	top;
	int	mid;
	int	bot;

	bot = (*stack_a)->next->next->index;
	mid = (*stack_a)->next->index;
	top = (*stack_a)->index;

	if (top < mid && mid > bot && top < bot)
	{
		sa(stack_a, config);
		ra(stack_a, config);
	}
	else if (top > mid && mid < bot && top < bot)
		sa(stack_a, config);
	else if (top < mid && mid > bot && top > bot)
		rra(stack_a, config);
	else if (top > mid && mid < bot && top > bot)
		ra (stack_a, config);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(stack_a, config);
		rra(stack_a, config);
	}
}

static void	sort_five(t_node **stack_a, t_node **stack_b,
	t_config *config, int size)
{
	if (size == 4)
	{
		push_min_to_b(stack_a, stack_b, config, size);
		sort_three(stack_a, config);
		pa(stack_a, stack_b, config);
	}
	else if (size == 5)
	{
		push_min_to_b(stack_a, stack_b, config, size);
		push_min_to_b(stack_a, stack_b, config, size - 1);
		sort_three(stack_a, config);
		pa(stack_a, stack_b, config);
		pa(stack_a, stack_b, config);
	}
}

void	sort_small(t_node **stack_a, t_node **stack_b, t_config *config)
{
	int	size;

	assign_index(*stack_a);
	size = get_stack_size(*stack_a);
	if (size == 2 && (*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, config);
	else if (size == 3)
		sort_three(stack_a, config);
	else if (size == 4 || size == 5)
		sort_five(stack_a, stack_b, config, size);
}
