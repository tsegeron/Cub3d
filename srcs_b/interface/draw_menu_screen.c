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

void	draw_buttons(t_interface *menu)
{
	int	y;
	int	x;

	y = 300;
	while (++y < 370)
	{
		x = 465;
		while (++x < 815)
			my_mlx_pixel_put(menu, x, y, 0x333A5739);
	}
	y = 400;
	while (++y < 470)
	{
		x = 465;
		while (++x < 815)
			my_mlx_pixel_put(menu, x, y, 0x44CF2E34);
	}
}

void	draw_menu_screen(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->menu_screen.size_y)
	{
		x = -1;
		while (++x < map->menu_screen.size_x)
			my_mlx_pixel_put(&map->menu_screen, x, y, 0x77000000);
	}
	draw_buttons(&map->menu_screen);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
		map->menu_screen.img, 0, 0);
}
