/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_round_minimap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:51:02 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 23:04:47 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

static void	draw_round_minimap_background(t_interface *r_minimap)
{
	int	y;
	int	x;
	int	rad;
	int	res;

	y = -1;
	rad = 110;
	while (++y < r_minimap->size_y)
	{
		x = -1;
		while (++x < r_minimap->size_x)
		{
			res = sqrt((y - rad) * (y - rad) + (x - rad) * (x - rad));
			if (rad > res)
				my_mlx_pixel_put(r_minimap, x, y, 0xBBF9F2C3);
			else
				my_mlx_pixel_put(r_minimap, x, y, EMPTY);
		}
	}
}

static void	draw_player_in_round_minimap(t_interface *minimap)
{
	int		x;
	int		y;
	int		end;
	int		save_y;

	save_y = minimap->size_x / 2 - 2;
	end = save_y + 4;
	x = save_y;
	while (x < end)
	{
		y = save_y;
		while (y < end)
		{
			my_mlx_pixel_put(minimap, x, y, PLAYER);
			y++;
		}
		x++;
	}
}

static void	draw_fov_in_round_minimap(t_map *map)
{
	double	line_end_x;
	double	line_end_y;
	double	dir_start;
	double	dir_end;
	double	dir_center;

	dir_end = map->pers.dir + FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir_start = dir_end - 2 * FOV2;
	dir_center = dir_end - 30 * GR;
	while (dir_start <= dir_end)
	{
		line_end_x = 110 + ray_cast(map, dir_start, 0);
		line_end_y = 110 + ray_cast(map, dir_start, 1);
		if (fabs(dir_start - dir_center) < GR / 2)
			draw_line(map->round_minmap, line_end_x, line_end_y, AIM);
		else
			draw_line(map->round_minmap, line_end_x, line_end_y, FOV);
		dir_start += GR / 2;
	}
}

void	draw_round_minimap(t_map *map)
{
	draw_round_minimap_background(&map->round_minmap);
	draw_minimap_elements(map);
	draw_fov_in_round_minimap(map);
	draw_player_in_round_minimap(&map->round_minmap);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
		map->round_minmap.img, 32, 25);
}
