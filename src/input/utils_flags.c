/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:27:07 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/26 10:27:34 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

int	get_flags_num(int argc, char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0
			|| ft_strcmp(argv[i], "--medium") == 0
			|| ft_strcmp(argv[i], "--complex") == 0
			|| ft_strcmp(argv[i], "--adaptive") == 0
			|| ft_strcmp(argv[i], "--bench") == 0)
			count++;
		i++;
	}
	return (count);
}
