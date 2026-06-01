/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:37:18 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/28 11:00:55 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_n;
	t_list	*next_n;

	if (!lst || !del)
		return ;
	current_n = *lst;
	while (current_n)
	{
		next_n = current_n->next;
		del(current_n->content);
		free(current_n);
		current_n = next_n;
	}
	*lst = NULL;
}

// int	main(void)
// {
// 	t_list	node1;
// 	t_list	node2;
// 	t_list	node3;
// }
