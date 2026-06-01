/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:54:10 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/06 11:58:25 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	size_t	size;
	char	*res;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i ++;
	while (s1[j] && ft_strchr(set, s1[j]))
		j --;
	size = j - i + 1;
	res = ft_substr(s1, i, size);
	return (res);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*set;
// 	char	*res;
// 	s1 = "abazojababa";
// 	set = "ab";
// 	res = ft_strtrim(s1, set);
// 	printf("result is: %s", res);
// }
