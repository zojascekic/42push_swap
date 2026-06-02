/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 09:54:05 by dvasilev          #+#    #+#             */
/*   Updated: 2026/06/01 18:42:15 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

static int	get_max_bit_num(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a != NULL)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while (max >> bits != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b, t_config *config)
{
	int	max_bits;
	int	bit;
	int	i;

	assign_index(*a);
	max_bits = get_max_bit_num(*a);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < config->size)
		{
			if ((((*a)->index >> bit) & 1) == 0)
				pb(a, b, config);
			else
				ra(a, config);
			i++;
		}
		while (*b)
			pa(a, b, config);
		bit++;
	}
}

// int	main(int argc, char **argv)
// {
// 	t_node		*stack_a;
// 	t_node		*stack_b;
// 	t_config	config;

// 	if (argc < 2)
// 		return (0);
// 	config = (t_config){0};
// 	stack_a = get_stack(argc, argv, &config);
// 	if (!stack_a)
// 	{
// 		printf("Error\n");
// 		return (0);
// 	}
// 	stack_b = NULL;
// 	radix_sort(&stack_a, &stack_b, &config);
// 	// int a;
// 	// a = 21; //101010
// 	// printf("a >> 1: %d\n", a >> 0);
// 	// printf("a >> 1: %d\n", a >> 1);
// 	// printf("a >> 1: %d\n", a >> 2);
// 	// printf("a >> 1: %d\n", a >> 3);
// 	// printf("a >> 1: %d\n", a >> 4);
// 	// printf("a >> 1: %d\n", a >> 5);
// 	return (0);
// }
