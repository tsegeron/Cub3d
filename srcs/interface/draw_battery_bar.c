#include "../../hdrs/cub3d.h"

static void	battery_bar_init(t_map *map, int *charge, int *color)
{
	map->battery_bar.size_x = map->mlx.win_size_x / 5;
	map->battery_bar.size_y = map->mlx.win_size_y / 25 - 15;
	map->battery_bar.posx = 15;
	map->battery_bar.posy = map->mlx.win_size_y - map->battery_bar.size_y - 10;
	map->battery_bar.img = mlx_new_image(map->mlx.mlx,
			map->battery_bar.size_x, map->battery_bar.size_y);
	map->battery_bar.addr = mlx_get_data_addr(map->battery_bar.img,
			&map->battery_bar.bits_per_pixel, &map->battery_bar.line_length,
			&map->battery_bar.endian);
	*charge = map->pers.charge;
	if (*charge > 6)
		*color = BATTERY;
//		*color = 0x008DB600;
	else if (*charge > 3)
		*color = 0x00FFD700;
	else
		*color = 0x00CC0000;
}

/*
 *	draws a rectangle of health bar
 */
static void	draw_battery_charge_frame(t_map *map)
{
	int	pix_x;
	int	pix_y;
	int	pix_end_x;
	int	pix_end_y;

	pix_x = -1;
	pix_end_x = map->mlx.win_size_x / 5;
	pix_end_y = map->battery_bar.size_y;
	while (++pix_x < pix_end_x)
	{
		pix_y = 0;
		while (pix_y < 3)
			my_mlx_pixel_put(&map->battery_bar, pix_x, pix_y++, BATTERY);
		if (!((pix_x >= 0 && pix_x < 4)
				|| (pix_x >= pix_end_x - 4 && pix_x < pix_end_x)))
			pix_y = map->battery_bar.size_y - 3;
		while (pix_y < pix_end_y)
			my_mlx_pixel_put(&map->battery_bar, pix_x, pix_y++, BATTERY);
	}
}

/*
 *	draws battery charges
 */
static void	draw_battery_charges(t_map *map, int *charge, int *color)
{
	int	pix_x;
	int	pix_y;
	int	pix_end_x;
	int	pix_end_y;
	int	pix_x_step;

	pix_x = 3;
	pix_x_step = map->mlx.win_size_x / 44 - pix_x;
	pix_end_y = map->battery_bar.size_y - 3;
	while ((*charge)--)
	{
		pix_end_x = pix_x + pix_x_step;
		while (++pix_x < pix_end_x)
		{
			pix_y = 3;
			while (pix_y < pix_end_y)
				my_mlx_pixel_put(&map->battery_bar, pix_x, pix_y++, *color);
		}
		pix_x -= 1;
	}
}

/*
 *	draws battery bar
 */
void	draw_battery_bar(t_map *map)
{
	int	charge;
	int	color;

	battery_bar_init(map, &charge, &color);
	draw_battery_charge_frame(map);
	draw_battery_charges(map, &charge, &color);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->battery_bar.img,
		map->battery_bar.posx, map->battery_bar.posy);
}
