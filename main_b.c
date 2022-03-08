#include "hdrs/cub3d_bonus.h"

#include "srcs_b/3d/L3d.h"

static void	init_all2(t_map *map)
{
	map->battery_bar.size_x = map->mlx.win_size_x / 5;
	map->battery_bar.size_y = map->mlx.win_size_y / 25 - 15;
	map->battery_bar.posx = 15;
	map->battery_bar.posy = map->mlx.win_size_y - map->battery_bar.size_y - 10;
	map->battery_bar.img = mlx_new_image(map->mlx.mlx, \
	map->battery_bar.size_x, map->battery_bar.size_y);
	map->battery_bar.addr = mlx_get_data_addr(map->battery_bar.img, \
	&map->battery_bar.bits_per_pixel, &map->battery_bar.line_length, \
	&map->battery_bar.endian);
	map->menu_screen.size_x = map->mlx.win_size_x;
	map->menu_screen.size_y = map->mlx.win_size_y;
	map->menu_screen.img = mlx_new_image(map->mlx.mlx, \
	map->menu_screen.size_x, map->menu_screen.size_y);
	map->menu_screen.addr = mlx_get_data_addr(map->menu_screen.img, \
	&map->menu_screen.bits_per_pixel, &map->menu_screen.line_length, \
	&map->menu_screen.endian);
	map->key.w = false;
	map->key.a = false;
	map->key.s = false;
	map->key.d = false;
	map->key.left = false;
	map->key.right = false;
	if (!map->back.img || !map->health.img || !map->round_minmap.img
			|| !map->battery_bar.img || !map->menu_screen.img)
		exit((int )write(2, "Error: mlx_new_image\n", 21));
}

static void	init_all1(t_map *map)
{
	map->back.size_x = map->mlx.win_size_x;
	map->back.size_y = map->mlx.win_size_y;
	map->back.img = mlx_new_image(map->mlx.mlx, \
	map->back.size_x,map->back.size_y);
	map->back.addr = mlx_get_data_addr(map->back.img, \
	&map->back.bits_per_pixel, &map->back.line_length, \
	&map->back.endian);
	map->health.size_x = map->mlx.win_size_x;
	map->health.size_y = map->mlx.win_size_y;
	map->health.img = mlx_new_image(map->mlx.mlx, \
	map->health.size_x, map->health.size_y);
	map->health.addr = mlx_get_data_addr(map->health.img, \
	&map->health.bits_per_pixel, &map->health.line_length, \
	&map->health.endian);
	map->round_minmap.size_x = map->mlx.win_size_y / 4 + 20;
	map->round_minmap.size_y = map->mlx.win_size_y / 4 + 20;
	map->round_minmap.img = mlx_new_image(map->mlx.mlx, \
	map->round_minmap.size_x, map->round_minmap.size_y);
	map->round_minmap.addr = mlx_get_data_addr(map->round_minmap.img, \
	&map->round_minmap.bits_per_pixel, &map->round_minmap.line_length, \
	&map->round_minmap.endian);
	map->light.size_x = 200;
	map->light.size_y = 200;
	map->light.img = mlx_new_image(map->mlx.mlx, \
	map->light.size_x, map->light.size_y);
	map->light.addr = mlx_get_data_addr(map->light.img, \
	&map->light.bits_per_pixel, &map->light.line_length, \
	&map->light.endian);
}

static void	craft_the_window(t_map *map)
{
	map->mlx.win_size_x = 1320;
	map->mlx.win_size_y = 800;
	map->mlx.win = mlx_new_window(map->mlx.mlx, map->mlx.win_size_x,
		map->mlx.win_size_y, "Cub3d");
	map->screen_stat = START;
}

//	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->vars.rasengan.img,
//			map->map_width * 5 / 8 - map->vars.wand.size_x,
//			map->map_height - map->vars.wand.size_y);

static int	render_frame(t_map *map)
{
	static int	random;

	if (random % 2 && map->screen_stat == NOSCREEN)
	{
		m_enemy_action(map);
		random = 0;
	}
	else if (map->screen_stat == NOSCREEN)
		random++;
	handle_mouse_pos(map);
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	check_buttons(map);
	if (map->screen_stat == NOSCREEN || map->screen_stat == MENU)
	{
		draw_walls(map);
		draw_wand_and_light(map);
//		draw_rasengan(map);
		draw_health_effect(map);
		draw_round_minimap(map);
		draw_battery_bar(map);
	}
	draw_interface(map);	//	draws start, end, menu screen
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
	init_all1(&map);
	init_all2(&map);
	mlx_mouse_move(map.mlx.win, map.mlx.win_size_x / 2, map.mlx.win_size_y / 2);
	mlx_hook(map.mlx.win, 2, 1L << 0, press_key, &map);
	mlx_hook(map.mlx.win, 3, 1L << 1, release_key, &map.key);
	mlx_hook(map.mlx.win, 17, 1L << 0, close_win, &map);
	if (map.screen_stat == NOSCREEN)
		mlx_mouse_hook(map.mlx.win, m_player_attack, &map);
	mlx_loop_hook(map.mlx.mlx, render_frame, &map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
