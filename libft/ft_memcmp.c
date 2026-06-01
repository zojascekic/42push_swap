/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:01:53 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/24 10:25:08 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;
	size_t			i;

	s1_temp = (unsigned char *) s1;
	s2_temp = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1_temp[i] == s2_temp[i])
			i++;
		else
			return (s1_temp[i] - s2_temp[i]);
	}
	return (0);
}

// int	main(void)
// {
// 	char s1[] = {0, -10, 127, 0};
// 	char s2[] = {0, 0, 42, 0};

// 	printf("%d\n", ft_memcmp(s1, s2, 0));
// 	printf("%d", memcmp(s1, s2, 0));
// 	return (0);
// }
