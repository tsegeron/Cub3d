/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 23:20:01 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

static void	draw_line_w(t_interface *back, int starty, int endy, int x)
{
	int	startx;
	int	y;
	int	savex;
	int	endx;

	if (starty < 0)
		starty = 0;
	if (endy > 799)
		endy = 799;
	y = -1;
	savex = x * 11;
	endx = (x + 1) * 11;
//	printf("%d %d\n", savex, endx);
//	return;
	while (++y < starty)
	{
		startx = savex;
		while (startx < endx)
			my_mlx_pixel_put(back, startx++, y, CEIL);
	}
	while (starty < endy)
	{
		startx = savex;
		while (startx < endx)
			my_mlx_pixel_put(back, startx++, starty, 0x00F9F2C3);
		starty++;
	}
	while (starty < 800)
	{
		startx = savex;
		while (startx < endx)
			my_mlx_pixel_put(back, startx++, starty, FLOOR);
		starty++;
	}
}

void	draw_walls(t_map *map)
{
	double	dist;
	double	dir_start;
	double	dir_end;
	int		lineh;
	int		x;

	dir_end = map->pers.dir + FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir_start = dir_end - 2 * FOV2;

	x = 119;
	while (dir_end > dir_start && x > -1)
	{
		dist = ray_cast(map, dir_start, 2);
//		dist =
		lineh = 800 / dist;
		if (lineh > 800)
			lineh = 800;
		lineh /= 2;

//		pix_start_y = 400 - half_y_len;
//		pix_end_y = 400 + half_y_len;
		draw_line_w(&map->background, 400 - lineh, 400 + lineh, x);
		x--;
		dir_start += GR / 2;
	}
}
