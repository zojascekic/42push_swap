/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:23:55 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/25 12:14:26 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	*get_values(int argc, char **argv)
{
	int	i;
	int	j;
	int	*values;
	int	start;

	start = 1;
	if (argc <= 1)
		return (NULL);
	values = malloc(sizeof(int) * (argc - start));
	if (!values)
		return (NULL);
	i = start;
	j = 0;
	while (i < argc)
	{
		if (!valid_num(argv[i]))
			return (free(values), NULL);
		values[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
	return (values);
}

static int	duplicates(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*validate_input(int argc, char **argv, char **mode, int *bench)
{
	int	*values;

	if (argc < 2)
		return (NULL);
	*mode = get_mode(argc, argv);
	if (!(*mode))
		return (NULL);
	*bench = get_bench(argc, argv);
	if (*bench == -1)
		return (NULL);
	values = get_values(argc, argv);
	if (duplicates(values, argc))
		return (free(values), NULL);
	return (values);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int		*values;
	char	*mode;
	int		bench;
	int		i;

	values = validate_input(argc, argv, &mode, &bench);

	if (!values)
		printf("error\n");
	else
	{
		printf("mode = %s\n", mode);
		printf("bench = %d\n", bench);
		i = 0;
		while (i < argc - 1)
		{
			printf("%d\n", values[i]);
			i++;
		}
		free(values);
	}
	return (0);
}
//TODO - handle "" (maybe just delete all quotes in the input before processing?)
//TODO - should 01 be valid?
//TODO - if greater than min int or less than max int - return error
// + TODO - check for duplicates (can it be O(n^2) or should it be O(n))