#include "../../hdrs/cub3d.h"
#include "./L3d.h"

int	shade_color(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
			+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
			+ ((int)((0x0000FF & color) / divide)));
}

int	distance_shade(int options, int color, double distance)
{
	if (options & FLAG_SHADOWS)
		return (shade_color(color, distance / 1.5));
	return (color);
}

int	get_color(t_tex *tex, t_pos *pos)
{
	if (pos->x >= 0 && pos->x < tex->width
		&& pos->y >= 0 && pos->y < tex->height)
	{
		return (*(int*)(tex->ptr + (4 * tex->width * (int)pos->y) + (4 * (int)pos->x)));
	}
	return (0x0);
}