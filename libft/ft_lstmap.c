/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:56:50 by konagash          #+#    #+#             */
/*   Updated: 2020/11/24 01:55:50 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_lst;
	t_list		*elem;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&new_lst, del);
			return (new_lst);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, elem);
	}
	return (new_lst);
}
