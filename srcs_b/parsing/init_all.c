/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

void	init_imgs(t_map *map)
{
	map->back.img = mlx_new_image(map->mlx.mlx, \
	map->back.size_x, map->back.size_y);
	map->health.img = mlx_new_image(map->mlx.mlx, \
	map->health.size_x, map->health.size_y);
	map->round_minmap.img = mlx_new_image(map->mlx.mlx, \
	map->round_minmap.size_x, map->round_minmap.size_y);
	map->light.img = mlx_new_image(map->mlx.mlx, \
	map->light.size_x, map->light.size_y);
	map->battery_bar.img = mlx_new_image(map->mlx.mlx, \
	map->battery_bar.size_x, map->battery_bar.size_y);
	map->menu_screen.img = mlx_new_image(map->mlx.mlx, \
	map->menu_screen.size_x, map->menu_screen.size_y);
	if (!map->back.img || !map->health.img || !map->round_minmap.img
		|| !map->light.img || !map->battery_bar.img || !map->menu_screen.img)
	{
		write(2, "Error: mlx_new_image\n", 21);
		m_clear_all(map);
	}
}

void	init_addrs(t_map *map)
{
	map->back.addr = mlx_get_data_addr(map->back.img, \
	&map->back.bits_per_pixel, &map->back.line_length, \
	&map->back.endian);
	map->health.addr = mlx_get_data_addr(map->health.img, \
	&map->health.bits_per_pixel, &map->health.line_length, \
	&map->health.endian);
	map->round_minmap.addr = mlx_get_data_addr(map->round_minmap.img, \
	&map->round_minmap.bits_per_pixel, &map->round_minmap.line_length, \
	&map->round_minmap.endian);
	map->light.addr = mlx_get_data_addr(map->light.img, \
	&map->light.bits_per_pixel, &map->light.line_length, \
	&map->light.endian);
	map->battery_bar.addr = mlx_get_data_addr(map->battery_bar.img, \
	&map->battery_bar.bits_per_pixel, &map->battery_bar.line_length, \
	&map->battery_bar.endian);
	map->menu_screen.addr = mlx_get_data_addr(map->menu_screen.img, \
	&map->menu_screen.bits_per_pixel, &map->menu_screen.line_length, \
	&map->menu_screen.endian);
	if (!map->back.addr || !map->health.addr || !map->round_minmap.addr
		|| !map->light.addr || !map->battery_bar.addr || !map->menu_screen.addr)
	{
		write(2, "Error: mlx_get_data_addr\n", 25);
		m_clear_all(map);
	}
}

void	init_all(t_map *map)
{
	map->back.size_x = map->mlx.win_size_x;
	map->back.size_y = map->mlx.win_size_y;
	map->health.size_x = map->mlx.win_size_x;
	map->health.size_y = map->mlx.win_size_y;
	map->round_minmap.size_x = map->mlx.win_size_y / 4 + 20;
	map->round_minmap.size_y = map->mlx.win_size_y / 4 + 20;
	map->light.size_x = 200;
	map->light.size_y = 200;
	map->battery_bar.size_x = map->mlx.win_size_x / 5;
	map->battery_bar.size_y = map->mlx.win_size_y / 25 - 15;
	map->battery_bar.posx = 15;
	map->battery_bar.posy = map->mlx.win_size_y - map->battery_bar.size_y - 10;
	map->menu_screen.size_x = map->mlx.win_size_x;
	map->menu_screen.size_y = map->mlx.win_size_y;
	map->key.w = false;
	map->key.a = false;
	map->key.s = false;
	map->key.d = false;
	map->key.e = false;
	map->key.left = false;
	map->key.right = false;
	init_imgs(map);
	init_addrs(map);
}
