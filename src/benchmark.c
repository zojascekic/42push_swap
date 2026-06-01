/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:14:40 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/01 15:37:08 by dvasilev         ###   ########.fr       */
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
	if (ft_strcmp(config.mode, "simple") == 0)
		ft_putendl_fd("Simple / O(n^2)", 2);
	else if (ft_strcmp(config.mode, "medium") == 0)
		ft_putendl_fd("Medium / O(n√n)", 2);
	else if (ft_strcmp(config.mode, "complex") == 0)
		ft_putendl_fd("Complex / O(n log n)", 2);
	else if (ft_strcmp(config.mode, "adaptive") == 0)
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

static void	write_each_operation(t_config config)
{
	ft_putstr_fd("sa :", 2);
	ft_putnbr_fd(config.sa_count, 2);
	ft_putstr_fd("sb :", 2);
	ft_putnbr_fd(config.sb_count, 2);
	ft_putstr_fd("ss :", 2);
	ft_putnbr_fd(config.ss_count, 2);
	ft_putstr_fd("pa :", 2);
	ft_putnbr_fd(config.pa_count, 2);
	ft_putstr_fd("pb :", 2);
	ft_putnbr_fd(config.pb_count, 2);
	ft_putstr_fd("ra :", 2);
	ft_putnbr_fd(config.ra_count, 2);
	ft_putstr_fd("rb :", 2);
	ft_putnbr_fd(config.rb_count, 2);
	ft_putstr_fd("rr :", 2);
	ft_putnbr_fd(config.rr_count, 2);
	ft_putstr_fd("rra :", 2);
	ft_putnbr_fd(config.rra_count, 2);
	ft_putstr_fd("rrb :", 2);
	ft_putnbr_fd(config.rrb_count, 2);
	ft_putstr_fd("rrr :", 2);
	ft_putnbr_fd(config.rrr_count, 2);
}

void	benchmark_summary(double disorder, t_config *config)
{
	ft_putendl_fd("---BENCHMARK SUMMARY---", 2);
	ft_putstr_fd("disorder: ", 2);
	write_disorder_percentage(disorder);
	ft_putstr_fd("strategy: ", 2);
	write_strategy(*config, disorder);
	ft_putstr_fd("total_ops: ", 2);
	write_total_operations(*config);
	write_each_operation(*config);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_config	config;

// 	config.mode = "adaptive";
// 	benchmark_summary(0.413518, &config);
// }
