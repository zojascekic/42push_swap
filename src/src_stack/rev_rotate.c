/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:25:11 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/02 11:24:53 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	add_front(stack, last);
}

void	rra(t_node **stack_a, t_config *config)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	config->rra_count += 1;
}

void	rrb(t_node **stack_b, t_config *config)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	config->rrb_count += 1;
}

void	rrr(t_node **stack_a, t_node **stack_b, t_config *config)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	config->rrr_count += 1;
}

// int	main(void)
// {
// 	t_node	*list;
// 	t_node	*temp;
// 	t_node	*temp2;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;

// 	list = NULL;
// 	node1 = create_node(1);
// 	node2 = create_node(2);
// 	node3 = create_node(3);

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
// 	reverse_rotate(&temp2);
// 	while (temp2 != NULL)
// 	{
// 		printf("content: %i\n", (int)temp2->content);
// 		temp2 = temp2->next;
// 	}
// }
