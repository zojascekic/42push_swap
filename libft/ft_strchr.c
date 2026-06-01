/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:13:36 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/24 09:54:59 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	charc;

	i = 0;
	charc = (char) c;
	while (s[i])
	{
		if (s[i] == charc)
			return ((char *) &s[i]);
		i ++;
	}
	if (s[i] == charc)
		return ((char *) &s[i]);
	return (NULL);
}
