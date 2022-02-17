/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:32:00 by konagash          #+#    #+#             */
/*   Updated: 2020/11/22 00:37:29 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;

	if (!(*s2))
		return ((char *)s1);
	while (*s1 && len)
	{
		i = 0;
		while (*(s1 + i) == *(s2 + i) && *(s1 + i) && i < len)
		{
			if (*(s2 + i + 1) == '\0')
				return ((char *)s1);
			i++;
		}
		s1++;
		len--;
	}
	return (NULL);
}
