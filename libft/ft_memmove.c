/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:04:00 by konagash          #+#    #+#             */
/*   Updated: 2020/11/24 13:54:32 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*ptr_dst;
	const unsigned char		*ptr_src;
	size_t					i;

	i = 0;
	ptr_src = (unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	if (dst > src)
	{
		while (i < len)
		{
			ptr_dst[len - 1 - i] = ptr_src[len - 1 - i];
			i++;
		}
	}
	else if (dst < src)
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}
