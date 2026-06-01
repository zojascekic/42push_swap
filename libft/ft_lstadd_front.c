/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:49:17 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/26 14:24:52 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
// #include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*res;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*temp;

// 	res = NULL;
// 	node1 = ft_lstnew("node1");
// 	node2 = ft_lstnew("node2");
// 	ft_lstadd_front(&res, node1);
// 	ft_lstadd_front(&res, node2);

// 	temp = res;
// 	while (temp != NULL)
// 	{
// 		printf("content: %s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}	
// }
