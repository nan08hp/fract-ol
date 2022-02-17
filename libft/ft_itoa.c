/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:32:33 by konagash          #+#    #+#             */
/*   Updated: 2020/11/15 02:11:20 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	long		num;
	int			digit;

	digit = 1;
	num = n;
	if (num < 0)
	{
		num *= -1;
		digit++;
	}
	while (num > 9)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			i;
	int			digit;
	long		num;

	i = 0;
	num = n;
	digit = count_digit(n);
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		result[0] = '-';
	}
	while (num > 9)
	{
		result[digit - i - 1] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	result[digit - i - 1] = (num % 10) + '0';
	result[digit] = '\0';
	return (result);
}
