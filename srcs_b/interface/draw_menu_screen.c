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

#include "../../hdrs/cub3d_bonus.h"

void	draw_buttons(t_interface *menu)
{
	int	y;
	int	x;

	y = 300;
	while (++y < 370)
	{
		x = 465;
		while (++x < 815)
			my_mlx_pixel_put(menu, x, y, 0x223A5739);
	}
	y = 400;
	while (++y < 470)
	{
		x = 465;
		while (++x < 815)
			my_mlx_pixel_put(menu, x, y, 0x229B3335);
	}
}

void	draw_menu_screen(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->menu_screen.size_y - 1)
	{
		x = -1;
		while (++x < map->menu_screen.size_x - 1)
			my_mlx_pixel_put(&map->menu_screen, x, y, 0x55000000);
	}
	draw_buttons(&map->menu_screen);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
		map->menu_screen.img, 0, 0);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->vars.but_imgs[0].img, 465, 300);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->vars.but_imgs[1].img, 465, 400);
}
