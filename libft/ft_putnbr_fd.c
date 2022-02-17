/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:35:24 by konagash          #+#    #+#             */
/*   Updated: 2020/11/19 21:35:34 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n <= 9)
	{
		c = (n % 10) + '0';
		write(fd, &c, 1);
		return ;
	}
	c = (n % 10) + '0';
	ft_putnbr(n / 10, fd);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr((long)n, fd);
}
