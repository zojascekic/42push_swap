/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:15:14 by dvasilev          #+#    #+#             */
/*   Updated: 2026/06/02 10:07:03 by dvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	has_duplicates(int *values, int int_num)
{
	int	i;
	int	j;

	i = 0;
	while (i < int_num)
	{
		j = i + 1;
		while (j < int_num)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_elements_in_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}
