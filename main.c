#include "hdrs/cub3d.h"

int	close_win(t_map *map)
{
	for (int i = 0; map->map[i]; i++)
		free(map->map[i]);
	free(map->map);
	exit(EXIT_SUCCESS);
}

static int	render_frame(t_map *map)
{
	static int	random;

//	if (random > 500)
//	{
		handle_mouse_pos(map);
		mlx_clear_window(map->mlx.mlx, map->mlx.win);
		if (map->screen_stat == NOSCREEN || map->screen_stat == MENU)
		{
			draw_background(map);	//	for test
			draw_health_effect(map);
			draw_round_minimap(map);
			draw_battery_bar(map);
		}
		draw_interface(map);	//	draws start, end, menu screen
		mlx_do_sync(map->mlx.mlx);
		random = 0;
//	}
	random += 1;
	return (0);
}

void	init_all(t_map *map)
{
	map->background.size_x = map->mlx.win_size_x;
	map->background.size_y = map->mlx.win_size_y;
	map->background.img = mlx_new_image(map->mlx.mlx, map->background.size_x, map->background.size_y);
	map->background.addr = mlx_get_data_addr(map->background.img, &map->background.bits_per_pixel, &map->background.line_length, &map->background.endian);

	map->health.size_x = map->mlx.win_size_x;
	map->health.size_y = map->mlx.win_size_y;
	map->health.img = mlx_new_image(map->mlx.mlx, map->health.size_x, map->health.size_y);
	map->health.addr = mlx_get_data_addr(map->health.img, &map->health.bits_per_pixel, &map->health.line_length, &map->health.endian);

	map->round_minmap.size_x = map->mlx.win_size_y / 4 + 20;
	map->round_minmap.size_y = map->mlx.win_size_y / 4 + 20;
	map->round_minmap.img = mlx_new_image(map->mlx.mlx, map->round_minmap.size_x, map->round_minmap.size_y);
	map->round_minmap.addr = mlx_get_data_addr(map->round_minmap.img, &map->round_minmap.bits_per_pixel, &map->round_minmap.line_length, &map->round_minmap.endian);

	map->battery_bar.size_x = map->mlx.win_size_x / 5;
	map->battery_bar.size_y = map->mlx.win_size_y / 25 - 15;
	map->battery_bar.posx = 15;
	map->battery_bar.posy = map->mlx.win_size_y - map->battery_bar.size_y - 10;
	map->battery_bar.img = mlx_new_image(map->mlx.mlx, map->battery_bar.size_x, map->battery_bar.size_y);
	map->battery_bar.addr = mlx_get_data_addr(map->battery_bar.img, &map->battery_bar.bits_per_pixel, &map->battery_bar.line_length, &map->battery_bar.endian);

	map->menu_screen.size_x = map->mlx.win_size_x;
	map->menu_screen.size_y = map->mlx.win_size_y;
	map->menu_screen.img = mlx_new_image(map->mlx.mlx, map->menu_screen.size_x, map->menu_screen.size_y);
	map->menu_screen.addr = mlx_get_data_addr(map->menu_screen.img, &map->menu_screen.bits_per_pixel, &map->menu_screen.line_length, &map->menu_screen.endian);

}

void	craft_the_window(t_map *map)
{
	map->mlx.win_size_x = 1320;
	map->mlx.win_size_y = 800;
	map->mlx.win = mlx_new_window(map->mlx.mlx, map->mlx.win_size_x, map->mlx.win_size_y, "Cub3d");
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2 || m_pars(av, &map))
		return (EXIT_FAILURE);
	map.map_height = ft_len_array(map.map);
	map.screen_stat = NOSCREEN;
	craft_the_window(&map);
	init_all(&map);
	mlx_mouse_move(map.mlx.win, map.mlx.win_size_x / 2, map.mlx.win_size_y / 2);	// moves mouse at the center
	mlx_hook(map.mlx.win, 2, 1L << 1, g_do_keys, &map);		// key management
	mlx_hook(map.mlx.win, 17, 1L << 0, close_win, &map);	// closes on mouse click
	mlx_loop_hook(map.mlx.mlx, render_frame, &map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
