/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:57:35 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/26 15:10:42 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// int	main(void)
// {
// 	t_list	*res;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*new;
// 	t_list	*temp;

// 	res = NULL;
// 	node1 = ft_lstnew("node1");
// 	node2 = ft_lstnew("node2");
// 	new = ft_lstnew("new");

// 	ft_lstadd_back(&res, node1);
// 	ft_lstadd_back(&res, node2);
// 	ft_lstadd_back(&res, new);

// 	temp = res;
// 	while (temp != NULL)
// 	{
// 		printf("content: %s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }
