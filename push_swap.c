/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:17:41 by dvasilev          #+#    #+#             */
/*   Updated: 2026/06/01 12:23:13 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (0);
	}
	if (config.mode == "simple")
		bubble_sort(stack_a, config);
	else if (config.mode == "medium")
		chunk_sort(stack_a, stack_b, config);
	else if (config.mode == "complex")
		radix_sort(stack_a, stack_b, config);
	else if (config.mode == "adaptive")
		adaptive(stack_a, stack_b, config);
	// if (config.bench == 1)
		// benchmark_summary(config);
	return (0);
}
