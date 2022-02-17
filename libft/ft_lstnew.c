/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 02:44:46 by konagash          #+#    #+#             */
/*   Updated: 2020/11/22 00:44:39 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*arr_lst;

	arr_lst = (t_list *)malloc(sizeof(arr_lst));
	if (!arr_lst)
		return (NULL);
	arr_lst->content = content;
	arr_lst->next = NULL;
	return (arr_lst);
}
