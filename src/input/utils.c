/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:25:53 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/26 11:14:12 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_int_num(int argc, char **argv, int flags_num)
{
	int	i;
	int	int_num;

	i = flags_num + 1;
	int_num = 0;
	while (i < argc)
		int_num += count_words(argv[i++], ' ');
	return (int_num);
}

char	**split_numbers(int argc, char **argv, int flags_num)
{
	char	**res;
	char	**splited;
	int		i_arg;
	int		i_res;
	int		i_splited;

	res = malloc(sizeof(char *)
			* (get_int_num(argc, argv, flags_num) + 1));
	if (!res)
		return (NULL);
	i_arg = flags_num + 1;
	i_res = 0;
	while (i_arg < argc)
	{
		splited = ft_split(argv[i_arg++], ' ');
		if (!splited)
			return (free_all(res, i_res), NULL);
		i_splited = 0;
		while (splited[i_splited])
			res[i_res++] = splited[i_splited++];
		free(splited);
	}
	res[i_res] = NULL;
	return (res);
}

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

static int	check_is_valid_num(char *str)
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

int	*convert_to_int(int argc, char **numbers, int int_num)
{
	int		i;
	int		j;
	int		*values;

	if (int_num <= 0)
		return (NULL);
	values = malloc(sizeof(int) * int_num);
	if (!values)
		return (NULL);
	j = 0;
	i = 0;
	while (i < int_num)
	{
		if (!check_is_valid_num(numbers[i]))
			return (free(values), NULL);
		values[j] = ft_atoi(numbers[i]);
		j++;
		i++;
	}
	return (values);
}
