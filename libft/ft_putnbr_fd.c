/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:15:33 by zscekic           #+#    #+#             */
/*   Updated: 2026/04/24 16:16:27 by zscekic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	res[12];
	int		i;

	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (n > 0)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i ++;
	}
	-- i;
	while (i >= 0)
	{
		write(fd, &res[i], 1);
		-- i;
	}
}

// int	main(void)
// {
// 	int	test;

// 	test = -2147448;
// 	ft_putnbr_fd(test, 1);
// }
