/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_health_effect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

void	get_color(double hp, int *color)
{
	if (round(hp) == 2.)
		*color = 0xDDFF0000;
	else if (round(hp) == 1.)
		*color = 0xBBFF0000;
	else if (round(hp) == 0)
		*color = 0x11FF0000;
}

void	draw_health_effect(t_map *map)
{
	int	y;
	int	x;
	int	rad;
	int	color;

	if (round(map->pers.health) > 2.)
		return ;
	get_color(map->pers.health, &color);
	rad = 110;
	y = -1;
	while (++y < map->health.size_y)
	{
		x = -1;
		while (++x < map->health.size_x)
		{
			if (rad >= sqrt((y - 25 - rad) * (y - 25 - rad)
					+ (x - 32 - rad) * (x - 32 - rad)))
				my_mlx_pixel_put(&map->health, x, y, EMPTY);
			else
				my_mlx_pixel_put(&map->health, x, y, color);
		}
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->health.img, 0, 0);
	if (round(map->pers.health) == 0.)
		map->screen_stat = MENU;
}
