/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:10:28 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/27 12:02:50 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// char	**bubble_sort(int *arr, int size, int bench)
// {
// 	char	**operations;
// 	t_node	*stack_a;
// 	t_node	*stack_b;

// 	return (operations);
// }

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*values;
	char	*mode;
	int		bench;
	char	**operations;
	t_node	*stack_a;
	t_node	*temp;
	int		i;
	t_node	*node;

	if (argc < 2)
		return (0);
	values = validate_input(argc, argv, &mode, &bench);
	if (!values)
	{
		printf("Error\n");
		return (0);
	}
	i = 0;
	stack_a = NULL;
	while (i < 2)
	{
		node = create_node(values[i]);
		add_back(&stack_a, node);
		i++;
	}
	temp = stack_a;
	while (temp != NULL)
	{
		printf("content: %i\n", (int)temp->content);
		temp = temp->next;
	}

	// operations = bubble_sort(values, argc - 1);

	return (0);
}
