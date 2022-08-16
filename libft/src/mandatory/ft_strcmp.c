/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:26:43 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/16 11:19:12 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s;
	unsigned char	*d;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while (*s == *d)
	{
		if (*s != *d)
			return (*s - *d);
		if (!*s)
			return (0);
		s++;
		d++;
	}
	return (*s - *d);
}
