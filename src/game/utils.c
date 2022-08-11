#include "game/game.h"

int *newtexture(void)
{
	int		y;
	int		x;
	int		*texture;

	y = 0;
	x = 0;
	texture = malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
	while (y < TEXHEIGHT)
	{
		x = 0;
		while(x < TEXWIDTH)
		{
			texture[y * TEXWIDTH + x] = 0;
			x++;
		}
		y++;
	}
	return (texture);
}