/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:06:11 by konagash          #+#    #+#             */
/*   Updated: 2020/11/19 21:25:48 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*strr;

	strr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			strr = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (strr);
}
