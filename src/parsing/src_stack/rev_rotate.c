/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoja <Zoja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:25:11 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/24 13:18:56 by Zoja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = NULL;
}
