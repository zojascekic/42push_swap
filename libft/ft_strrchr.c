/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:16:53 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/24 10:09:17 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	charc;

	i = ft_strlen(s);
	charc = (char) c;
	while (i >= 0)
	{
		if (s[i] == charc)
			return ((char *) &s[i]);
		i --;
	}
	return (NULL);
}
