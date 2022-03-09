/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/24 19:05:50 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"
#include "./L3d.h"

static void	get_wall_info(t_map *map, t_wall_clr *data, double dir)
{
	double	dist_on_y;
	double	dist_on_x;

	dist_on_y = cast_on_y_tex(map, dir, 'D');
	dist_on_x = cast_on_x_tex(map, dir, 'D');
	if (dist_on_y > dist_on_x)
		get_ea_we_data(&map->vars, data, dist_on_x, dir);
	else
		get_no_so_data(&map->vars, data, dist_on_y, dir);
	calc_tex_dims(map, data, dir);
}

void	draw_doors(t_map *map)
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
		draw_line_w(map, 800 / data.dist / 2, data, x);
		dir_start += 0.00158666;
		x--;
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->back.img, 0, 0);
}
