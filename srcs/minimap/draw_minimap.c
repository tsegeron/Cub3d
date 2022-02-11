#include "../../hdrs/cub3d.h"

void	my_mlx_pixel_put(t_minimap *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	paint_rect(t_minimap map, int x, int y, int endx, int endy)
{
	int	save_y;

	save_y = y;
	while (x < endx)
	{
		y = save_y;
		while ( y < endy)
		{
			my_mlx_pixel_put(&map, x, y, 0x0050C878);
			y++;
		}
		x++;
	}
}

void	draw_pers_in_minimap(t_map *map)
{
	map->minimap.posx = map->minimap.minimap_size_x / 2; // 160
	map->minimap.posy = map->minimap.minimap_size_y / 2; // 100
	paint_rect(map->minimap, map->minimap.posx - 3, map->minimap.posy - 3, \
	map->minimap.posx + 3, map->minimap.posy + 3);
}

void	paint_area(t_minimap map, double y, double x, int color)
{
	double	stepx;
	double	stepy;
	double	endx;
	double	endy;
	double	save_x;

	stepx = x * 32;
	stepy = y * 20;
	endx = stepx + 32.0;
	endy = stepy + 20.0;
	save_x = stepx;
	while (stepy < endy)
	{
		stepx = save_x;
		while (stepx < endx)
		{
			my_mlx_pixel_put(&map, (int)stepx, (int)stepy, color);
			stepx += 1.0;
		}
		stepy += 1.0;
	}
}

void	draw_relative_minimap(t_map *map)
{
//	int		midx;
//	int		midy;
//	double	posx;
//	double	posy;
	double	start_on_x;
	double	start_on_y;
	double	end_on_x;
	double	end_on_y;
	double	difx;
	double	dify;
	double	save_x;

//	midx = map->minimap.minimap_size_x / 2;
//	midy = map->minimap.minimap_size_y / 2;
//	posx = map->pers.posx;
//	posy = map->pers.posy;
	start_on_x = map->pers.posx - 5.0;
	start_on_y = map->pers.posy - 5.0;
	end_on_x = start_on_x + 9.0;
	end_on_y = start_on_y + 9.0;
	// 32x20 10 times
	difx = 5.0 - map->pers.posx;
	dify = 5.0 - map->pers.posy;
//	printf("%.3f, %.3f %.3f, %.3f\n", start_on_x, start_on_y, end_on_x, end_on_y);
	if (start_on_x < 0.0)
		start_on_x = 0.0;
	if (start_on_y < 0.0)
		start_on_y = 0.0;
	if (end_on_x > (double)map->map_width)
		end_on_x = (double)map->map_width;
	if (end_on_y > (double)map->map_height)
		end_on_y = (double)map->map_height;
//	printf("%d %d\n", map->map_width, map->map_height);
//	printf("%.3f %.3f %.3f %.3f\n", start_on_x, start_on_y, end_on_x, end_on_y);
	save_x = start_on_x;
	while (start_on_y < end_on_y)
	{
		start_on_x = save_x;
		while (start_on_x < end_on_x)
		{
			if (map->map[(int)start_on_y][(int)start_on_x] == '1')
				paint_area(map->minimap, (start_on_y + dify), (start_on_x + difx), 0x00FF0000);
			else if (map->map[(int)start_on_y][(int)start_on_x] == '0')
				paint_area(map->minimap, (start_on_y + dify), (start_on_x + difx), 0x00808080);
			start_on_x += 0.25;
		}
		start_on_y += 0.25;
//		printf("%.3f %.3f\n", start_on_x, start_on_y);
//		break ;
	}
}

void	draw_minimap(t_map *map)
{
	map->minimap.minimap_size_x = map->mlx.win_size_x / 4; // 320 5 2 2 2 2 2 2
	map->minimap.minimap_size_y = map->mlx.win_size_y / 4; // 200 5 2 2 2 5
	map->minimap.img = mlx_new_image(map->mlx.mlx, map->minimap.minimap_size_x, map->minimap.minimap_size_y);
	map->minimap.addr = mlx_get_data_addr(map->minimap.img, &map->minimap.bits_per_pixel, &map->minimap.line_length, &map->minimap.endian);

//	for (int i = 0; i < map->minimap.minimap_size_x; i++)
//		for (int j = 0; j < map->minimap.minimap_size_y; j++)
//		{
//			if ((i / 20 % 2 + j / 20 % 2) % 2)
//				my_mlx_pixel_put(&map->minimap, i, j, 0x00808080);
//			else
//				my_mlx_pixel_put(&map->minimap, i, j, 0x00FF0000);
//		}

	draw_relative_minimap(map);
	draw_pers_in_minimap(map);
//	printf("%.3f %0.3f\n", map->pers.posx, map->pers.posy);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->minimap.img, 0, 0);
}
