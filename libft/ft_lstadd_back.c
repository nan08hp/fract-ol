/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 23:14:10 by konagash          #+#    #+#             */
/*   Updated: 2020/11/16 23:45:19 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*tmp;

	if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = &(*new);
	}
	else
		*lst = new;
}
