/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/cub3d.h"

static int	render_frame(t_map *map)
{
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	check_buttons(map);
	draw_walls(map);
	mlx_do_sync(map->mlx.mlx);
	return (0);
}

static void	craft_the_window(t_map *map)
{
	map->mlx.win_size_x = 1320;
	map->mlx.win_size_y = 800;
	map->mlx.win = mlx_new_window(map->mlx.mlx, map->mlx.win_size_x,
			map->mlx.win_size_y, "Cub3d");
}

static void	init_all(t_map *map)
{
	map->back.size_x = map->mlx.win_size_x;
	map->back.size_y = map->mlx.win_size_y;
	map->back.img = mlx_new_image(map->mlx.mlx,
			map->back.size_x, map->back.size_y);
	map->back.addr = mlx_get_data_addr(map->back.img,
			&map->back.bits_per_pixel, &map->back.line_length,
			&map->back.endian);
	map->key.w = 0;
	map->key.a = 0;
	map->key.s = 0;
	map->key.d = 0;
	map->key.left = 0;
	map->key.right = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2 || m_pars(av, &map))
		return (EXIT_FAILURE);
	map.map_height = (int )ft_len_array(map.map);
	craft_the_window(&map);
	init_all(&map);
	mlx_mouse_move(map.mlx.win, map.mlx.win_size_x / 2,
		map.mlx.win_size_y / 2);
	mlx_hook(map.mlx.win, 2, 1L << 0, press_key, &map);
	mlx_hook(map.mlx.win, 3, 1L << 1, release_key, &map.key);
	mlx_hook(map.mlx.win, 17, 1L << 0, close_win, &map);
	mlx_loop_hook(map.mlx.mlx, render_frame, &map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
