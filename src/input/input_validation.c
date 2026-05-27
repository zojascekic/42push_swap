/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:23:55 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/27 11:50:48 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	*validate_input(int argc, char **argv, char **mode, int *bench)
{
	int		*values;
	int		flags_num;
	int		int_num;
	char	**numbers;

	if (argc < 2)
		return (NULL);
	*mode = get_mode(argc, argv);
	if (!(*mode))
		return (NULL);
	*bench = get_bench(argc, argv);
	if (*bench == -1)
		return (NULL);
	flags_num = get_flags_num(argc, argv);
	numbers = split_numbers(argc, argv, flags_num);
	if (!numbers)
		return (NULL);
	int_num = count_elements_in_array(numbers);
	values = convert_to_int(argc, numbers, int_num);
	free(numbers);
	if (!values)
		return (NULL);
	if (has_duplicates(values, int_num))
		return (free(values), NULL);
	return (values);
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
