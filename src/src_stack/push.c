/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:25:17 by zscekic           #+#    #+#             */
/*   Updated: 2026/06/01 15:28:27 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	temp->next = *dst;
	if (*dst != NULL)
		(*dst)->prev = temp;
	temp->prev = NULL;
	*dst = temp;
}

void	pa(t_node **stack_a, t_node **stack_b, t_config *config)
{
	push(stack_a, stack_b);
	if (config->bench != 1)
		write(1, "pa\n", 3);
	config->pa_count += 1;
}

void	pb(t_node **stack_a, t_node **stack_b, t_config *config)
{
	push(stack_b, stack_a);
	if (config->bench != 1)
		write(1, "pb\n", 3);
	config->pb_count += 1;
}
