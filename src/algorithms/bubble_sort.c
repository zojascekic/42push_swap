/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:10:28 by dvasilev          #+#    #+#             */
/*   Updated: 2026/06/01 13:50:32 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

void	bubble_sort(t_node **a, t_config config)
{
	int	swapped;
	int	i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < config.int_num - 1)
		{
			if ((*a)->content > (*a)->next->content)
			{
				sa(a, config);
				swapped = 1;
			}
			ra(a, config);
			i++;
		}
		while (i--)
			rra(a, config);
	}
}

// int	main(int argc, char **argv)
// {
// 	t_node		*stack_a;
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
// 	bubble_sort(stack_a, config);
// 	return (0);
// }
