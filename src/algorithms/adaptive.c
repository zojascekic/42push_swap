/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:35:59 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/02 16:10:48 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	adaptive(t_node **a, t_node **b, t_config *config, double disorder)
{
	if (get_stack_size(a) < 6)
	{
		sort_small(a, b, config);
		return ;
	}
	if (disorder < 0.2)
		bubble_sort(a, config);
	else if (disorder >= 0.2 && disorder < 0.5)
		chunk_sort(a, b, config);
	else
		radix_sort(a, b, config);
}
