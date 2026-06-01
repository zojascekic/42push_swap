/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:44:38 by zscekic           #+#    #+#             */
/*   Updated: 2026/05/06 11:57:53 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
// #include <stdio.h>

static int	word_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i])
		{
			count += 1;
			while (s[i] && s[i] != c)
				i ++;
		}
	}
	return (count);
}

static char	**free_memory(char **res, int i)
{
	while (i > 0)
	{
		i --;
		free(res[i]);
	}
	free(res);
	return (NULL);
}

static int	word_copy(char **res, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i ++;
			res[j] = ft_substr(s, start, i - start);
			if (!res[j])
				return (free_memory(res, j), 0);
			j ++;
		}
	}
	res[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	if (!word_copy(res, s, c))
		return (NULL);
	return (res);
}

// int	main(void)
// {
// 	char	**res;
// 	int		i;
// 	char	*s;
// 	char	c;

// 	i = 0;
// 	s = "Test string ";
// 	c = ' ';
// 	res = ft_split(s, c);
// 	if (!res)
// 	{
// 		printf("Failed to allocate");
// 		return (1);
// 	}
// 	while (res[i])
// 	{
// 		printf("%s\n", res[i]);
// 		free(res[i]);
// 		i ++;
// 	}
// 	free(res);
// 	return (0);
// }
