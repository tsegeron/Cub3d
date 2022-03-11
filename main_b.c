/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:34:59 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/08 22:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/cub3d_bonus.h"

static void	craft_the_window(t_map *map)
{
	map->mlx.win_size_x = 1320;
	map->mlx.win_size_y = 800;
	map->mlx.win = mlx_new_window(map->mlx.mlx, map->mlx.win_size_x, \
	map->mlx.win_size_y, "Cub3d");
	map->screen_stat = START;
}

static int	render_frame(t_map *map)
{
	static int	random;

	handle_mouse_pos(map);
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	check_buttons(map);
	if (map->screen_stat == NOSCREEN || map->screen_stat == MENU)
	{
		draw_walls(map, &random);
		draw_wand_and_light(map);
		draw_health_effect(map);
		draw_round_minimap(map);
		draw_battery_bar(map);
	}
	draw_interface(map);
	mlx_do_sync(map->mlx.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2 || m_pars(av, &map))
		return (m_clear_all(&map));
	map.map_height = (int)ft_len_array(map.map);
	craft_the_window(&map);
	init_all(&map);
	mlx_mouse_move(map.mlx.win, map.mlx.win_size_x / 2, map.mlx.win_size_y / 2);
	mlx_hook(map.mlx.win, 2, 1L << 0, press_key, &map);
	mlx_hook(map.mlx.win, 3, 1L << 1, release_key, &map.key);
	mlx_hook(map.mlx.win, 17, 1L << 0, close_win, &map);
	mlx_mouse_hook(map.mlx.win, m_player_attack, &map);
	mlx_mouse_hook(map.mlx.win, handle_mouse_keys, &map);
	mlx_loop_hook(map.mlx.mlx, render_frame, &map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
