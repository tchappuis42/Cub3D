/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:15:08 by tweimer           #+#    #+#             */
/*   Updated: 2022/08/16 16:46:23 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/parsing.h"
#include "../../includes/cub3d.h"

char	*expected_line(void)
{
	char	*width;
	char	*height;
	char	*tmp[3];
	char	*rtn;

	width = ft_itoa(TEXWIDTH);
	height = ft_itoa(TEXHEIGHT);
	tmp[0] = ft_strjoin("\"", width);
	tmp[1] = ft_strjoin(tmp[0], " ");
	tmp[2] = ft_strjoin(tmp[1], height);
	rtn = ft_strjoin(tmp[2], " ");
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(width);
	free(height);
	return (rtn);
}

void	free_line(char *line)
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
}

int	check_tex_size(int tmp_fd, char *expected)
{
	char	*line;
	char	*needle;

	line = NULL;
	needle = "/* columns rows colors chars-per-pixel */";
	while (ft_strcmp(needle, line) != 0)
	{
		free_line(line);
		line = get_next_line(tmp_fd);
		line[ft_strlen(line) - 1] = '\0';
	}
	free_line(line);
	line = get_next_line(tmp_fd);
	close(tmp_fd);
	if (ft_strncmp(line, expected, ft_strlen(expected)) != 0)
		return (0);
	free_line(line);
	return (1);
}

int	check_file(const char *filename, char *expected)
{
	int	tmp_fd;

	tmp_fd = open(filename, O_RDONLY);
	if (tmp_fd < 0)
	{
		close(tmp_fd);
		return (0);
	}
	if (!check_tex_size(tmp_fd, expected))
		return (0);
	return (1);
}

void	parsing_texture(t_data *data)
{
	char	*expected;

	expected = expected_line();
	if (!check_file(data->tex->path_no, expected)
		|| !check_file(data->tex->path_so, expected)
		|| !check_file(data->tex->path_ea, expected)
		|| !check_file(data->tex->path_we, expected))
	{
		free(expected);
		expected = NULL;
		exit_map(8, data);
	}
	free(expected);
	expected = NULL;
}
