/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:20:13 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/21 10:16:03 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	int				i;

	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		temp_dest[i] = temp_src[i];
		i ++;
		n --;
	}
	return (dest);
}
