/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:23:55 by dvasilev          #+#    #+#             */
/*   Updated: 2026/06/01 16:23:19 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

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
	values = convert_to_int(numbers, config->int_num);
	free_str_array(numbers);
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
		if (!node)
		{
			free(values);
			free_stack(&stack_a);
			return (NULL);
		}
		add_back(&stack_a, node);
		i++;
	}
	free(values);
	return (stack_a);
}
// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	t_node		*stack_a;
// 	t_node		*stack_b;
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
// 	printf("mode = %s\n", config.mode);
// 	printf("bench = %d\n", config.bench);
// 	while (stack_a != NULL)
// 	{
// 		printf("%d\n", stack_a->content);
// 		stack_a = stack_a->next;
// 	}
// 	return (0);
// }
