/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:46:57 by konagash          #+#    #+#             */
/*   Updated: 2020/11/19 21:23:43 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*result;
	size_t		size;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
	{
		result[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		result[i] = *s2++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
