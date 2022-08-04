/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:32:36 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/03 11:46:07 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_tampon(char *str)
{
	size_t	i;
	char	*dest;

	dest = NULL;
	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
		{
			free (str);
			return (NULL);
		}
		i++;
	}
	if (str[i + 1] != '\0')
	{
		dest = ft_strdup(str + i + 1);
		free (str);
	}
	else
	{
		free (str);
		return (NULL);
	}
	return (dest);
}

static char	*ft_resultat(char *str)
{
	char	*rtn;
	size_t	i;

	rtn = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			rtn = ft_substr(str, 0, i + 1);
			return (rtn);
		}
		i++;
	}
	rtn = ft_strdup(str);
	return (rtn);
}

static char	*ft_newt(int fd, char *rtn)
{
	int		ret;
	size_t	i;
	char	buffer[BUFFER_SIZE + 1];

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == 0)
		return (rtn);
	while (ret != 0)
	{
		buffer[ret] = '\0';
		i = 0;
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
			{
				rtn = ft_printstr(buffer, rtn);
				return (rtn);
			}
			i++;
		}
		rtn = ft_printstr(buffer, rtn);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	return (rtn);
}

static char	*ft_checkt(int fd, char *str)
{
	size_t	i;
	char	*test;

	test = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (str);
		}
		i++;
	}
	str = ft_newt(fd, str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*t;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, res, 0) < 0 )
		return (NULL);
	if (!t && read(fd, res, BUFFER_SIZE) == 0)
		return (NULL);
	if (!t)
		t = ft_newt(fd, t);
	else if (t[0] == '\0' && read(fd, res, BUFFER_SIZE) == 0)
	{
		free (t);
		return (NULL);
	}
	else
		t = ft_checkt(fd, t);
	res = ft_resultat(t);
	t = ft_tampon(t);
	return (res);
}
