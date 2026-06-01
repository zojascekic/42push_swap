/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:51:57 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/06 11:57:11 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
// #include <stdio.h>

static int	num_len(long num)
{
	int	count;

	count = 0;
	if (num == 0)
		count = 1;
	if (num < 0)
		count ++;
	while (num != 0)
	{
		num = num / 10;
		count ++;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	long	num;
	int		size;
	char	*res;
	int		i;

	num = n;
	size = num_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	res = (char *)ft_calloc(size, sizeof(char));
	if (!res)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		res[0] = '-';
	}
	i = size - 2;
	while (num != 0)
	{
		res[i] = num % 10 + '0';
		num = num / 10;
		i --;
	}
	return (res);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(123));
// }
