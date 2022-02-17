/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:11:34 by konagash          #+#    #+#             */
/*   Updated: 2020/11/19 23:28:25 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ptr_s1;
	unsigned char		*ptr_s2;
	size_t				i;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	return (ptr_s1[i] - ptr_s2[i]);
}
