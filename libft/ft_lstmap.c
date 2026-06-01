/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:07:19 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/28 11:53:23 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_n;
	t_list	*temp;
	void	*transformed;

	res = NULL;
	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	while (temp)
	{
		transformed = f(temp->content);
		new_n = ft_lstnew(transformed);
		if (!new_n)
		{
			del(transformed);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new_n);
		temp = temp->next;
	}
	return (res);
}
