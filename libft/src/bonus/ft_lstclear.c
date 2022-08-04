/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:01:23 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/04 18:12:08 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*actual;
	t_list	*to_delete;

	if (lst == NULL || del == NULL)
		return ;
	actual = *lst;
	while (actual != NULL)
	{
		to_delete = actual;
		actual = actual->next;
		del(to_delete->content);
		free(to_delete);
	}
	*lst = NULL;
}
