/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:25:53 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/24 14:49:49 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	sign;

	sign = 1;
	i = 0;
	number = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*get_mode(int argc, char **argv)
{
	int		i;
	char	*mode;

	i = 1;
	mode = NULL;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0 && !mode)
			mode = "simple";
		else if (ft_strcmp(argv[i], "--medium") == 0 && !mode)
			mode = "medium";
		else if (ft_strcmp(argv[i], "--complex") == 0 && !mode)
			mode = "complex";
		else if (ft_strcmp(argv[i], "--adaptive") == 0 && !mode)
			mode = "adaptive";
		else if (mode && (ft_strcmp(argv[i], "--simple") == 0
				|| ft_strcmp(argv[i], "--medium") == 0
				|| ft_strcmp(argv[i], "--complex") == 0
				|| ft_strcmp(argv[i], "--adaptive") == 0))
			return (NULL);
		i++;
	}
	if (!mode)
		return ("adaptive");
	return (mode);
}

int	get_bench(int argc, char **argv)
{
	int	i;
	int	bench;

	i = 1;
	bench = 0;

	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
		{
			if (bench == 1)
				return (-1);
			bench = 1;
		}
		i++;
	}
	return (bench);
}
