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
#include "./L3d.h"

static void	get_wall_info(t_map *map, t_wall_clr *data, double dir)
{
	double	dist_on_y;
	double	dist_on_x;

	dist_on_y = cast_on_y(map, map->pers.posx, map->pers.posy, dir);
	dist_on_x = cast_on_x(map, map->pers.posx, map->pers.posy, dir);
	if (dist_on_y > dist_on_x)
	{
		if ((dir < 1.5 * PI && dir > PI2) || (dir < 3.5 * PI && dir > 2.5 * PI))
			data->wall_img = map->vars.path_we;
		else
			data->wall_img = map->vars.path_ea;
		data->dist = dist_on_x;
	}
	else
	{
		if ((dir < PI && dir > 0) || (dir < 3 * PI && dir > 2 * PI))
			data->wall_img = map->vars.path_no;
		else
			data->wall_img = map->vars.path_so;
		data->dist = dist_on_y;
	}
}

static int	get_pixel(t_interface wall, int x, int y)
{
	int		*dst;
	int		color;

	dst = (void *)wall.addr + (y * wall.line_length + x * (wall.bits_per_pixel / 8));
	color = *(int *)dst;
	return (color);
}

static void	draw_line_w(t_map *map, int lineh, t_interface wall_img, int x)
{
	t_local	q;


	q.rad = 3000;
	q.starty = 400 - lineh;
	q.endy = 400 + lineh;
	q.savex = x * 11;
	q.endx = (x + 1) * 11;
	q.dim_factor = (1600 / lineh) - 1;
	q.y = -1;
	if (q.starty < 0)
		q.starty = 0;
	if (q.endy > 800)
		q.endy = 800;
	draw_ceil(&q, &map->background, map->vars.ceil_clr);



	while (q.starty < q.endy)
	{
		q.startx = q.savex;
		q.wall_clr = get_pixel(wall_img, q.startx, q.starty);
		while (q.startx < q.endx)
		{
			my_mlx_pixel_put(&map->background, q.startx++, q.starty, q.wall_clr);
		}
		q.starty++;
	}





	draw_floor(&q, &map->background, map->vars.floor_clr);
}

void	draw_walls(t_map *map)
{
	t_wall_clr	data;
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
		data.dist *= cos(delta_dir);
		lineh = 800 / data.dist;
		if (lineh > 800)
			lineh = 800;
		lineh /= 2;
		draw_line_w(map, lineh, data.wall_img, x--);
		dir_start += GR / 2;
	}
}
