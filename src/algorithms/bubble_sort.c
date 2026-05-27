/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:10:28 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/27 14:18:16 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

// void	bubble_sort(int *arr, int size, int bench)
// {
// 	char	**operations;
// 	t_node	*stack_a;
// 	t_node	*stack_b;

// }

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_config	config;

	if (argc < 2)
		return (0);
	config = (t_config){0};
	stack_a = get_stack(argc, argv, &config);
	if (!stack_a)
	{
		printf("Error\n");
		return (0);
	}
	printf("bench: %i\n", config.bench);
	printf("mode: %s\n", config.mode);
	printf("%i\n", stack_a->content);
	printf("%i\n", stack_a->next->content);
	printf("%i\n", stack_a->next->next->content);
	// bubble_sort(stack_a, argc - 1, 0);
	return (0);
}
