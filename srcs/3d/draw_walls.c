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

static void	draw_wall_line(t_map *map, t_local *q, t_wall_clr *wall, int lineh)
{
	double	pix_start;
	double	pix_step;

	pix_step = 1. * wall->wall_img.size_y / lineh / 2;
	pix_start = (q->starty - map->mlx.win_size_y / 2. + lineh) * pix_step;
	while (q->starty < q->endy)
	{
		q->startx = q->savex;
		pix_start += pix_step;
		if (wall->side == 1 || wall->side == 2)
			q->wall_clr = get_pixel(wall->wall_img, wall->x, pix_start);
		else
			q->wall_clr = get_pixel(wall->wall_img, wall->y, pix_start);
		q->wall_clr = shade_color(q->wall_clr, wall->dist / 1.1);
		while (q->startx < q->endx)
			my_mlx_pixel_put(&map->back, q->startx++, q->starty, q->wall_clr);
		q->starty++;
	}
}

static void	draw_line_w(t_map *map, int lineh, t_wall_clr wall, int x)
{
	t_local	q;

	q.rad = 3000;
	q.starty = 400 - lineh;
	q.endy = 400 + lineh;
	q.savex = x * 2;
	q.endx = (x + 1) * 2;
	q.y = -1;
	if (q.starty < 0)
		q.starty = 0;
	if (q.endy > 800)
		q.endy = 800;
	draw_ceil(&q, &map->back, map->vars.ceil_clr);
	draw_wall_line(map, &q, &wall, lineh);
	draw_floor(&q, &map->back, map->vars.floor_clr);
}

static void	get_wall_info(t_map *map, t_wall_clr *data, double dir)
{
	double	dist_on_y;
	double	dist_on_x;

	dist_on_y = cast_on_y(map, map->pers.posx, map->pers.posy, dir);
	dist_on_x = cast_on_x(map, map->pers.posx, map->pers.posy, dir);
	if (dist_on_y > dist_on_x)
		get_ea_we_data(&map->vars, data, dist_on_x, dir);
	else
		get_no_so_data(&map->vars, data, dist_on_y, dir);
	data->y = fabs(sin(dir) * data->dist);
	data->x = fabs(cos(dir) * data->dist);
	calc_tex_dims(data, dir, map->pers.posx, map->pers.posy);
}

void	draw_walls(t_map *map)
{
	t_wall_clr	data;
	double		dir_start;
	double		dir_end;
	double		delta_dir;
	int			x;

	dir_end = map->pers.dir + FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir_start = dir_end - 2 * FOV2;
	x = 659;
	while (dir_end > dir_start && x > -1)
	{
		delta_dir = map->pers.dir - dir_start;
		if (delta_dir < 0)
			delta_dir += 2 * PI;
		else if (delta_dir > 2 * PI)
			delta_dir -= 2 * PI;
		get_wall_info(map, &data, dir_start);
		data.dist *= cos(delta_dir);
		draw_line_w(map, (int)(800 / data.dist / 2), data, x);
		dir_start += 0.00158666;
		x--;
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->back.img, 0, 0);
}
