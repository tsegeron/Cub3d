/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/22 19:15:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

void	draw_background(t_map *map)	//	FOR TEST
{
	map->background.size_x = map->mlx.win_size_x;
	map->background.size_y = map->mlx.win_size_y;
	map->background.img = mlx_new_image(map->mlx.mlx,
										 map->background.size_x, map->background.size_y);
	map->background.addr = mlx_get_data_addr(map->background.img,
											  &map->background.bits_per_pixel, &map->background.line_length,
											  &map->background.endian);
	draw_walls(map);
	draw_ceil_and_floor(map);
//	int	i = -1;
//	while (++i < map->background.size_y)
//	{
//		int	j = -1;
//		while (++j < map->background.size_x)
//			my_mlx_pixel_put(&map->background, j, i, 0x00F9F2C3);	//	-	milky white
////			my_mlx_pixel_put(&map->background, j, i, 0x009DE3A2);	//	-	cyan
////			my_mlx_pixel_put(&map->background, j, i, 0x004B5320);	//	-	shrek
////			my_mlx_pixel_put(&map->background, j, i, 0x00D74442);	//	-	red 'o pink
//	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->background.img, 0, 0);
}

void	draw_interface(t_map *map)
{
//	draw_battery_bar(map);
//	draw_health_effect(map);




//
//	if (map->screen_stat == START)
//		draw_start_screen(map);
//	else if (map->screen_stat == MENU)
	if (map->screen_stat == MENU)
		draw_menu_screen(map);
//	else if (map->screen_stat == END)
//		draw_end_screen(map);
}

//	9DE3A2	-	cyan
//	5F6D4C	-	nasty green
