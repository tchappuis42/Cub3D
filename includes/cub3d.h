#ifndef CUB3D_H
# define CUB3D_H

// struct pour la map

# include "stdio.h"
# include <fcntl.h>

typedef struct s_data
{
	char **map; // map en double tab
	int		h;  // change nom
	int		w;	// change nom
	double	px; // 
	double	py; //
	char	p;  // 
	int		i; // pour le parcing
}	t_data;

//lien des fichiers pour les textures
typedef struct s_texture 
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
} t_tex;

// start the game
void	parsing(t_data *data, t_tex *tex, char *map);
void	game_start(void); 

#endif