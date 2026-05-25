/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:23:55 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/25 16:14:27 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_overflow(long num, char digit, int sign)
{
	if (sign == 1)
	{
		if (num > INT_MAX / 10
			|| (num == INT_MAX / 10 && (digit - '0') > INT_MAX % 10))
			return (1);
	}
	else
	{
		if (num > -(INT_MIN / 10)
			|| (num == -(INT_MIN / 10)
				&& (digit - '0') > -(INT_MIN % 10)))
			return (1);
	}
	return (0);
}

static int	valid_num(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (check_overflow(num, str[i], sign))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

static int	*get_values(int argc, char **argv, int int_num)
{
	int	i;
	int	j;
	int	*values;

	if (int_num <= 0)
		return (NULL);
	values = malloc(sizeof(int) * int_num);
	if (!values)
		return (NULL);
	j = 0;
	i = argc - int_num;
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

static int	has_duplicates(int *values, int int_num)
{
	int	i;
	int	j;

	i = 0;
	while (i < int_num)
	{
		j = i + 1;
		while (j < int_num)
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
	int	flags_num;
	int	int_num;

	if (argc < 2)
		return (NULL);
	*mode = get_mode(argc, argv);
	if (!(*mode))
		return (NULL);
	*bench = get_bench(argc, argv);
	if (*bench == -1)
		return (NULL);
	flags_num = get_flags_num(argc, argv);
	int_num = argc - (flags_num + 1);
	values = get_values(argc, argv, int_num);
	if (!values)
		return (NULL);
	if (has_duplicates(values, int_num))
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
	int		int_num;

	values = validate_input(argc, argv, &mode, &bench);
	if (!values)
		printf("error\n");
	else
	{
		printf("mode = %s\n", mode);
		printf("bench = %d\n", bench);
		int_num = argc - (get_flags_num(argc, argv) + 1);
		i = 0;
		while (i < int_num)
		{
			printf("%d\n", values[i]);
			i++;
		}
		free(values);
	}
	return (0);
}
//TODO - handle "" (maybe just delete all quotes in the input before processing?)
// + TODO - should 01 be valid? now it is valid
// + TODO - if greater than min int or less than max int - return error
// + TODO - check for duplicates (can it be O(n^2) or should it be O(n))
// + what if flag in the middle? -> error