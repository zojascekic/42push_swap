/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:14:40 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/02 10:18:56 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	write_disorder_percentage(double disorder)
{
	int		int_part;
	float	float_part;

	int_part = (int)(disorder * 100);
	float_part = (int)(((disorder * 100) - int_part) * 100 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(int_part, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd(float_part, 2);
	ft_putendl_fd("%", 2);
}

static void	write_strategy(t_config config, double disorder)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (ft_strcmp(config.strategy, "simple") == 0)
		ft_putendl_fd("Simple / O(n^2)", 2);
	else if (ft_strcmp(config.strategy, "medium") == 0)
		ft_putendl_fd("Medium / O(n√n)", 2);
	else if (ft_strcmp(config.strategy, "complex") == 0)
		ft_putendl_fd("Complex / O(n log n)", 2);
	else if (ft_strcmp(config.strategy, "adaptive") == 0)
	{
		if (disorder < 0.2)
			ft_putendl_fd("Adaptive / O(n^2)", 2);
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_putendl_fd("Adaptive / O(n√n)", 2);
		else
			ft_putendl_fd("Adaptive / O(n log n)", 2);
	}
}

static void	print_op_count(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd(' ', 2);
}

static void	write_operations_count(t_config config)
{
	int	sum;

	sum = config.pa_count + config.pb_count + config.ra_count + config.rb_count
		+ config.rr_count + config.rra_count + config.rrb_count
		+ config.rrr_count + config.sa_count + config.sb_count
		+ config.ss_count;
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(sum, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_op_count("sa", config.sa_count);
	print_op_count("sb", config.sb_count);
	print_op_count("ss", config.ss_count);
	print_op_count("pa", config.pa_count);
	print_op_count("pb", config.pb_count);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_op_count("ra", config.ra_count);
	print_op_count("rb", config.rb_count);
	print_op_count("rr", config.rr_count);
	print_op_count("rra", config.rra_count);
	print_op_count("rrb", config.rrb_count);
	print_op_count("rrr", config.rrr_count);
	ft_putchar_fd('\n', 2);
}

void	benchmark_summary(double disorder, t_config *config)
{
	write_disorder_percentage(disorder);
	write_strategy(*config, disorder);
	write_operations_count(*config);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_config	config;

// 	config.strategy = "adaptive";
// 	benchmark_summary(0.413518, &config);
// }
