#include "hdrs/cub3d.h"

int	close_win(t_map *map)
{
	for (int i = 0; map->map[i]; i++)
		free(map->map[i]);
	free(map->map);
//	mlx_destroy_image();
	exit(EXIT_SUCCESS);
}

void	craft_the_window(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.win_size_x = 1280;
	map->mlx.win_size_y = 800;
	map->mlx.win = mlx_new_window(map->mlx.mlx, map->mlx.win_size_x, map->mlx.win_size_y, "Cub3d");
	mlx_hook(map->mlx.win, 17, 1L << 0, close_win, map); // closes on mouse click
}

int	main(int ac, char **av)
{
	t_map	map;

	/* ---Parsing--- */
//	if (ac > 2 || m_pars(av, &map.map) || m_check_map(map.map))
//		return (EXIT_FAILURE);
//	printf("PATH NO : %s\nPATH SO : %s\nPATH WE : %s\nPATH EA : %s\n", \
//			path_no, path_so, path_we, path_ea);
//	for (int i = 0; i < 3; i++)
//		printf("f[%d] : %d\n", i, f[i]);
//	for (int i = 0; i < 3; i++)
//		printf("c[%d] : %d\n", i, cel[i]);
//	printf("--------------------------------------\n");
//	for (int i = 0; map.map[i]; i++)
//		printf("%s\n", map.map[i]);

	map.map = (char **) malloc(sizeof(char *) * 11);
	map.map[0] = ft_strdup("1111111111");
	map.map[1] = ft_strdup("1010101001");
	map.map[2] = ft_strdup("1010101001");
	map.map[3] = ft_strdup("1000000001");
	map.map[4] = ft_strdup("1110111011");
	map.map[5] = ft_strdup("1000000001");
	map.map[6] = ft_strdup("1000000001");
	map.map[7] = ft_strdup("1000000001");
	map.map[8] = ft_strdup("1000000001");
	map.map[9] = ft_strdup("1111111111");
	map.map[10] = NULL;
	map.map_width = 10;
	map.map_height = 10;

	map.pers.posx = 8;
	map.pers.posy = 8;
//	printf("%.1f %.1f\n", map.pers.posx, map.pers.posy);
	map.pers.dir = 0;							// 0
//	map.pers.dir = GR;							// 1
//	map.pers.dir = 3.14159265 / 2.0 - 0.017452;	// 89
//	map.pers.dir = 3.14159265 / 2.0;			// 90
//	map.pers.dir = 3.14159265 / 2.0 + 0.017452;	// 91
//	map.pers.dir = 3.14159265 / 2.0 + PI2 / 2.0;//
//	map.pers.dir = 3.14159265 - 0.017452;		// 179
//	map.pers.dir = 3.14159265 + 0.017452 * 1;	// 179
//	map.pers.dir = 1.5 * 3.14159265 - 0.017452;	// 269
//	map.pers.dir = 2 * 3.14159265 - 0.017452;	// 359
	map.pers.fov = 3.14159265 / 3.0;

	/* ---Craft a window--- */
	craft_the_window(&map);

	/* ---Draw minimap--- */
	draw_minimap(&map);

	/* ---Keys management--- */
	mlx_hook(map.mlx.win, 2, 1L << 1, g_do_keys, &map);


	// Draw 3d view


	mlx_loop(map.mlx.mlx);
	return (0);
}
