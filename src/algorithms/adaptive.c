/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:35:59 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/01 18:39:09 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	adaptive(t_node **a, t_node **b, t_config *config, double disorder)
{
	if (disorder < 0.2)
		bubble_sort(a, config);
	else if (disorder >= 0.2 && disorder < 0.5)
		chunk_sort(a, b, config);
	else
		radix_sort(a, b, config);
}
