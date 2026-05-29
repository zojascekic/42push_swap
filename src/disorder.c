/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:36:29 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/29 14:12:05 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	compute_disorder(t_node *stack_a)
{
	t_node	*i_node;
	t_node	*j_node;
	int		mistakes;
	int		total_pairs;

	if (!stack_a || !(stack_a->next))
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i_node = stack_a;
	while (i_node != NULL)
	{
		j_node = i_node->next;
		while (j_node != NULL)
		{
			total_pairs ++;
			if (i_node->content > j_node->content)
				mistakes += 1;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_node	*list;
// 	t_node	*temp;
// 	t_node	*print_ptr;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;
// 	t_node	*node4;
// 	t_config	config;
// 	double	disorder;

// 	list = NULL;
// 	node1 = create_node(1);
// 	node2 = create_node(3);
// 	node3 = create_node(-5);
// 	node4 = create_node(-15);
// 	add_front(&list, node1);
// 	add_front(&list, node2);
// 	add_front(&list, node3);
// 	add_front(&list, node4);
// 	disorder = compute_disorder(list);
// 	temp = list;
// 	print_ptr = temp;
// 	while (print_ptr != NULL)
// 	{
// 		printf("node content: %i\n", (int)print_ptr->content);
// 		print_ptr = print_ptr->next;
// 	}
// 	printf("disorder %f", disorder);
// }
