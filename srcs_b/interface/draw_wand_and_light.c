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

typedef struct s_local_vars
{
	double	rad;
	int		clr;
	int		clr_save;
	int		x;
	int		y;
}	t_local;

static void	put_imgs_to_window(t_map *map)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->vars.wand.img,
		map->back.size_x / 3 + map->vars.wand.size_x,
		map->back.size_y - map->vars.wand.size_y);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->light.img,
		map->back.size_x / 3 + map->vars.wand.size_x - 25,
		map->back.size_y / 2);
}

void	draw_wand_and_light(t_map *map)
{
	static double	div = 6.66;
	static double	step = 0.04;
	t_local			q;

	q.clr_save = 0x00c0d4f3;
	q.y = -1;
	while (++q.y < 200)
	{
		q.x = -1;
		while (++q.x < 200)
		{
			q.rad = sqrt((q.y - 100) * (q.y - 100) + (q.x - 100) * (q.x - 100));
			q.clr = 0xFF000000;
			if (q.rad <= 100)
				q.clr = add_transparency(q.clr_save, q.rad / div);
			my_mlx_pixel_put(&map->light, q.x, q.y, q.clr);
		}
	}
	div += step;
	if (div > 7.2 || div < 6.69)
		step = -step;
	put_imgs_to_window(map);
}

//	clr_save = 0x009DE3A2;	//	cyan
