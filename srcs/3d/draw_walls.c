/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/24 19:05:50 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

typedef struct s_local
{
	double	dist;
	int		color;
}	t_wall_clr;

static void	get_wall_info(t_map *map, t_wall_clr *data, double dir)
{
	double	dist_on_y;
	double	dist_on_x;

	dist_on_y = cast_on_y(map, map->pers.posx, map->pers.posy, dir);
	dist_on_x = cast_on_x(map, map->pers.posx, map->pers.posy, dir);
	if (dist_on_y > dist_on_x)
	{
		if ((dir < 1.5 * PI && dir > PI2) || (dir < 3.5 * PI && dir > 2.5 * PI))
			data->color = WE;
		else
			data->color = EA;

		data->dist = dist_on_x;
	}
	else
	{
		if ((dir < PI && dir > 0) || (dir < 3 * PI && dir > 2 * PI))
			data->color = NO;
		else
			data->color = SO;
		data->dist = dist_on_y;
	}
}

static void	draw_line_w(t_interface *back, int lineh, int wall_color, int x)
{
	int	startx;
	int	starty;
	int	endx;
	int	endy;
	int	y;
	int	savex;
	int	floor_color;
	int	ceil_color;
	int	dim_factor;

	starty = 400 - lineh;
	endy = 400 + lineh;
	if (starty < 0)
		starty = 0;
	if (endy > 800)
		endy = 800;
	dim_factor = (800 / lineh) - 1;
	if (dim_factor > 7)
		wall_color = 0xFF000000;
	else
		wall_color = dim_factor * 570425344 + wall_color;
	floor_color = FLOOR;
	ceil_color = CEIL;



	y = -1;
	savex = x * 11;
	endx = (x + 1) * 11;
//	while (++y < starty)
//	{
//		startx = savex;
//		while (startx < endx)
//			my_mlx_pixel_put(back, startx++, y, ceil_color);
//		if (y == 135 || y == 200 || y == 240 || y == 265 || y == 285 || y == 300 || y == 309)
//			ceil_color += 570425344;
//		else if (y == 317)
//			ceil_color = 0xEE51A889;
//	}

//int	rad = 64;
//int	res;
	while (++y < starty)
	{
		startx = savex;
		while (startx < endx)
		{
//			res = sqrt((y + rad) * (y + rad) + (x + rad) * (x + rad));
//			ceil_color += res / 64 * 285212672;
			my_mlx_pixel_put(back, startx++, y, ceil_color);
		}
		if (y == 135 || y == 200 || y == 240 || y == 265 || y == 285 || y == 300 || y == 309)
			ceil_color += 570425344;
		else if (y == 317)
			ceil_color = 0xEE51A889;
	}
	while (starty < endy)
	{
		startx = savex;
		while (startx < endx)
			my_mlx_pixel_put(back, startx++, starty, wall_color);
		starty++;
	}
	endy = 800;
//	while (starty < endy--)
//	{
//		startx = savex;
//		while (startx < endx)
//			my_mlx_pixel_put(back, startx++, endy, floor_color);
//		if (endy == 800 - 135 || endy == 800 - 200 || endy == 800 - 240 || endy == 800 - 265
//			|| endy == 800 - 285 || endy == 800 - 300 || endy == 800 - 309)
//			floor_color += 570425344;
//	}
	while (starty < endy--)
	{
		startx = savex;
		while (startx < endx)
			my_mlx_pixel_put(back, startx++, endy, floor_color);
		if (endy == 800 - 135 || endy == 800 - 200 || endy == 800 - 240 || endy == 800 - 265
			|| endy == 800 - 285 || endy == 800 - 300 || endy == 800 - 309)
			floor_color += 570425344;
	}
}

void	draw_walls(t_map *map)
{
	t_wall_clr	data;
	double		dist;
	double		dir_start;
	double		dir_end;
	double		delta_dir;
	int			lineh;
	int			x;

	dir_end = map->pers.dir + FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir_start = dir_end - 2 * FOV2;

	x = 119;
	while (dir_end > dir_start && x > -1)
	{
		delta_dir = map->pers.dir - dir_start;
		if (delta_dir < 0)
			delta_dir += 2 * PI;
		else if (delta_dir > 2 * PI)
			delta_dir -= 2 * PI;
		get_wall_info(map, &data, dir_start);
		dist = data.dist;
		dist *= cos(delta_dir);
		lineh = 800 / dist;
		if (lineh > 800)
			lineh = 800;
		lineh /= 2;
		draw_line_w(&map->background, lineh, data.color, x--);
		dir_start += GR / 2;
	}
}
