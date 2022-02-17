/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:51:42 by konagash          #+#    #+#             */
/*   Updated: 2020/11/19 21:26:25 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && check_set(*s1, (char *)set))
		s1++;
	end = ft_strlen(s1);
	while (end && check_set(s1[end - 1], (char *)set))
		end--;
	result = ft_substr(s1, 0, end);
	return (result);
}
