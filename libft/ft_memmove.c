/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:20:21 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/28 15:32:55 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (temp_dest < temp_src)
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i ++;
		}
	}
	else if (temp_dest > temp_src)
	{
		while (n -- > 0)
		{
			temp_dest[n] = temp_src[n];
		}
	}
	return (dest);
}
