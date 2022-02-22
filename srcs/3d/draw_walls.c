/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static void	draw_line_w(t_interface map, double endx, double endy, int color)
{
	double	startx;
	double	starty;
	double	deltax;
	double	deltay;
	double	pixels;

	startx = map.size_x / 2;
	starty = map.size_y / 2;
	deltax = endx - startx;
	deltay = endy - starty;
	pixels = 40;
	deltax /= pixels;
	deltay /= pixels;
	while (pixels-- > 0)
	{
		my_mlx_pixel_put(&map, startx, starty, color);
		startx += deltax;
		starty += deltay;
	}
}

void	draw_walls(t_map *map)
{
	double	dist;
	double	dir;
	double	dir_end;
	double	half_y_len;
	double	pix_start_y;
	double	pix_end_y;

	dir_end = map->pers.dir + FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir = dir_end - 2 * FOV2;
	while (dir < dir_end)
	{
		dist = ray_cast(map, dir, 2);
		half_y_len = dist * tan(0.523599);
		pix_start_y = 400 - half_y_len;
		pix_end_y = 400 + half_y_len;
//		draw_line_w();
		dir += GR / 2;
	}

}
