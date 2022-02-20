/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

void	draw_background(t_map *map)
{
	map->background.size_x = map->mlx.win_size_x;
	map->background.size_y = map->mlx.win_size_y;
	map->background.img = mlx_new_image(map->mlx.mlx,
										 map->background.size_x, map->background.size_y);
	map->background.addr = mlx_get_data_addr(map->background.img,
											  &map->background.bits_per_pixel, &map->background.line_length,
											  &map->background.endian);
	int	i = -1;
	while (++i < map->background.size_y)
	{
		int	j = -1;
		while (++j < map->background.size_x)
			my_mlx_pixel_put(&map->background, j, i, 0x004B5320);
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->background.img, 0, 0);
}

void	draw_interface(t_map *map)
{
	draw_battery_bar(map);



}
