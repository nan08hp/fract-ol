/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:25:45 by konagash          #+#    #+#             */
/*   Updated: 2020/11/24 13:55:09 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		ch;
	unsigned char		*mem;
	size_t				i;

	ch = (unsigned char)c;
	i = 0;
	mem = (unsigned char *)b;
	while (i < len)
	{
		mem[i] = ch;
		i++;
	}
	return (mem);
}
