/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:35:59 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/01 14:38:26 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_node **stack_a, t_node **stack_b, t_config config)
{
	double	disorder_value;

	disorder_value = compute_disorder(stack_a);
	if (disorder_value < 0.2)
		bubble_sort(stack_a, config);
	else if (disorder_value >= 0.2 && disorder_value < 0.5)
		chunk_sort(stack_a, stack_b, config);
	else
		radix_sort(stack_a, stack_b, config);
}
