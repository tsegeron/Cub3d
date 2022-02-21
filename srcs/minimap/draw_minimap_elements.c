/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:51:02 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/16 12:11:08 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

typedef struct s_local
{
	int		pix_map_x;
	int		pix_map_y;
	int		pix_map_end_x;
	int		pix_map_end_y;
	int		save_x;
	int		pix_x;
	int		pix_y;
	int		res;
	int		rad;
}	t_local;

static void	params_init(t_map *map, t_local *q)
{
	q->rad = 110;
	q->save_x = 20 * map->pers.posx - 110;
	q->pix_map_y = 20 * map->pers.posy - 110;
	q->pix_map_end_x = q->save_x + 221;
	q->pix_map_end_y = q->pix_map_y + 221;
	if (q->pix_map_end_x > map->map_width * 20 - 1)
		q->pix_map_end_x = map->map_width * 20 - 1;
	if (q->pix_map_end_y > map->map_height * 20 - 1)
		q->pix_map_end_y = map->map_height * 20 - 1;
	q->pix_y = -1;
}

static int	skip_non_range_pixs(t_interface *minimap, t_local *q)
{
	if (q->pix_map_x < 0)
	{
		q->pix_map_x += 3;
		q->pix_x += 3;
		return (1);
	}
	if (q->pix_map_y < 0)
	{
		q->pix_map_y += 3;
		q->pix_y += 3;
		return (2);
	}
	if (!(q->pix_map_x % 20))
		return (1);
	if (q->rad < sqrt((q->pix_y - q->rad) * (q->pix_y - q->rad)
			+ (q->pix_x - q->rad) * (q->pix_x - q->rad)))
	{
		my_mlx_pixel_put(minimap, q->pix_x, q->pix_y, EMPTY);
		return (1);
	}
	return (0);
}

static int	draw_charge_square_in_minimap(int x, int y)
{
	int	modx;
	int	mody;

	modx = x % 20;
	mody = y % 20;
	if (mody >= 8 && mody < 12)
	{
		if (modx > 2 && modx < 18)
			return (1);
	}
	else if (mody >= 2 && mody < 18)
	{
		if (modx > 8 && modx < 12)
			return (1);
	}
	return (0);
}

static void	paint_pixels(t_map *map, t_local *q, int x, int y)
{
	if (map->map[y][x] == '1')
		my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, WALL);
	else if (map->map[y][x] == ' ')
		my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, EMPTY);
	else if (map->map[y][x] == 'C')
		my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, CDOOR);
	else if (map->map[y][x] == 'O')
		my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, ODOOR);
	else if (map->map[y][x] == 'B')
	{
		if (draw_charge_square_in_minimap(q->pix_map_x, q->pix_map_y))
			my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, BATTERY);
		else
			my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, VOID);
	}
	else if (map->map[y][x] == 'H')
	{
		if (draw_charge_square_in_minimap(q->pix_map_x, q->pix_map_y))
			my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, CURE);
		else
			my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, VOID);
	}
	else
		my_mlx_pixel_put(&map->round_minmap, q->pix_x, q->pix_y, VOID);
}

void	draw_minimap_elements(t_map *map)
{
	t_local	q;
	int		skip_status;

	params_init(map, &q);
	while (++q.pix_y < MAPH + 1 && ++q.pix_map_y < q.pix_map_end_y)
	{
		if (!(q.pix_map_y % 20))
			continue ;
		q.pix_x = -1;
		q.pix_map_x = q.save_x;
		while (++q.pix_x < MAPW + 1 && ++q.pix_map_x < q.pix_map_end_x)
		{
			skip_status = skip_non_range_pixs(&map->round_minmap, &q);
			if (skip_status == 1)
				continue ;
			else if (skip_status == 2)
				break ;
			paint_pixels(map, &q, q.pix_map_x / 20, q.pix_map_y / 20);
		}
	}
}
