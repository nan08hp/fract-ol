/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:07:18 by konagash          #+#    #+#             */
/*   Updated: 2020/11/19 21:29:06 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('0' <= c && c <= '9') \
	|| ('a' <= c && c <= 'z') \
	|| ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}
