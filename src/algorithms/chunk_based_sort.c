/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:01:56 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/28 15:54:40 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// todo - push_to_a and chunk_based_sort

static void	assign_index(t_node *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack;
	while (current != NULL)
	{
		current->index = 0;
		compare = stack;
		while (compare != NULL)
		{
			if (compare->content < current->content)
			{
				current->index += 1;
			}
			compare = compare->next;
		}
		current = current->next;
	}
}

static int	chunk_size(int stack_size)
{
	if (stack_size <= 16)
		return (stack_size / 2);
	if (stack_size <= 100)
		return (23);
	if (stack_size <= 500)
		return (45);
	else
		return (60);
}

static void	scan_and_push(t_node **stack_a, t_node **stack_b,
	int chunk_size, t_config config)
{
	int	i;

	i = 0;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, config);
			i ++;
		}
		else if ((*stack_a)->index <= i + chunk_size)
		{
			pb(stack_a, stack_b, config);
			rb(stack_b, config);
			i ++;
		}
		else
			ra(stack_a, config);
	}
}
// to revise
// static void	push_to_a(t_node **stack_a, t_node **stack_b, t_config config)
// {
// 	int		max_index;
// 	int		max_pos;
// 	int		current_pos;
// 	t_node	*temp;
// 	int		stack_size;

// 	max_index = -1;
// 	max_pos = 0;
// 	current_pos = 0;
// 	temp = *stack_b;
// 	stack_size = get_stack_size(stack_b);

// 	while (temp != NULL)
// 	{
// 		if (temp->index > max_index)
// 		{
// 			max_index = temp->index;
// 			max_pos = current_pos;
// 		}
// 		current_pos += 1;
// 		temp = temp->next;
// 	}
// 	while (max_pos != 0)
// 	{
// 		if (max_pos <= stack_size / 2)
// 		{
// 			rb(stack_b, config);
// 			max_pos --;
// 		}
// 		else
// 			rrb(stack_b, config);
// 	}
// 	pa(stack_a, stack_b, config);
// }

// void	chunk_sort(t_node **stack_a, t_node **stack_b, t_config config)
// {
// }

// #include <stdio.h>

// int	main(void)
// {
// 	t_node	*list;
// 	t_node	*temp;
// 	t_node	*temp2;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;

// 	list = NULL;
// 	node1 = create_node(4);
// 	node2 = create_node(-2);
// 	node3 = create_node(5);

// 	add_front(&list, node1);
// 	add_front(&list, node2);
// 	add_front(&list, node3);
// 	temp = list;
// 	while (temp != NULL)
// 	{
// 		printf("content: %i\n", (int)temp->content);
// 		temp = temp->next;
// 	}
// 	temp2 = list;
// 	assign_index(temp2);
// 	while (temp2 != NULL)
// 	{
// 		printf("content: %i\n", (int)temp2->index);
// 		temp2 = temp2->next;
// 	}
// }
