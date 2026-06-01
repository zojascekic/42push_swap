/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:14:15 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/24 15:34:11 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i ++;
	}
}

// void	transform(unsigned int i, char *c)
// {
// 	if (i % 2 == 0)
// 	{
// 		if (*c > 'a' && *c < 'z')
// 			*c = *c - 32;
// 	}
// 	else
// 	{
// 		if (*c > 'A' && *c < 'Z')
// 			*c = *c + 32;
// 	}
// }

// int	main(void)
// {
// 	char	input[] = "test";

// 	ft_striteri(input, transform);
// 	printf("%s\n", input);
// }
