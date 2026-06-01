/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:40:42 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/24 15:10:03 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
// #include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	if (!s || !f)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i ++;
	}
	res[i] = '\0';
	return (res);
}

// char	transform(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 	{
// 		if (c > 'a' && c < 'z')
// 			return (c - 32);
// 	}
// 	else
// 	{
// 		if (c > 'A' && c < 'Z')
// 			return (c + 32);
// 	}
// 	return (c);
// }

// int	main(void)
// {
// 	char	*input;
// 	char	*res;

// 	input = "test";
// 	res = ft_strmapi(input, transform);
// 	printf("%s\n", res);
// }
