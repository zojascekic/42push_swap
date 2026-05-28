/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:26:39 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/28 16:08:02 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

void	merge(t_node *a, t_node *b, t_config config)
{
	int	size_a;
	int	size_b;
	int	i;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	while (i < size_a && i < size_a)
	{
		if (a->content < b->content)
			pa(a, b, config);
		else
			pb(a, b, config);
		i++;
	}
}

void	merge_sort(t_node *a, t_node *b, t_config config)
{
	int	size_a;
	int	i;

	size_a = get_stack_size(a);
	if (size_a == 1)
		return ;
	i = 0;
	while (i < size_a / 2)
	{
		pb(&a, &b, config);
		i++;
	}
	merge_sort(a, b, config);
	merge_sort(b, a, config);
	merge(a, b, config);
}

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
		printf("Error\n");
		return (0);
	}
	stack_b = NULL;
	merge_sort(stack_a, stack_b, config);
	return (0);
}
