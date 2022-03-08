/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wand_and_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

void	draw_wand_and_light(t_map *map)
{
	double	rad;
	int		clr;
	int		clr_save;
	int 	x;
	int		y;

	clr_save = 0x00c0d4f3;	//	main
//	clr_save = 0x009DE3A2;	//	cyan
	y = -1;
	while (++y < 200)
	{
		x = -1;
		while (++x < 200)
		{
			rad = sqrt((y - 100.) * (y - 100.) + (x - 100.) * (x - 100.));
			clr = 0xFF000000;
			if (rad <= 100)
				clr = add_transparency(clr_save, rad / 6.7);
			my_mlx_pixel_put(&map->light, x, y, clr);
		}
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->vars.wand.img,
							map->back.size_x / 3 + map->vars.wand.size_x,
							map->back.size_y - map->vars.wand.size_y);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->light.img,
							map->back.size_x / 3 + map->vars.wand.size_x - 25,
							map->back.size_y / 2);
}
