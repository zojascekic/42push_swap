/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:01:56 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/29 11:59:51 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// todo - chunk_based_sort

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

static int	get_chunk_size(int stack_size)
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

static void	scan_and_push(t_node **stack_a, t_node **stack_b, t_config config)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = get_chunk_size(get_stack_size(*stack_a));
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

static void	push_to_a(t_node **stack_a, t_node **stack_b, t_config config)
{
	int		max_index;
	int		max_pos;
	int		current_pos;
	t_node	*temp;
	int		stack_size;

	while ((*stack_b) != NULL)
	{
		max_index = -1;
		max_pos = 0;
		current_pos = 0;
		temp = *stack_b;
		stack_size = get_stack_size(*stack_b);
		while (temp != NULL)
		{
			if (temp->index > max_index)
			{
				max_index = temp->index;
				max_pos = current_pos;
			}
			current_pos += 1;
			temp = temp->next;
		}
		if (max_pos <= stack_size / 2)
		{
			while (max_pos > 0)
			{
				rb(stack_b, config);
				max_pos --;
			}
		}
		else
		{
			while (max_pos < stack_size)
			{
				rrb(stack_b, config);
				max_pos ++;
			}
		}
		pa(stack_a, stack_b, config);
	}
}

// void	chunk_sort(t_node **stack_a, t_node **stack_b, t_config config)
// {
// }

// #include <stdio.h>

// int	main(void)
// {
// 	t_node	*list;
// 	t_node	*temp2;
// 	t_node	*temp3;
// 	t_node	*print_ptr;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;
// 	t_config	config;

// 	list = NULL;
// 	node1 = create_node(1);
// 	node2 = create_node(-2);
// 	node3 = create_node(-5);
// 	add_front(&list, node1);
// 	add_front(&list, node2);
// 	add_front(&list, node3);
// 	assign_index(list);
// 	temp2 = list;
// 	temp3 = NULL;
// 	scan_and_push(&temp2, &temp3, config);
// 	print_ptr = temp3;
// 	while (print_ptr != NULL)
// 	{
// 		printf("content2: %i\n", (int)print_ptr->content);
// 		print_ptr = print_ptr->next;
// 	}
// 	push_to_a(&temp2, &temp3, config);
// 	print_ptr = temp2;
// 	while (print_ptr != NULL)
// 	{
// 		printf("a after pta: %i\n", (int)print_ptr->content);
// 		print_ptr = print_ptr->next;
// 	}
// }
