/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:17:41 by dvasilev          #+#    #+#             */
/*   Updated: 2026/06/01 16:28:32 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_config	config;

	if (argc < 2)
		return (0);
	config = (t_config){0};
	stack_a = get_stack(argc, argv, &config);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_b = NULL;
	if (ft_strcmp(config.mode, "simple") == 0)
		bubble_sort(&stack_a, &config);
	else if (ft_strcmp(config.mode, "medium") == 0)
		chunk_sort(&stack_a, &stack_b, &config);
	else if (ft_strcmp(config.mode, "complex") == 0)
		radix_sort(&stack_a, &stack_b, &config);
	else if (ft_strcmp(config.mode, "adaptive") == 0)
		adaptive(&stack_a, &stack_b, &config);
	if (config.bench == 1)
		benchmark_summary(compute_disorder(stack_a), &config);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
