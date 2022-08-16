/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:23:47 by tchappui          #+#    #+#             */
/*   Updated: 2022/08/16 15:23:49 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_H = 4,
	KEY_G = 5,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_C = 8,
	KEY_V = 9,
	KEY_B = 11,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_R = 15,
	KEY_Y = 16,
	KEY_T = 17,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_SIX = 22,
	KEY_FIVE = 23,
	KEY_NINE = 25,
	KEY_SEVEN = 26,
	KEY_EIGHT = 28,
	KEY_ZERO = 29,
	KEY_BRACE_R = 30,
	KEY_O = 31,
	KEY_U = 32,
	KEY_BRACE_L = 33,
	KEY_I = 34,
	KEY_P = 35,
	KEY_L = 37,
	KEY_J = 38,
	KEY_K = 40,
	KEY_SEMI = 41,
	KEY_N = 45,
	KEY_M = 46,
	KEY_TAB = 48,
	KEY_ESCAPE = 53,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126
};

enum
{
	KEYPRESS = 2,
	KEYRELEASE = 3,
	BUTTONPRESS = 4,
	BUTTONRELEASE = 5,
	MOTIONNOTIFY = 6,
	ENTERNOTIFY = 7,
	LEAVENOTIFY = 8,
	FOCUSIN = 9,
	FOCUSOUT = 10,
	KEYMAPNOTIFY = 11,
	EXPOSE = 12,
	GRAPHICSEXPOSE = 13,
	NOEXPOSE = 14,
	VISIBILITYNOTIFY = 15,
	CREATENOTIFY = 16,
	DESTROYNOTIFY = 17,
	UNMAPNOTIFY = 18,
	MAPNOTIFY = 19,
	MAPREQUEST = 20,
	REPARENTNOTIFY = 21,
	CONFIGURENOTIFY = 22,
	CONFIGUREREQUEST = 23,
	GRAVITYNOTIFY = 24,
	RESIZEREQUEST = 25,
	CIRCULATENOTIFY = 26,
	CIRCULATEREQUEST = 27,
	PROPERTYNOTIFY = 28,
	SELECTIONCLEAR = 29,
	SELECTIONREQUEST = 30,
	SELECTIONNOTIFY = 31,
	COLORMAPNOTIFY = 32,
	CLIENTMESSAGE = 33,
	MAPPINGNOTIFY = 34,
	GENERICEVENT = 35,
	LASTEVENT = 36
};

typedef struct s_frame
{
	void	*ptr;
	int		*buff;
	int		bpp;
	int		line;
	int		argb;
	int		color;
	int		width;
	int		height;
}	t_frame;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_frame	*frame;
}	t_mlx;

#endif
