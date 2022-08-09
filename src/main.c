#include "../includes/cub3d.h"

// Parse the map and then start the game
int main(int argc, char **argv)
{
	t_data data;
	t_tex tex;

	if (argc == 2)
	{
		parsing(&data, &tex, argv[1]);	
		//game_start(&data, &tex);
		int i = 0;
		while(data.map[i])
		{
			printf("%s\n", data.map[i]);
			i++;
		}
	}
}