/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:10:28 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/27 13:35:17 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

void	bubble_sort(int *arr, int size, int bench)
{
	char	**operations;
	t_node	*stack_a;
	t_node	*stack_b;

}

int	main(int argc, char **argv)
{
	int		*values;
	char	*mode;
	int		bench;
	t_node	*stack_a;
	t_node	*temp;
	int		i;
	t_node	*node;
	t_config	config;

	if (argc < 2)
		return (0);
	values = validate_input(argc, argv, &mode, &bench);
	if (!values)
	{
		printf("Error\n");
		return (0);
	}
	config.bench = bench;
	config.mode = mode; //TODO: ft_strdub ??
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

	bubble_sort(values, argc - 1, 0);
	return (0);
}
