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

#include "../../hdrs/cub3d.h"

void	draw_health_effect(t_map *map)
{
	int	y;
	int	x;
	int	rad;
	int	color;

	if (map->pers.health > 2)
		return ;
	map->health.size_x = map->mlx.win_size_x;
	map->health.size_y = map->mlx.win_size_y;
	map->health.img = mlx_new_image(map->mlx.mlx, map->health.size_x, map->health.size_y);
	map->health.addr = mlx_get_data_addr(map->health.img, &map->health.bits_per_pixel, &map->health.line_length, &map->health.endian);

	if (map->pers.health == 2)
		color = 0xDDFF0000;
	else if (map->pers.health == 1)
		color = 0xBBFF0000;
	rad = 110;
	y = -1;
	while (++y < map->health.size_y)
	{
		x = -1;
		while (++x < map->health.size_x)
		{
			if (rad >= sqrt((y - 25 - rad) * (y - 25 - rad) + (x - 32 - rad) * (x - 32 - rad)))
				my_mlx_pixel_put(&map->health, x, y, EMPTY);
			else
				my_mlx_pixel_put(&map->health, x, y, color);
		}
	}






//	if (map->pers.health == 1)
//	{
//		step_x = 2;
//		step_y = 2;
//	}
//	else if (map->pers.health == 2)
//	{
//		step_x = 3;
//		step_y = 3;
//	}
//	rad = 110;
//	y = -1;
//	while (++y < map->health.size_y)
//	{
//		x = 0;
//		if (y % step_y)
//			while (++x < map->health.size_x)
//				my_mlx_pixel_put(&map->health, x, y, EMPTY);
//		else
//			while (++x < map->health.size_x)
//			{
//				if (rad >= sqrt((y - 25 - rad) * (y - 25 - rad) + (x - 32 - rad) * (x - 32 - rad)))
//				{
//					my_mlx_pixel_put(&map->health, x, y, EMPTY);
//					continue ;
//				}
//				if (!(x % step_x))
//					my_mlx_pixel_put(&map->health, x, y, 0x33FF0000);
//				else
//					my_mlx_pixel_put(&map->health, x, y, EMPTY);
//			}
//	}



//		while (++y < map->health.size_y)
//		{
//		while (++y < 40)
//		{
//			x = -1;
//			while (++x < map->mlx.win_size_x)
//			{
//				if (!(x % step_x))
//					my_mlx_pixel_put(&map->health, x, y, AIM);
//				else
//					my_mlx_pixel_put(&map->health, x, y, EMPTY);
//			}
//			step_x += 1;
//		}
//		while (y < map->health.size_y - 40)
//		{
//			x = -1;
//			while (++x < map->mlx.win_size_x)
//				my_mlx_pixel_put(&map->health, x, y, EMPTY);
//			y++;
//		}
//		while (y < map->health.size_y)
//		{
//			x = -1;
//			while (++x < map->mlx.win_size_x)
//				my_mlx_pixel_put(&map->health, x, y, AIM);
//			y++;
//		}
//		if (!((x >= 0 && x < 20) || (x >= map->health.size_x - 20 && x < map->health.size_x)))
//			y = map->health.size_y - 20;
//		}

//	if (map->pers.health == 1)
//	{
//
//	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->health.img, 0, 0);
}
