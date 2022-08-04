/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:08:02 by tchappui          #+#    #+#             */
/*   Updated: 2021/11/16 15:08:05 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc((size + 1) * (sizeof (char)));
	if (dest == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free ((char *)s1);
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof (char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dest;

	i = 0;
	if (!s)
		return (0);
	if ((start + len) > ft_strlen(s))
		dest = malloc(ft_strlen(s) + 1 * sizeof(char));
	else
		dest = malloc(len * sizeof(char) + 1);
	if (!dest)
		return (0);
	while (i < len && s[start] && start < ft_strlen(s))
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_printstr(char *buffer, char *rtn)
{
	if (!rtn)
		return (ft_strdup(buffer));
	return (ft_strjoinfree(rtn, buffer));
}
