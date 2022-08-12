#include "../includes/cub3d.h"
#include "game/game.h"


int	ft_exit(void *param)
{
	t_game* info;

	info = (t_game*)param;
	ft_clean(info);
	exit(EXIT_SUCCESS);
	return(0);
}

void ft_clean(t_game* info)
{
	(void)info;
	// int		i;

	// i = 0;
	// while (i < HEIGHT && info->buffer != NULL)
	// {
	// 	free(info->buffer[i]);
	// 	i++;
	// }
	// free(info->buffer);
	// i = 0;
	// while (i < 4)
	// {
	// 	free(info->texture[i]);
	// 	i++;
	// }
	// free(info->texture);
}



// Parse the map and then start the game
int main(int argc, char **argv)
{
	t_data data;
	t_tex tex;

	if (argc == 2)
	{
		parsing(&data, &tex, argv[1]);
		printf("h = %d, w = %d\n", data.h, data.w);
		game_start(&data, &tex);
	}
}