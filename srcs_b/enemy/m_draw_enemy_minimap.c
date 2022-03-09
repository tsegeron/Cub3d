/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_draw_enemy_minimap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:15:11 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/18 00:30:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d_bonus.h"

void	m_draw_all_enemy(t_map *map, int x, int y)
{
	t_vilian	*step;
	int			l;
	int			k;

	step = map->vilian;
	while (step)
	{
		if (step->health)
		{
			l = (int)((step->y - (map->pers.posy - 5.5)) * 20);
			k = (int)((step->x - (map->pers.posx - 5.5)) * 20);
			if (y > l - 4 && y < l + 4 && x > k - 4 && x < k + 4)
				my_mlx_pixel_put(&map->round_minmap, x, y, AIM);
			if ((y >= l - 5 && y <= l - 4 && x >= k - 5 && x <= k + 5) || \
			(y >= l + 4 && y <= l + 5 && x >= k - 5 && x <= k + 5) || \
			(x >= k - 5 && x <= k - 4 && y >= l - 5 && y <= l + 5) || \
			(x >= k + 4 && x <= k + 5 && y >= l - 5 && y <= l + 5))
				my_mlx_pixel_put(&map->round_minmap, x, y, 0x000000);
		}
		step = step->next;
	}
}

void	m_draw_enemy_minimap(t_map *map)
{
	int		x;
	int		y;
	double	res;

	y = -1;
	while (++y < 11 * 20)
	{
		x = -1;
		while (++x < 11 * 20)
		{
			res = sqrt(powf(y - 5.5 * 20, 2) + powf(x - 5.5 * 20, 2));
			if (res <= 5.5 * 20)
				m_draw_all_enemy(map, x, y);
		}
	}
}
