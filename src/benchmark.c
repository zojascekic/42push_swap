/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:14:40 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/01 14:43:30 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	write_disorder_percentage(double disorder)
{
	int		int_part;
	float	float_part;

	int_part = (int)(disorder * 100);
	float_part = (int)(((disorder * 100) - int_part) * 100 + 0.5);
	ft_putnbr_fd(int_part, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd(float_part, 2);
	ft_putendl_fd("%", 2);
}

static void	write_strategy(t_config config, double disorder)
{
	if (ft_strcmp(config.mode, "simple"))
		ft_putendl_fd("Simple / O(n^2)", 2);
	else if (ft_strcmp(config.mode, "medium"))
		ft_putendl_fd("Medium / O(n√n)", 2);
	else if (ft_strcmp(config.mode, "complex"))
		ft_putendl_fd("Complex / O(n log n)", 2);
	else if (ft_strcmp(config.mode, "adaptive"))
	{
		if (disorder < 0.2)
			ft_putendl_fd("Adaptive / O(n^2)", 2);
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_putendl_fd("Adaptive / O(n√n)", 2);
		else
			ft_putendl_fd("Adaptive / O(n log n)", 2);
	}
}

static void	write_total_operations(t_config config)
{
	int	sum;

	sum = config.pa_count + config.pb_count + config.ra_count + config.rb_count
		+ config.rr_count + config.rra_count + config.rrb_count
		+ config.rrr_count + config.sa_count + config.sb_count
		+ config.ss_count;
	ft_putnbr_fd(sum, 2);
	ft_putchar_fd('\n', 2);
}

// static void	write_operations(t_config config)
// {
// }

void	benchmark_summary(double disorder, t_config config)
{
	ft_putendl_fd("---BENCHMARK SUMMARY---", 2);
	ft_putstr_fd("disorder: ", 2);
	write_disorder_percentage(disorder);
	ft_putstr_fd("strategy: ", 2);
	write_strategy(config, disorder);
	ft_putstr_fd("total_ops: ", 2);
	write_total_operations(config);
}

#include <stdio.h>
int	main(void)
{
	t_config	config;

	config.mode = "adaptive";
	benchmark_summary(0.413518, config);
}
