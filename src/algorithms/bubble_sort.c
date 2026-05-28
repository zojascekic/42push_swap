/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:10:28 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/28 11:38:31 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

// void	bubble_sort(t_node *a, t_config config)
// {
// 	int	swapped;
// 	int	i;

// 	while (swapped)
// 	{
// 		swapped = 0;
// 		i = 0;
// 		while (i < size(a) - 1)
// 		{
// 			if (a->content > a->next->content)
// 			{
// 				sa(a);
// 				swapped = 1;
// 			}
// 			ra(a);
// 			i++;
// 		}
// 		while (i--)
// 			rra(a);
// 	}
// 	printf("%i\n", a->content);
// 	printf("%i\n", a->next->content);
// 	printf("%i\n", a->next->next->content);
// 	printf("%i\n", a->next->next->next->content);
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
	// bubble_sort(stack_a, config);
	return (0);
}
