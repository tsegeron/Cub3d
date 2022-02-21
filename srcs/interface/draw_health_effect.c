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
	int	step_x;
	int	step_y;
	int	x_end;

	if (map->pers.health > 2)
		return ;
	map->health.size_x = map->mlx.win_size_x;
	map->health.size_y = map->mlx.win_size_y;
	map->health.img = mlx_new_image(map->mlx.mlx, map->health.size_x, map->health.size_y);
	map->health.addr = mlx_get_data_addr(map->health.img, &map->health.bits_per_pixel, &map->health.line_length, &map->health.endian);


	step_x = 2;
	step_y = 5;
	y = -1;
	if (map->pers.health == 2)
	{
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
	}



//	if (map->pers.health == 1)
//	{
//
//	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->health.img, 0, 0);
}
