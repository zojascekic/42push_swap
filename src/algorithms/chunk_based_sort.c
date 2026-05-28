/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:01:56 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/28 14:12:42 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// todo!

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
