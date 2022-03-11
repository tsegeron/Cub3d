/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/24 19:05:50 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"
#include "./L3d.h"

static int	shade_color(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
			+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
			+ ((int)((0x0000FF & color) / divide)));
}

static int	get_wall_clr(int side, int tex_y, t_wall_clr *wall)
{
	int	clr;

	if (side == 1 || side == 2)
		clr = get_pixel(wall->wall_img, wall->x, tex_y);
	else
		clr = get_pixel(wall->wall_img, wall->y, tex_y);
	return (shade_color(clr, wall->dist / 0.5));
}

static void	draw_wall_line(t_map *map, t_local *q, t_wall_clr *wall, int lineh)
{
	double	pix_start;
	double	pix_step;

	pix_step = 1. * wall->wall_img.size_y / (lineh * 2);
	if (wall->wall_stat == 3 && map->key.e == 1)
		pix_start = (q->starty - map->mlx.win_size_y / 2. + lineh) * \
		pix_step + wall->rand;
	else if (wall->wall_stat == 3 && map->key.e == 2)
		pix_start = (q->starty - map->mlx.win_size_y / 2. + lineh) \
		* pix_step + wall->wall_img.size_y - wall->rand;
	else
		pix_start = (q->starty - map->mlx.win_size_y / 2. + lineh) * pix_step;
	while (q->starty < q->endy)
	{
		q->startx = q->savex;
		pix_start += pix_step;
		if (pix_start > wall->wall_img.size_y)
			break ;
		q->wall_clr = get_wall_clr(wall->side, (int)pix_start, wall);
		while (q->startx < q->endx)
			my_mlx_pixel_put(&map->back, q->startx++, q->starty, q->wall_clr);
		q->starty++;
	}
}

void	draw_line_w(t_map *map, int lineh, t_wall_clr wall, int x)
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
	if (wall.wall_stat != 3)
		draw_ceil(&q, &map->back, map->vars.ceil_clr);
	draw_wall_line(map, &q, &wall, lineh);
	if (wall.wall_stat != 3)
		draw_floor(&q, &map->back, map->vars.floor_clr);
}
