/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

void	draw_menu_screen(t_map *map)
{
	int	y;
	int	x;

	map->menu_screen.size_x = map->mlx.win_size_x;
	map->menu_screen.size_y = map->mlx.win_size_y;
	map->menu_screen.img = mlx_new_image(map->mlx.mlx, map->menu_screen.size_x, map->menu_screen.size_y);
	map->menu_screen.addr = mlx_get_data_addr(map->menu_screen.img, &map->menu_screen.bits_per_pixel, &map->menu_screen.line_length, &map->menu_screen.endian);

	//	dim background
	y = -1;
	while (++y < map->menu_screen.size_y)
	{
		x = -1;
		while (++x < map->menu_screen.size_x)
			my_mlx_pixel_put(&map->menu_screen, x, y, 0x77000000);
	}

	//	draw 2 buttons:
	//	continue
	y = 300;
	while (++y < 370)
	{
		x = 465;
		while (++x < 815)
			my_mlx_pixel_put(&map->menu_screen, x, y, 0x993A5739);
	}
	//	exit
	y = 400;
	while (++y < 470)
	{
		x = 465;
		while (++x < 815)
			my_mlx_pixel_put(&map->menu_screen, x, y, 0xBBF63C0F);
	}


	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->menu_screen.img, 0, 0);
}
