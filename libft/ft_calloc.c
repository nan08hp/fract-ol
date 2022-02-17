/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:26:02 by konagash          #+#    #+#             */
/*   Updated: 2020/11/22 00:47:37 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*block;
	size_t		malloc_size;

	malloc_size = count * size;
	block = (void *)malloc(malloc_size);
	if (block == NULL)
		return (NULL);
	ft_memset(block, 0, malloc_size);
	return (block);
}
