/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:23:55 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/27 14:26:46 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	*validate_input(int argc, char **argv, t_config *config)
{
	int		*values;
	int		flags_num;
	char	**numbers;

	if (argc < 2)
		return (NULL);
	config->mode = get_mode(argc, argv);
	if (!(*config->mode))
		return (NULL);
	config->bench = get_bench(argc, argv);
	if (config->bench == -1)
		return (NULL);
	flags_num = get_flags_num(argc, argv);
	numbers = split_numbers(argc, argv, flags_num);
	if (!numbers)
		return (NULL);
	config->int_num = count_elements_in_array(numbers);
	values = convert_to_int(argc, numbers, config->int_num);
	free(numbers);
	if (!values)
		return (NULL);
	if (has_duplicates(values, config->int_num))
		return (free(values), NULL);
	return (values);
}

t_node	*get_stack(int argc, char **argv, t_config *config)
{
	int		*values;
	t_node	*stack_a;
	t_node	*node;
	int		i;

	values = validate_input(argc, argv, config);

	stack_a = NULL;

	if (!values)
		return (NULL);

	i = 0;

	while (i < config->int_num)
	{
		node = create_node(values[i]);
		add_back(&stack_a, node);
		i++;
	}

	return (stack_a);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	int		*values;
// 	char	*mode;
// 	int		bench;
// 	int		i;

// 	if (argc < 2)
// 		return (0);
// 	values = validate_input(argc, argv, &mode, &bench);
// 	if (!values)
// 		printf("Error\n");
// 	else
// 	{
// 		printf("mode = %s\n", mode);
// 		printf("bench = %d\n", bench);
// 		i = 0;
// 		while (i < 15)
// 		{
// 			printf("%d\n", values[i]);
// 			i++;
// 		}
// 		free(values);
// 	}
// 	return (0);
// }
