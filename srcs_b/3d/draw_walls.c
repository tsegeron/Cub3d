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

#include "../../hdrs/cub3d_bonus.h"
#include "./L3d.h"

static void	get_wall_info(t_map *map, t_wall_clr *data, double dir, char c)
{
	double	dist_on_y;
	double	dist_on_x;

	dist_on_y = cast_on_y_tex(map, dir, c);
	dist_on_x = cast_on_x_tex(map, dir, c);
	if (dist_on_y > dist_on_x)
		get_ea_we_data(&map->vars, data, dist_on_x, dir);
	else
		get_no_so_data(&map->vars, data, dist_on_y, dir);
	data->y = fabs(sin(dir) * data->dist);
	data->x = fabs(cos(dir) * data->dist);
	calc_tex_dims(map, data, dir);
}

static void	set_the_door_done(t_map *map, int *stat)
{
	if (map->key.e)
	{
		(*stat)++;
		if ((*stat) > 64)
		{
			(*stat) = 0;
			if (map->map[map->vars.door.posy][map->vars.door.posx] == 'P' \
			&& map->key.e == 1)
				map->map[map->vars.door.posy][map->vars.door.posx] = 'O';
			else if (map->map[map->vars.door.posy][map->vars.door.posx] == 'P' \
			&& map->key.e == 2)
				map->map[map->vars.door.posy][map->vars.door.posx] = 'C';
			map->key.e = 0;
		}
	}
}

static void	do_calc(t_map *map, t_wall_clr	*data, double dir, int *stat)
{
	double		delta_dir;

	if (data->wall_stat == 3)
		data->wall_stat = 0;
	delta_dir = map->pers.dir - dir;
	if (delta_dir < 0)
		delta_dir += 2 * PI;
	else if (delta_dir > 2 * PI)
		delta_dir -= 2 * PI;
	get_wall_info(map, data, dir, 'D');
	if (data->wall_stat == 1)
		get_wall_info(map, data, dir, 'W');
	if (data->wall_stat == 3)
		data->rand = *stat;
	data->dist *= cos(delta_dir);
}

void	draw_walls(t_map *map, int *stat)
{
	t_wall_clr	data;
	double		dir_start;
	double		dir_end;
	int			x;

	data.wall_stat = 0;
	dir_end = map->pers.dir + FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir_start = dir_end - 2 * FOV2;
	x = 659;
	while (dir_end > dir_start && x > -1)
	{
		do_calc(map, &data, dir_start, stat);
		draw_line_w(map, 800 / data.dist / 2, data, x);
		if (data.wall_stat == 1)
		{
			data.wall_stat = 2;
			continue ;
		}
		dir_start += 0.00158666;
		x--;
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->back.img, 0, 0);
	set_the_door_done(map, stat);
}
