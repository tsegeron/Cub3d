/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

void	draw_health_bar(t_map *map)
{
	int	hp;
	int	color;
	int	pix_x;
	int	pix_y;
	int	pix_end_x;
	int	pix_end_y;

	map->hpbar.size_x = map->mlx.win_size_x / 5;
	map->hpbar.size_y = map->mlx.win_size_y / 12;
	map->hpbar.posx = 15;
	map->hpbar.posy = map->mlx.win_size_y - map->hpbar.size_y - 1;
//	pix_x = map->hpbar.posx;
	pix_end_x = map->mlx.win_size_x / 5;
//	pix_y = map->hpbar.posy + map->mlx.win_size_y / 12;
//	pix_y = 0;
	map->hpbar.img = mlx_new_image(map->mlx.mlx,
								   map->hpbar.size_x, map->hpbar.size_y);
	map->hpbar.addr = mlx_get_data_addr(map->hpbar.img,
										&map->hpbar.bits_per_pixel, &map->hpbar.line_length,
										&map->hpbar.endian);
	hp = map->pers.health;
	if (hp > 6)
		color = 0x00FF0000;
	else if (hp > 3)
		color = 0xCCFFD700;
	else
		color = 0xCCFF033E;


//	pix_end_y = 4;
	pix_x = -1;
	pix_end_y = map->hpbar.size_y - 15;
//	printf("%d %d %d %d\n", pix_x, pix_y, pix_end_x, pix_end_y);
	while (++pix_x < pix_end_x)
	{
		if ((pix_x >= 0 && pix_x < 4) || (pix_x >= pix_end_x - 4 && pix_x < pix_end_x))
			pix_end_y = map->hpbar.size_y - 15;
		else
			pix_end_y = 4;
		pix_y = -1;
		while (++pix_y < pix_end_y)
			my_mlx_pixel_put(&map->hpbar, pix_x, pix_y, color);
		pix_y = map->hpbar.size_y - 15;
		pix_end_y = map->hpbar.size_y - 10;
		while (++pix_y < pix_end_y)
			my_mlx_pixel_put(&map->hpbar, pix_x, pix_y, color);
	}

//	while (hp--)
//	{
//
//	}

	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->hpbar.img, map->hpbar.posx, map->hpbar.posy);
//	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->hpbar.img, 0, 0);
}

void	draw_interface(t_map *map)
{
	draw_health_bar(map);



}
