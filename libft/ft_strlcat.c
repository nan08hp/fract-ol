/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:54:00 by konagash          #+#    #+#             */
/*   Updated: 2020/11/24 14:39:35 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;

	len = 0;
	while (len < dstsize && dst[len])
		len++;
	if (dstsize == 0)
		return (ft_strlen(src));
	i = len;
	while (src[i - len] && i + 1 < dstsize)
	{
		dst[i] = src[i - len];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
