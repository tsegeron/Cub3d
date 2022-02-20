#include "../../hdrs/cub3d.h"

void	draw_line_r(t_interface map, double endx, double endy, int color)
{
	double	startx;
	double	starty;
	double	deltax;
	double	deltay;
	double	pixels;

	startx = map.size_x / 2;
	starty = map.size_y / 2;
	deltax = endx - startx;
	deltay = endy - starty;
	pixels = 100;
	deltax /= pixels;
	deltay /= pixels;
	while (pixels-- > 0)
	{
		my_mlx_pixel_put(&map, startx, starty, color);
		startx += deltax;
		starty += deltay;
	}
}

void	draw_round_minimap_background(t_interface r_minimap)
{
	int	y;
	int	x;
	int	rad;
	int	res;

	y = -1;
	rad = 110;
	while (++y < r_minimap.size_y)
	{
		x = -1;
		while (++x < r_minimap.size_x)
		{
			res = sqrt((y - rad) * (y - rad) + (x - rad) * (x - rad));
			if (rad >= res)
				my_mlx_pixel_put(&r_minimap, x,  y, 0x553B444B);
			else
				my_mlx_pixel_put(&r_minimap, x,  y, 0xFF000000);
		}
	}
}

void	draw_relative_round_minimap(t_map *map)
{

}

void	draw_player_in_round_minimap(t_map *map)
{
	int		x;
	int		y;
	int		end;
	int		save_y;

	save_y = map->round_minmap.size_x / 2 - 2;
	end = save_y + 4;
	x = save_y;
	while (x < end)
	{
		y = save_y;
		while (y < end)
		{
			my_mlx_pixel_put(&map->round_minmap, x, y, 0x0058C878);
			y++;
		}
		x++;
	}
}

void	draw_fov_in_round_minimap(t_map *map)
{
	double	line_end_x;
	double	line_end_y;
	double	dir_start;
	double	dir_end;
	double	dir_center;

	dir_end = map->pers.dir + FOV2;
	if (dir_end > PI * 2)
		dir_end -= PI * 2;
	dir_start = dir_end - 2 * FOV2;
	dir_center = dir_end - 30 * GR;
	while (dir_start <= dir_end)
	{
		line_end_x = 110 + ray_cast(map, dir_start, 0);
		line_end_y = 110 + ray_cast(map, dir_start, 1);
		if (fabs(dir_start - dir_center) < GR / 2)
			draw_line_r(map->round_minmap, line_end_x, line_end_y, WALL);
		else
			draw_line_r(map->round_minmap, line_end_x, line_end_y, FOV);
		dir_start += GR / 2;
	}
}

void	draw_round_minimap(t_map *map)
{
	map->round_minmap.size_x = map->mlx.win_size_y / 4 + 20;
	map->round_minmap.size_y = map->mlx.win_size_y / 4 + 20;
	map->round_minmap.img = mlx_new_image(map->mlx.mlx,
									 map->round_minmap.size_x, map->round_minmap.size_y);
	map->round_minmap.addr = mlx_get_data_addr(map->round_minmap.img,
										  &map->round_minmap.bits_per_pixel, &map->round_minmap.line_length,
										  &map->round_minmap.endian);
	draw_round_minimap_background(map->round_minmap);
	draw_relative_round_minimap(map);
	draw_player_in_round_minimap(map);
	draw_fov_in_round_minimap(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->round_minmap.img, 32, 25);
//	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->round_minmap.img, 15, map->mlx.win_size_y - map->round_minmap.size_y - 15 - map->mlx.win_size_y / 20);
}

