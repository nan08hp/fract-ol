/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:06:10 by konagash          #+#    #+#             */
/*   Updated: 2020/11/24 14:35:12 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long		number;

	sign = 1;
	number = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || \
				*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && '0' <= *str && *str <= '9')
	{
		if (number > LONG_MAX)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number * sign);
}
