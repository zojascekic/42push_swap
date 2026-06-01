/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:35:42 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/22 14:58:24 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_temp;
	unsigned char	c_temp;
	size_t			i;

	s_temp = (unsigned char *) s;
	c_temp = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (s_temp[i] == c_temp)
			return ((void *) &s_temp[i]);
		i ++;
	}
	return (NULL);
}
