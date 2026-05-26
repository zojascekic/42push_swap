/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:56:43 by dvasilev          #+#    #+#             */
/*   Updated: 2026/05/26 10:24:52 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static char	*copy_wrapped_substr(char *str, int start_index, int end_index)
{
	int		i;
	int		copy_started;
	char	*res;
	int		i_res;

	res = malloc(sizeof(char) * (end_index - start_index + 2));
	if (!res)
		return (NULL);
	copy_started = 0;
	i_res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i == start_index)
			copy_started = 1;
		if (copy_started == 1)
			res[i_res++] = str[i];
		if (i == end_index)
			copy_started = 0;
		i++;
	}
	res[i_res] = '\0';
	return (res);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**allocate_memory_if_exist(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	return (res);
}

void	free_all(char **res, int i)
{
	while (i > 0)
	{
		free(res[i - 1]);
		i--;
	}
	free(res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i_s;
	int		i_sub;
	int		i_res;

	res = allocate_memory_if_exist(s, c);
	if (!res)
		return (NULL);
	i_s = 0;
	i_res = 0;
	while (s[i_s])
	{
		if (s[i_s] != c && (i_s == 0 || s[i_s - 1] == c))
			i_sub = i_s;
		if (s[i_s] != c && (s[i_s + 1] == c || s[i_s + 1] == '\0'))
		{
			res[i_res] = copy_wrapped_substr((char *)s, i_sub, i_s);
			if (!res[i_res++])
				return (free_all(res, i_res - 1), NULL);
		}
		i_s++;
	}
	res[i_res] = NULL;
	return (res);
}
