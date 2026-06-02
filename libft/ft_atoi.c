/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:12:28 by dvasilev          #+#    #+#             */
/*   Updated: 2026/04/30 15:58:52 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	long	number;
	int		sign;

	sign = 1;
	i = 0;
	number = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(number * sign));
}

// int	main(void)
// {
// 	printf("my: %i, orig: %i\n", ft_atoi("123"), atoi("123"));
// 	printf("my: %i, orig: %i\n", ft_atoi(" 123"), atoi(" 123"));
// 	printf("my: %i, orig: %i\n", ft_atoi("    123"), atoi("    123"));
// 	printf("my: %i, orig: %i\n", ft_atoi("0123"), atoi("0123"));
// 	printf("my: %i, orig: %i\n", ft_atoi("a"), atoi("a"));
// 	printf("my: %i, orig: %i\n", ft_atoi("-123"), atoi("-123"));
// 	printf("my: %i, orig: %i\n", ft_atoi("--1"), atoi("--1"));
// 	printf("my: %i, orig: %i\n", ft_atoi("++1"), atoi("++1"));
// 	printf("my: %i, orig: %i\n", ft_atoi("+-1"), atoi("+-1"));
// 	printf("my: %i, orig: %i\n", ft_atoi("-+1"), atoi("-+1"));
// 	printf("my: %i, orig: %i\n", ft_atoi("-2147483648"), atoi("-2147483648"));
// 	printf("my: %i, orig: \n", atoi(NULL));
// 	// printf("my: %i, orig: %i\n", ft_atoi(NULL), atoi(NULL));
// }
