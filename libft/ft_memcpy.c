/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:32:58 by konagash          #+#    #+#             */
/*   Updated: 2020/11/24 13:53:13 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!ptr_dst && !ptr_src)
		return (NULL);
	while (n-- > 0)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
