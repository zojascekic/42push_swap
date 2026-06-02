/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:17:41 by dvasilev          #+#    #+#             */
/*   Updated: 2026/06/02 11:30:00 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*sort(t_node **stack_a, t_node **stack_b,
		t_config *config, double disorder)
{
	if (ft_strcmp(config->strategy, "simple") == 0)
		bubble_sort(stack_a, config);
	else if (ft_strcmp(config->strategy, "medium") == 0)
		chunk_sort(stack_a, stack_b, config);
	else if (ft_strcmp(config->strategy, "complex") == 0)
		radix_sort(stack_a, stack_b, config);
	else if (ft_strcmp(config->strategy, "adaptive") == 0)
		adaptive(stack_a, stack_b, config, disorder);
	if (config->bench == 1)
		benchmark_summary(disorder, config);
	return (*stack_a);
}

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_config	config;
	double		disorder;

	if (argc < 2)
		return (0);
	config = (t_config){0};
	stack_a = get_stack(argc, argv, &config);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	disorder = compute_disorder(stack_a);
	if (disorder == 0.0)
	{
		free_stack(&stack_a);
		return (0);
	}
	stack_b = NULL;
	sort(&stack_a, &stack_b, &config, disorder);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
