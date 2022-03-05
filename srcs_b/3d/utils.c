/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/24 19:05:50 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"
#include "./L3d.h"

void	get_ea_we_data(t_vars *vars, t_wall_clr *data, double dist, double dir)
{
	if ((dir < 1.5 * PI && dir > PI2) || (dir < 3.5 * PI && dir > 2.5 * PI))
	{
		data->wall_img = vars->path_we;
		data->side = 3;
	}
	else
	{
		data->wall_img = vars->path_ea;
		data->side = 4;
	}
	data->dist = dist;
}

void	get_no_so_data(t_vars *vars, t_wall_clr *data, double dist, double dir)
{
	if ((dir < PI && dir > 0) || (dir < 3 * PI && dir > 2 * PI))
	{
		data->wall_img = vars->path_no;
		data->side = 1;
	}
	else
	{
		data->wall_img = vars->path_so;
		data->side = 2;
	}
	data->dist = dist;
}

void	calc_tex_dims(t_map *map, t_wall_clr *data, double dir)
{
	data->y = fabs(sin(dir) * data->dist);
	data->x = fabs(cos(dir) * data->dist);
	if (dir < PI && dir > 0)
		data->y = -data->y;
	if (dir > PI2 && dir < PI2 * 3)
		data->x = -data->x;
	data->x += map->pers.posx;
	data->y += map->pers.posy;
//	printf("%f %f\n", data->x, data->y);
	if (map->map[(int)(data->y)][(int)(data->x)] == 'C')
		data->wall_img = map->vars.door;
	if ((dir < PI && dir > 0) || (dir < 3 * PI && dir > 2 * PI))
		data->x -= floor(data->x);
	else
		data->x = ceil(data->x) - data->x;
	if ((dir < 1.5 * PI && dir > PI2) || (dir < 3.5 * PI && dir > 2.5 * PI))
		data->y = ceil(data->y) - data->y;
	else
		data->y -= floor(data->y);
	data->x *= data->wall_img.size_x;
	data->y *= data->wall_img.size_y;
}

int	shade_color(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
			+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
			+ ((int)((0x0000FF & color) / divide)));
}

int	get_pixel(t_interface wall, double x, double y)
{
	int		*dst;
	int		color;

	dst = (void *)wall.addr + ((int )y * wall.line_length
			+ (int )x * (wall.bits_per_pixel / 8));
	color = *(int *)dst;
	return (color);
}
