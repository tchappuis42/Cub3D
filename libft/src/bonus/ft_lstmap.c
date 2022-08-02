/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:01:54 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/04 18:10:02 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first;

	if (!del || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new_list = ft_lstnew((*f)(lst->content));
		if (!new_list)
		{
			while (first)
			{
				new_list = first->next;
				(*del)(first->content);
				free(first);
				first = new_list;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new_list);
		lst = lst->next;
	}
	return (first);
}
